from flask.views import MethodView
from flask import request
from flask.globals import session
from werkzeug.utils import redirect
from app.bloglib.loginCheck import isLoggedin
from flask.templating import render_template

class UserHomeView(MethodView):
    def get(self):
        user=isLoggedin()
        if not user:
            return redirect("/login")
        
        data = {
                "uid":user[0],
                "firstname":user[1],
                "pwdhash":user[2],
                }
        
        return render_template('user_home.html',s=session["usid"],user=data)