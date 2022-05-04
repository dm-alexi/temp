from flask import Flask, render_template, request
from solver import Solver

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/api/v0', methods=['GET', 'POST'])
def api():
    if request.method == 'GET':
        return "Computor v1 api"
    else:
        return str(Solver(request.json.get('line')))
