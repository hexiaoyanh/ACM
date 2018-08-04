from flask import Flask

import os


app = Flask(__name__)

@app.route("/")
def index():
    html="hello"
    return html.format(name=os.getenv("flask"))

if __name__ == '__main':
    app.run()
