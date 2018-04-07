'''
Created on Dec 2, 2015

@author: Deepak
'''


from flask import Flask, render_template, request, session
import mysql.connector
from werkzeug.utils import redirect
import time
from datetime import datetime
from werkzeug.exceptions import abort

app = Flask(__name__)

app.secret_key = "development key"

# function for connecting to the mysql db
def db_connect():
    config = {
        "host": "localhost",
        "port": 3306,
        "database": "barcablog",
        "user": "root",
        "password": "wine23",
        "charset": "utf8",
        "use_unicode": True,
        "get_warnings": True,
    }
    cnx = mysql.connector.connect(**config)
    return cnx

@app.route("/")
def home():
    # this returns the value of the key 'page' specified in the query string.
    # when the URL "/" is entered, the key 'page' does not exist so 
    # default value is returned which in this case is 1.
    page = request.args.get("page", 1)
    
    # this try-except block verifies that value of 'page' is a whole number
    try:
        page = int(page)
    except:
        abort(404)
    
    # this makes a connection with the db
    cnx = db_connect()
    cur = cnx.cursor()
        
    stmt_count = "select count(*) from posts;"
    
    # for executing sql query stmt_count
    cur.execute(stmt_count)
    r = cur.fetchone()
    
    # totalRows contains the no. of records in the table "posts"
    totalRows = r[0]
    
    # this stores the offset value for stmt_select
    skip = totalRows - 5*page
    
    # this stmt is same as "select * from posts limit 5 offset %s;"   
    stmt_select = "select * from posts limit %s, 5;"
    values = [skip]
    
    # for executing sql query stmt_select
    cur.execute(stmt_select, values)
    
    # records is a list & its items are tuples and each tuple contains a record or row 
    records = cur.fetchall()
    
    output = []
    
    # the values in each tuple are stored in a dictionary and added in the list 'output'
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
    # this if block executes if the form in signup.html is submitted
    if request.method == "POST":
        # variables for storing the submitted form data from signup.html
        fname = request.form["firstname"]
        lname = request.form["lastname"]
        email = request.form["email"]
        pwd = request.form["password"]
        
        # this makes a connection with db
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_insert = "INSERT INTO users (firstname, lastname, email, pwdhash) VALUES (%s, %s, %s, %s);"
        names = [fname, lname, email, pwd]
        
        # for executing sql query
        cur.execute(stmt_insert, names)
        cnx.commit()
        
        return render_template("success.html", success = True, process = "signup")
    
    # this elif block executes if the URL /signup is entered in the browser
    elif request.method == "GET":
        return render_template("signup.html")
    
@app.route("/login", methods = ["GET", "POST"])
def login():
    # this if block executes if session["usid"] exists i.e. any user is logged in
    if session.get("usid"):
        return redirect("/user_home")
    
    # this if block executes if the form in login.html is submitted
    if request.method == "POST":
        # variables for storing the submitted form data from login.html
        email = request.form.get("email")
        password = request.form["password"]
        
        # this makes a connection with mysql db
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_select = "select uid, firstname, pwdhash from users where email = %s;"
        names = [email]
        
        # for executing sql query
        cur.execute(stmt_select, names)
        row = cur.fetchone()
     
        # this if block executes if row is not empty i.e. the email entered exists in the db
        if row:
            # the items in the tuple "row" are stored in the dictionary "data"
            data = {
                "uid":row[0],
                "firstname":row[1],
                "pwdhash":row[2],
            }
            
            # this if block executes if pwd entered in the form is correct
            if password == data["pwdhash"]:
                session["usid"] = data["uid"]
                return redirect("/user_home")
            else:
                return render_template("login.html", pwdwrong = True)
        else:
            return render_template("login.html", emailwrong = True) 
        
    # this elif block executes if the URL /login is entered in the browser   
    elif request.method == "GET":
        return render_template("login.html")
    
@app.route("/logout")
def logout():
    del session["usid"]
    return redirect("/login")
    
@app.route("/user_home")
def user_home():
    # this if block executes if session["usid"] does not exist i.e. no user is logged in
    # if session["usid"] does not exist then session.get("usid") = None
    if not session.get("usid"):
        return redirect("/login")
    
    # this makes a connection with the db
    cnx = db_connect()
    cur = cnx.cursor()
    
    stmt_select = "select uid, firstname, pwdhash from users where uid = %s;"
    values = [session.get("usid")]
    
    # for executing sql query
    cur.execute(stmt_select, values)
    row = cur.fetchone()

    # the items in the tuple "row" are stored in the dictionary "data"
    data = {
        "uid":row[0],
        "firstname":row[1],
        "pwdhash":row[2],
    }
    
    return render_template("user_home.html", s = session["usid"], user = data)

@app.route("/write_post", methods = ["GET", "POST"])
def write_post():
    # this if block executes if the form in write_post.html is submitted
    if request.method == "POST":
        # variables for storing the submitted form data from write_post.html
        s = request.form["subject"]
        p = request.form["post_content"]
        
        # this makes a connection with the db
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_insert = "INSERT INTO posts (uid, subject, post_content, date) VALUES (%s, %s, %s, %s)"
        names = [session["usid"], s, p, int(time.time())]
        
        # for executing sql query
        cur.execute(stmt_insert, names)
        cnx.commit()
        
        return render_template("success.html", success = True, process = "write_post")
    
    # this elif block executes if the URL /write_post is entered in the browser 
    elif request.method == "GET":
        return render_template("write_post.html")
    
@app.route("/post/<postid>")
def post(postid):
    # this try-except block verifies that postid is a whole number
    try:
        postid = int(postid)
    except:
        abort(404)
    
    # this makes a connection with the db    
    cnx = db_connect()
    cur = cnx.cursor()
    
    stmt_select = "select * from posts where pid = %s;"
    values = [postid]
    
    # for executing sql query
    cur.execute(stmt_select, values)
    row = cur.fetchone()
    
    # the items in the tuple "row" are stored in the dictionary "data"
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
    # this if block executes if the form in edit_post.html is submitted
    if request.method == "POST":
        # variables for storing the submitted form data from edit_post.html
        s = request.form["subject"]
        p = request.form["post_content"]
        
        # this makes a connection with the db
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_update = "UPDATE posts SET subject = %s, post_content = %s WHERE pid = %s"
        names = [s, p, postid]
        
        # for executing sql query
        cur.execute(stmt_update, names)
        cnx.commit() 
        
        return render_template("success.html", success = True, process = "edit_post")
    
    # this elif block executes if the URL /edit_post/{postid} is entered in the browser    
    elif request.method == "GET":
        # this makes a connection with the db
        cnx = db_connect()
        cur = cnx.cursor()
        
        stmt_select = "select * from posts where pid = %s;"
        values = [postid]
        
        # for executing sql query
        cur.execute(stmt_select, values)
        row = cur.fetchone()
        
        # the items in the tuple "row" are stored in the dictionary "data"
        data = {
            "uid":row[0],
            "pid":row[1],
            "subject":row[2],
            "post_content":row[3],
            "date":datetime.fromtimestamp(row[4]),
        }
        
        # this if block executes if user logged in is the author of the post to be edited
        if(data["uid"] == session.get("usid")):
            return render_template("edit_post.html", post = data)
        else:
            abort(403)

if __name__ == "__main__":
    app.run(debug=True)