from flask import request
from flask.globals import session
from werkzeug.utils import redirect
from app.bloglib.loginCheck import isLoggedin
from flask.templating import render_template
from flask.views import MethodView

class UserLogoutView(MethodView):
    def get(self):
        del session["usid"]
        return redirect("/login")