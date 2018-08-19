import os
import random
from flask import Flask
from flask import json
from flask import Response

import db

app = Flask(__name__)
db.init_db()

# If this were an actual project, I not implement any business logic here as I do now

# We use user_name as key to the current game session if it exists
# Only one game can exist at a time
@app.route('/target/<user_name>', methods = ['GET'])
def target(user_name):
    target = db.get_game(user_name)
    if(target is None):
        target = random.randint(1, 101)
        db.create_game(user_name, target)

    data = {
        'target': target
    }

    js = json.dumps(data)
    return Response(js, status=200, mimetype='application/json')

"""
Expected input:
{
    guess_value : int 
}
"""
@app.route('/guess/<user_name>')
def guess(): 
    target = db.get_game(user_name)
    if(target is None): 
        return abort(400) # no active game

    answer = False
    try:
        answer = exec_question(target, json.dumps(request.json))
    except Exception as e:
        print(e)
        return abort(400) # bad input

    # Update DB
    db.increment_guess(user_name)
    if answer == True:
        db.complete_game(user_name)

    js = json.dumps({'result': answer})
    return Response(js, status=200, mimetype='application/json')

def exec_guess(target, guess_dict):
    return target == guess_dict['guess_value']

"""
Expected input:
{
    operation: [even|odd|gt|lt],
    operand: int (optional)
}
"""
@app.route('/question/<user_name>')
def question(name):
    target = db.get_game(user_name)
    if(target is None):
        return abort(400) 

    answer = False
    try:
        answer = exec_question(target, json.dumps(request.json))
    except Exception as e:
        print(e)
        return abort(400)

    # Update DB
    db.increment_question(user_name)

    js = json.dumps({'result': answer})
    return Response(js, status=200, mimetype='application/json')
        
def exec_question(target, question_dict):
    operation = question_dict[operation]
    if operation == 'gt':
        return target > question_dict[operand]
    elif operation == 'lt':
        return target < question_dict[operand]
    elif operation == 'odd':
        return target % 2 == 1
    elif operation == 'even':
        return target % 2 == 0
    else:   
        raise Exception('Invalid guess operation')

if __name__ == '__main__':
    app.run()