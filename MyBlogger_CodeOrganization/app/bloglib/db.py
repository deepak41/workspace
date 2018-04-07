import mysql.connector

class MysqlConnect:
    def __init__(self):
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
        
        self.cnx = mysql.connector.connect(**config)