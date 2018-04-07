'''
Created on 29-Jan-2013

@author: roshan
'''

from flask import Flask
from flask.ext.assets import Environment


from flask import render_template

from datetime import timedelta
import json, time

#views
from Routes.IndexAPI import IndexAPI
from Routes.PostsAPI import PostsAPI

app = Flask(__name__, static_folder='static', template_folder='templates')

app.config['PROPAGATE_EXCEPTIONS'] = True #propagates errors to log, now all logs should appear in apache error log
assets = Environment(app)
app.config['JSONIFY_PRETTYPRINT_REGULAR'] = False
app.config['INIT_TIME'] = int(time.time())

app.config['MAX_CONTENT_LENGTH'] = 2 * 1024 * 1024


indexApi = IndexAPI.as_view('index_view')
app.add_url_rule('/', view_func=indexApi, methods=['GET'])
app.add_url_rule('/reports', view_func=indexApi, methods=['GET'])
app.add_url_rule('/posts', view_func=indexApi, methods=['GET'])
app.add_url_rule('/events', view_func=indexApi, methods=['GET'])
app.add_url_rule('/pushnotif', view_func=indexApi, methods=['GET'])
app.add_url_rule('/bulk-events', view_func=indexApi, methods=['GET'])
app.add_url_rule('/dynamic_groups', view_func=indexApi, methods=['GET'])

app.add_url_rule('/api/posts', view_func=PostsAPI.as_view('reports_view'), methods=['GET'])


if __name__ == '__main__':
    app.debug = True
    app.config['ASSETS_DEBUG'] = True
    app.run(host='0.0.0.0', port=4000)
