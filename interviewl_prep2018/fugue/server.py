import os
import random
from flask import Flask
from flask import json
from flask import Response
from flask import request
from flask import abort

import db

app = Flask(__name__)
db.init_db()

# We use user_name as key to the current game session if it exists
# Only one game can exist at a time
@app.route('/game/<user_name>', methods = ['GET'])
@app.route('/game/<user_name>/', methods = ['GET'])
def game(user_name):
    new_game = False
    if(db.get_game(user_name) is None):
        target = random.randint(1, 101)
        db.create_game(user_name, target)
        new_game = True

    data = {
        'new_game': new_game 
    }

    js = json.dumps(data)
    return Response(js, status=200, mimetype='application/json')

"""
Expected input:
{
    operation: [guess|even|odd|gt|lt],
    operand: int (optional)
}
"""
@app.route('/operation/<user_name>', methods = ['GET'])
@app.route('/operation/<user_name>/', methods = ['GET'])
def operation(user_name):
    target = db.get_game(user_name)
    if(target is None):
        return abort(400) 

    try:
        result = exec_operation_for_user(user_name, target, request.get_json())
    except Exception as e:
        print(e) 
        # Should eventually provide client with some context since exception was probably their fault
        return abort(400)

    js = json.dumps(result)
    return Response(js, status=200, mimetype='application/json')
        
def exec_operation_for_user(user_name, target, operation_dict):
    operation = operation_dict['operation']
    output = {'operation' : operation} # TODO: no need to return operation to client. Client communicates synchronously,
                                       #       so it knows which operation corresponds with which result. Remove.
    if operation == 'guess':
        output['result'] = exec_guess(target, operation_dict['operand'])
        if output['result']:
            db.finish_game(user_name)
        db.increment_guess(user_name)
    else:
        output['result'] = exec_question(target, operation_dict)
        db.increment_question(user_name)
    return output

def exec_guess(target, value):
    guess_result = target == value
    return guess_result 

def exec_question(target, operation_dict):
    operation = operation_dict['operation']
    op_result = False
    if operation == '>':
        op_result = target > operation_dict['operand']
    elif operation == '<':
        op_result = target < operation_dict['operand']
    elif operation == 'odd':
        op_result = target % 2 == 1
    elif operation == 'even':
        op_result = target % 2 == 0
    else:   
        raise Exception('Invalid question or operand: {0}'.format(operation))
    return op_result

if __name__ == '__main__':
    app.run()