'''
Created on Jun 11, 2015

@author: rsingh
'''
from flask.views import MethodView
from flask import request, jsonify
import mysql.connector
from datetime import datetime
import json


class PostsAPI(MethodView):
    
    def con2db(self):
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


    def get(self):
        cnx = self.con2db()
        cur = cnx.cursor()
        skip = 0
        stmt_select = "select * from posts;"
        cur.execute(stmt_select)
        x=cur.fetchall()
        
        allPosts = []
        for row in reversed(x):
            data = {
                    "uid":row[0],
                    "pid":row[1],
                    "subject":row[2],
                    "post_content":row[3],
                    "date":datetime.fromtimestamp(row[4]).strftime("%Y-%m-%d %H:%M:%S"),
                    }
            allPosts.append(data)
             
        return json.dumps(allPosts)
        #return jsonify(results = allPosts)