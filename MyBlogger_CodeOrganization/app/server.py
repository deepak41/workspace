from flask import Flask, render_template, request, flash, session
from flask_mail import Message, Mail
import mysql.connector
from flask.wrappers import Response
from werkzeug.utils import redirect
from app.views.user_home import UserHomeView
from app.views.logout import UserLogoutView

app = Flask(__name__)

app.secret_key = 'development key'

def con2db():
    config = {
        'host': 'localhost',
        'port': 3306,
        'database': 'development',
        'user': 'root',
        'password': 'width',
        'charset': 'utf8',
        'use_unicode': True,
        'get_warnings': True,
    }
    
    output = []
    cnx = mysql.connector.connect(**config)
    cur = cnx.cursor()
    return cnx

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/signup',methods=['GET', 'POST'])
def signup():
    if request.method == 'POST':
        cnx=con2db()
        cur = cnx.cursor()
        
        f=request.form['fn']
        l=request.form['ln']
        e=request.form['email']
        p=request.form['pwd']
        stmt_insert = "INSERT INTO users (firstname, lastname, email,pwdhash) VALUES (%s, %s, %s, %s)"
        names = [f,l,e,p]
        cur.execute(stmt_insert, names)
        cnx.commit()
        return render_template('success.html', success=True, process="signup")
        
    elif request.method == 'GET':
        return render_template('signup.html')
    
@app.route('/login', methods=['GET', 'POST'])
def login():
    if session.get("usid"):
        return redirect("/user_home")
    if request.method == 'POST':
        cnx=con2db()
        cur = cnx.cursor()
        
        em=request.form['email']
        p=request.form['pwd']
        
        stmt_select = "select uid, firstname, pwdhash from users where email=%s;"
        names=[em]
        cur.execute(stmt_select,names)
        row=cur.fetchone()
     
        
        if row:
            data = {
                        "uid":row[0],
                        "firstname":row[1],
                        "pwdhash":row[2],
                        }
                               
            if p==data["pwdhash"]:
                session['usid'] = data["uid"]
                return redirect("/user_home")
            else:
                return render_template('login.html', pwdwrong=True)
        else:
            return render_template('login.html', emailwrong=True) 
               
    elif request.method == 'GET':
        return render_template('login.html')
    
app.add_url_rule('/logout', view_func=UserLogoutView.as_view('UserLogoutView'), methods=['GET'])
    
app.add_url_rule('/user_home', view_func=UserHomeView.as_view('UserHomeView'), methods=['GET'])

if __name__ == '__main__':
    app.run(debug=True)