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
@app.route('/game/<user_name>', methods = ['GET'])
def game(user_name):
    new_game = False
    if(db.get_game(user_name)):
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
@app.route('/operation/<user_name>')
def operation(name):
    target = db.get_game(user_name)
    if(target is None):
        return abort(400) 

    answer = False
    try:
        answer = exec_operation(target, json.dumps(request.json))
    except Exception as e:
        print(e) 
        # Should eventually provide client with some context since exception was probably their fault
        return abort(400)

    js = json.dumps({'result': answer})
    return Response(js, status=200, mimetype='application/json')
        
def exec_operation(target, operation_Dict):
    operation = operation_dict['operation']
    output['operation'] = operation
    if operation is 'guess':
        output['result'] = exec_guess(target, operation_dict['operand'])
    else:
        output['result'] = exec_question(target, operation_dict)
    return output

def exec_guess(target, value):
    guess_result = target == value
    db.increment_guess()
    return guess_result 

def exec_question(target, operation_dict):
    operation = operation_dict[operation]
    op_result = False
    if operation == '>':
        op_result = target > operation_dict[operand]
    elif operation == '<':
        op_result = target < operation_dict[operand]
    elif operation == 'odd':
        op_result = target % 2 == 1
    elif operation == 'even':
        op_result = target % 2 == 0
    else:   
        raise Exception('Invalid question or operand: {0}'.format(operation))
    db.increment_question()
    return op_result

if __name__ == '__main__':
    app.run()