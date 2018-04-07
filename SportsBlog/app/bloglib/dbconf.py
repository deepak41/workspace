import mysql.connector

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