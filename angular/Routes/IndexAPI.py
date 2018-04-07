'''
Created on Jun 11, 2015

@author: rsingh
'''

from flask.views import MethodView
from flask import current_app
from flask.templating import render_template
from werkzeug import redirect

class IndexAPI(MethodView):

    def get(self):
        

        appSettings = {'ver': current_app.config['INIT_TIME']}
        userSettings = {}
        return render_template('index.html', appSettings=appSettings, userSettings = userSettings)
