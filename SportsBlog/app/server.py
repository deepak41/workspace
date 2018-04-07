'''
Created on Dec 2, 2015

@author: Deepak
'''
# simple flask app

from flask import Flask, render_template, request, session
import mysql.connector
from werkzeug.utils import redirect
import time
from datetime import datetime
from werkzeug.exceptions import abort
from bloglib.dbconf import db_connect

app = Flask(__name__)

app.secret_key = "development key"

@app.route("/")
def home():
    page = request.args.get("page", 1)
    
    try:
        page = int(page)
    except:
        abort(404)
    
    cnx = db_connect()
    cur = cnx.cursor()
        
    stmt_count = "select count(*) from posts;"
    
    cur.execute(stmt_count)
    r = cur.fetchone()
    
    totalRows = r[0]
    
    skip = totalRows - 5*page
    
    stmt_select = "select * from posts limit %s, 5;"
    values = [skip]
    
    cur.execute(stmt_select, values)
    
    records = cur.fetchall()
    
    output = []
    
    for row in reversed(records):
        data = {
            "uid":row[0],
            "pid":row[1],
            "subject":row[2],
            "post_content":row[3],
            "date":datetime.fromtimestamp(row[4]),
        }
        output.append(data)
        
    nextpage = page+1
    previous = page-1
    if previous < 1:
        previous = 1
        
    return render_template("home.html", persons = output, nextpage = nextpage, previous = previous)

@app.route("/about")
def about():
    return render_template("about.html")

@app.route("/contact")
def contact():
    return render_template("contact.html")

@app.route("/signup", methods = ["GET", "POST"])
def signup():
    if request.method == "POST":
        fname = request.form["firstname"]
        lname = request.form["lastname"]
        email = request.form["email"]
        pwd = request.form["password"]
        
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_insert = "INSERT INTO users (firstname, lastname, email, pwdhash) VALUES (%s, %s, %s, %s);"
        names = [fname, lname, email, pwd]
        
        cur.execute(stmt_insert, names)
        cnx.commit()
        
        return render_template("success.html", success = True, process = "signup")

    elif request.method == "GET":
        return render_template("signup.html")
    
@app.route("/login", methods = ["GET", "POST"])
def login():
    if session.get("usid"):
        return redirect("/user_home")
    
    if request.method == "POST":
        email = request.form.get("email")
        password = request.form["password"]
        
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_select = "select uid, firstname, pwdhash from users where email = %s;"
        names = [email]
        
        cur.execute(stmt_select, names)
        row = cur.fetchone()
     
        if row:
            data = {
                "uid":row[0],
                "firstname":row[1],
                "pwdhash":row[2],
            }
            
            if password == data["pwdhash"]:
                session["usid"] = data["uid"]
                session["firstname"] = data["firstname"]
                return redirect("/user_home")
            else:
                return render_template("login.html", pwdwrong = True)
        else:
            return render_template("login.html", emailwrong = True) 
          
    elif request.method == "GET":
        return render_template("login.html")
    
@app.route("/logout")
def logout():
    del session["usid"]
    return redirect("/login")
    
@app.route("/user_home")
def user_home():
    if not session.get("usid"):
        return redirect("/login")
    
    cnx = db_connect()
    cur = cnx.cursor()
    
    stmt_select = "select uid, firstname, pwdhash from users where uid = %s;"
    values = [session.get("usid")]
    
    cur.execute(stmt_select, values)
    row = cur.fetchone()

    data = {
        "uid":row[0],
        "firstname":row[1],
        "pwdhash":row[2],
    }
    
    return render_template("user_home.html", s = session["usid"], user = data)

@app.route("/write_post", methods = ["GET", "POST"])
def write_post():
    if request.method == "POST":
        s = request.form["subject"]
        p = request.form["post_content"]
        
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_insert = "INSERT INTO posts (uid, subject, post_content, date) VALUES (%s, %s, %s, %s)"
        names = [session["usid"], s, p, int(time.time())]
        
        cur.execute(stmt_insert, names)
        cnx.commit()
        
        return render_template("success.html", success = True, process = "write_post")
    
    elif request.method == "GET":
        return render_template("write_post.html")
    
@app.route("/post/<postid>")
def post(postid):
    try:
        postid = int(postid)
    except:
        abort(404)
      
    cnx = db_connect()
    cur = cnx.cursor()
    
    stmt_select = "select * from posts where pid = %s;"
    values = [postid]
    
    cur.execute(stmt_select, values)
    row = cur.fetchone()
    
    data = {
        "uid":row[0],
        "pid":row[1],
        "subject":row[2],
        "post_content":row[3],
        "date":datetime.fromtimestamp(row[4]),
    }
        
    return render_template("post.html", post=data)
    
@app.route("/edit_post/<postid>", methods = ["GET", "POST"])
def edit_post(postid):
    if request.method == "POST":
        s = request.form["subject"]
        p = request.form["post_content"]
        
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_update = "UPDATE posts SET subject = %s, post_content = %s WHERE pid = %s"
        names = [s, p, postid]
        
        cur.execute(stmt_update, names)
        cnx.commit() 
        
        return render_template("success.html", success = True, process = "edit_post")
       
    elif request.method == "GET":
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_select = "select * from posts where pid = %s;"
        values = [postid]
        
        cur.execute(stmt_select, values)
        row = cur.fetchone()
        
        data = {
            "uid":row[0],
            "pid":row[1],
            "subject":row[2],
            "post_content":row[3],
            "date":datetime.fromtimestamp(row[4]),
        }
        
        if(data["uid"] == session.get("usid")):
            return render_template("edit_post.html", post = data)
        else:
            abort(403)

if __name__ == "__main__":
    app.run(debug=True)