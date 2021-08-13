# examples

## route variables 
```
@app.route('/user/<username>')
def showuser(username):
  return username
```

## accessing request data
``` 
from flask import request
print(request.path)
```
## useable attributes in request data 
1) method
```
request.method # usually get or post
```
2) form data
```
request.form['username'] # accessing username in form
```
3) files
```
request.files['file_name'] # accessing file uploaded
```
4) cookies
```
request.cookies.get('cookie_name') # accessing cookies
```
## store cookies in response 
```
  from flask import make_response
  @app.route("/")
  def index():
    resp = make_response(render_template('index.html'))
    resp.set_cookie('username','yuval')
    return resp
```

## redirects 
```
from flask import redirect,url_for
@app.route("/")
def index():
  return redirect(url_for('login'))
```

## custom error pages
```
@app.errorhandler(404)
def page_not_found(error):
  return render_template('page.html'), 404 # the 404 tells flask which error code to return
```
## sessions 
```
import os
from flask import session,request,url_for
app.secret_key = os.urandom(16)
@app.route("/login")
def login():
  session['username'] = request.from['username']
  return redirect(url_for('index'))
```

## logging 
the log is defined by environ['wsgi.errors'] file  
```
@app.route("/")
def login():
  if request.password != "A123a123":
    app.logger.info('%s failed to login',request.username)
    aboert(401)
```