'''
Created on Dec 2, 2015

@author: Deepak
'''


from flask import Flask, render_template, request, flash, session
from flask_mail import Message, Mail
import mysql.connector
from flask.wrappers import Response
from werkzeug.utils import redirect
import time
from datetime import datetime
from werkzeug.exceptions import abort
from APIs.postAPI import PostsAPI


app = Flask(__name__)

app.secret_key = "development key"

def con2db():
    config = {
        "host": "localhost",
        "port": 3306,
        "database": "blogdb",
        "user": "root",
        "password": "width",
        "charset": "utf8",
        "use_unicode": True,
        "get_warnings": True,
    }
    cnx = mysql.connector.connect(**config)
    return cnx

@app.route("/")
def home():
    cnx = con2db()
    cur = cnx.cursor()
    output = []
    
    page=request.args.get('page', 1)
    
    try:
        page=int(page)
        skip=(page-1)*4
    except:
        abort(404)
       
    stmt_select = "select * from posts limit %s, 4;"
    values=[skip]
    cur.execute(stmt_select,values)
    x=cur.fetchall()
    
    for row in reversed(x):
        data = {
                "uid":row[0],
                "pid":row[1],
                "subject":row[2],
                "post_content":row[3],
                "date":datetime.fromtimestamp(row[4]),
                }
        output.append(data)
        
    next = page+1
    previous = page-1
    if previous<1:
        previous=1
    return render_template("home.html", persons=output, next=next, previous=previous)

@app.route("/about")
def about():
    return render_template("about.html")

@app.route("/contact")
def contact():
    return render_template("contact.html")

@app.route("/signup", methods = ["GET", "POST"])
def signup():
    if request.method == "POST":
        cnx = con2db()
        cur = cnx.cursor()
        
        fname = request.form["firstname"]
        lname = request.form["lastname"]
        email = request.form["email"]
        password = request.form["pwd"]
        
        stmt_insert = "INSERT INTO users (firstname, lastname, email, pwdhash) VALUES (%s, %s, %s, %s);"
        names = [fname, lname, email, password]
        
        cur.execute(stmt_insert, names)
        cnx.commit()
        return render_template("success.html", success = True, process = "signup")
    elif request.method == "GET":
        return render_template("signup.html")
    
@app.route("/login", methods=["GET", "POST"])
def login():
    if session.get("usid"):
        return redirect("/user_home")
    
    if request.method == "POST":
        cnx = con2db()
        cur = cnx.cursor()
        
        email = request.form["email"]
        password = request.form["pwd"]
        
        stmt_select = "select uid, firstname, pwdhash from users where email=%s;"
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
    
    cnx = con2db()
    cur = cnx.cursor()
    
    stmt_select = "select uid, firstname, pwdhash from users where uid=%s;"
    values = [session.get("usid")]
    
    cur.execute(stmt_select, values)
    row = cur.fetchone()
    
    if not row:
        return redirect("/login")
    
    data = {
        "uid":row[0],
        "firstname":row[1],
        "pwdhash":row[2],
    }
    return render_template("user_home.html", s = session["usid"], user = data)

@app.route("/write_post", methods = ["GET", "POST"])
def write_post():
    if request.method == "POST":
        cnx = con2db()
        cur = cnx.cursor()
        
        s = request.form["subject"]
        p = request.form["post_content"]
        
        stmt_insert = "INSERT INTO posts (uid, subject, post_content, date) VALUES (%s, %s, %s, %s)"
        names = [session["usid"], s, p, int(time.time())]
        
        cur.execute(stmt_insert, names)
        cnx.commit()
        return render_template("success.html", success = True, process = "write_post")
    elif request.method == "GET":
        return render_template("write_post.html")
    
@app.route("/post/<postid>")
def post(postid):
    if not postid:
        abort(404)
    
    try:
        postid = int(postid)
    except:
        abort(404)
        
    cnx = con2db()
    cur = cnx.cursor()
    output = []
    
    stmt_select = "select * from posts where pid=%s;"
    values=[postid]
    cur.execute(stmt_select, values)
    row=cur.fetchone()
    
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
        cnx = con2db()
        cur = cnx.cursor()
        
        s = request.form["subject"]
        p = request.form["post_content"]
        
        stmt_update = "UPDATE posts SET subject=%s, post_content=%s WHERE pid=%s"
        names = [s, p, postid]
        
        cur.execute(stmt_update, names)
        cnx.commit() 
        return render_template("success.html", success = True, process = "edit_post")   
    elif request.method == "GET":
        cnx = con2db()
        cur = cnx.cursor()
        output = []
        
        stmt_select = "select * from posts where pid=%s;"
        values=[postid]
        cur.execute(stmt_select, values)
        row=cur.fetchone()
        
        data = {
                    "uid":row[0],
                    "pid":row[1],
                    "subject":row[2],
                    "post_content":row[3],
                    "date":datetime.fromtimestamp(row[4]),
                    }
            
        return render_template("edit_post.html", post=data)
    
app.add_url_rule('/api/posts', view_func=PostsAPI.as_view('posts_view'), methods=['GET'])

@app.route("/index")
def index():
    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True)