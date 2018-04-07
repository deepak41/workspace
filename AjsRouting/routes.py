from flask import Flask, render_template, request, flash, session
from flask_mail import Message, Mail
import mysql.connector
from flask.wrappers import Response
from werkzeug.utils import redirect
import time
from datetime import datetime
from werkzeug.exceptions import abort

app = Flask(__name__)

app.secret_key = "development key"

@app.route('/')
def home():
    return render_template('index.html')

if __name__ == "__main__":
    app.run(debug=True)