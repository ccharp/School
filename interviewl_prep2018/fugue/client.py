import os
import sys
import requests
import functools as ft
import json

def print_prompt():
    print('$ ', end='', flush=True)

def make_request(url_params, json_params=None):
    url_tail = squash_url_params(url_params)
    full_url = 'http://localhost:5000/' + url_tail
    if json_params is not None:
        resp = requests.get(full_url, json=json_params)
    else:
        resp = requests.get(full_url)

    if resp.status_code != 200:
        raise Exception("Server responded with status {}".format(resp.status_code))

    return resp.json()

def squash_url_params(url_params):
    url_params = map((lambda x: x.strip()), url_params)
    return ft.reduce((lambda x, y: x + '/' + y + '/'), url_params)

def parse_operation(txt):
    if txt.strip().isdigit():
        return parse_guess(txt.strip())
    return parse_question(txt)
    
def parse_guess(txt):
    return { 'operation': 'guess'
           , 'operand' : int(txt)}       

def parse_question(txt):
    words = txt.split()
    operation = words[0]
    data = {'operation': operation}
    if(operation != 'odd' and operation != 'even'):
        data['operand'] = int(words[1]) # We should probably also make sure words is bigger than 1 and that it is a digit
    return data

### BEGIN MAIN ### 

print("Welcome to Number Finder, the game where you try to guess a number between 1 and 100!\n")
print("Enter your name and we'll either create a new game or recover an unfinished one!")

print("(But why not password? Feature. We want to give you the most streamlined user experience possible. 'Passwords' and 'security' are nothing but tacky anachronisms.)\n")
# ^ In case it's not obvious, I don't actually believe this. This is a toy program.

print_prompt()
user_name = sys.stdin.readline()

print("Sit tight, game incoming...")
try:
    result_dict = make_request(["game", user_name])
except Exception as e:
    print("Bad news... Something went wrong while talking to the server: {}".format(e))
    exit(1)

if(result_dict['new_game'] is True):
    print("Hey, you're starting a new game since you have no incomplete games.")
else:
    print("You about to finish what you started, homie... Found an incomplete game.")

print("\nAnyway... It's time to play! Ask a valid question ('> x', '< x', 'odd', 'even') or simply enter a number to guess!")
while True:
    print_prompt()
    input = sys.stdin.readline()
    result = {}
    try:
        op = parse_operation(input)
        result = make_request(["operation", user_name], op)
        print(result['result'])
        if result['operation'] == 'guess' and result['result']:
            print("OH YAY! You guessed correctly! Restart the program to play again!")
            exit(0)
    except Exception as e:
        print("OMGGGGGGG. Encountered error: ({}).".format(e))