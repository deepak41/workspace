from flask.globals import session
from app.bloglib.db import MysqlConnect
from werkzeug.utils import redirect

def isLoggedin():
    if not session.get("usid"):
        return None
    mySqlconnect=MysqlConnect()
        
    cur = mySqlconnect.cnx.cursor()
    stmt_select = "select uid, firstname, pwdhash from users where uid=%s;"
    values=[session.get("usid")]
    cur.execute(stmt_select,values)
    row=cur.fetchone()
    if not row:
        return None
    
    return row