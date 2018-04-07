from flask import Flask, render_template, request, flash, session
from forms import ContactForm
from flask_mail import Message, Mail
import mysql.connector
from flask.wrappers import Response
from werkzeug.utils import redirect
  
mail = Mail()

app = Flask(__name__)

app.secret_key = 'development key'

app.config["MAIL_SERVER"] = "smtp.mail.yahoo.com"
app.config["MAIL_PORT"] = 465
app.config["MAIL_USE_SSL"] = True
app.config["MAIL_USERNAME"] = 'dummy665@yahoo.com'
app.config["MAIL_PASSWORD"] = 'matrix67'
 
mail.init_app(app)

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
  
@app.route('/about')
def about():
    return render_template("about.html")

@app.route('/contact', methods=['GET', 'POST'])
def contact():
    form = ContactForm(request.form)
   
    if request.method == 'POST':
        if form.validate() == False:
            flash('All fields are required.')
            return render_template('contact.html', form=form)
        else:
            msg = Message(form.subject.data, sender='dummy665@yahoo.com', recipients=[form.email.data])
            msg.body = """
            From: %s <%s>
              %s
              """ % (form.name.data, form.email.data, form.message.data)
            mail.send(msg)
            return render_template('contact.html', success=True)
    elif request.method == 'GET':
        return render_template('contact.html', form=form)
    
@app.route('/table')
def table():
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

#     names = (("ram", '65',"dfg@hgfg.com","fdyt"), ('Jan', '31',"ytdytfyh@gf.com","fcgfdh"), ('Michel', '32',"dtyhd@gfuj.com","hgfhd"))
#     stmt_insert = "INSERT INTO users (firstname, lastname, email,pwdhash) VALUES (%s, %s, %s, %s)"
#     cur.executemany(stmt_insert, names)
#     cnx.commit()
    
    #select statement example
    stmt_select = "SELECT firstname, lastname, email FROM users ORDER BY uid"
    cur.execute(stmt_select)
    x=cur.fetchall()
    print type(x)
    print x
    
    
    for row in x:
        data = {
                "firstname":row[0],
                "lastname":row[1],
                "email":row[2],
                }
        output.append(data)
    print output
        
    return render_template("table.html",persons=output)

@app.route('/reg',methods=['GET', 'POST'])
def reg():
    if request.method == 'POST':
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
        
        f=request.form['fn']
        l=request.form['ln']
        e=request.form['email']
        p=request.form['pwd']
        stmt_insert = "INSERT INTO users (firstname, lastname, email,pwdhash) VALUES (%s, %s, %s, %s)"
        names = [f,l,e,p]
        cur.execute(stmt_insert, names)
        cnx.commit()
        return render_template('register.html', success=True)
        
    elif request.method == 'GET':
        return render_template('register.html')

@app.route('/update', methods=['GET', 'POST'])
def update():
    if request.method == 'POST':
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
        
        f=request.form['fn']
        l=request.form['ln']
        e=request.form['email']
        stmt_insert = "UPDATE users SET firstname = %s, lastname = %s WHERE email = %s;"
        names = [f,l,e]
        cur.execute(stmt_insert, names)
        cnx.commit()
        return render_template('update_info.html', success=True)
        
    elif request.method == 'GET':
        return render_template('update_info.html')
    
@app.route('/set_cookie')
def cookie_insertion():
    response = Response("lala")  
    print session
    session['name'] = 'roshan'
    return response
    
@app.route('/login', methods=['GET', 'POST'])
def login():
    if session.get("usid"):
        return redirect("/user_home")
    if request.method == 'POST':
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
    
@app.route('/logout')
def logout():
    del session["usid"]
    return redirect("/login")

@app.route("/user_home")
def user_home():
    if not session.get("usid"):
        return redirect("/login")
    cnx=con2db()
    cur = cnx.cursor()
    stmt_select = "select uid, firstname, pwdhash from users where uid=%s;"
    values=[session.get("usid")]
    cur.execute(stmt_select,values)
    row=cur.fetchone()
    if not row:
        return redirect("/login")
    
    data = {
                        "uid":row[0],
                        "firstname":row[1],
                        "pwdhash":row[2],
                        }
    
    return render_template('user_home.html',s=session["usid"],user=data)
  
if __name__ == '__main__':
    app.run(debug=True)