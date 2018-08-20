import os
import sys
import requests
import json

def make_request(url_params, json_params=None):
    url_tail = reduce((lambda x, y: x + '/' + y + '/'), ulr_params)
    print("url_tail: " + url_tail)
    resp = requests.get('http://localhost:5000/target/' + url_tail, json_params)
    print("CSC: " + str(resp.json()))

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
        data['operand'] = int(words[1]) # We should probably also make words is bigger than 1 and that it is a digit
    return data

print("Welcome to Number Finder, the game where you try to guess a number between 1 and 100!")
print("Enter your name and we'll either create a new game or recover an unfinished one!")
print("(But what about a password? We want to give you the most streamlined user experience possible. 'Passwords' and 'security' are nothing but tacky anachronisms.")
# ^ In case it's not obvious, I don't actually believe this. This is a toy program.
print("Enter your user name: ")
user_name = sys.stdin.readline()

# defining a params dict for the parameters to be sent to the API
# PARAMS = {'address':location}
 
# sending get request and saving the response as response object
print("Acquiring game...")

try:
    result_dict = make_request(["game", user_name])
except Exception as e:
    print("Bad news... Something went wrong when while talking to the server: {0}".format(e))

if(js['new_game'] is True):
    print("Hey, you're starting a new game since you have no incomplete games.")
else:
    print("You about to finish what you started, homie... Found an incomplete game.")

print("\nAnyway... It's time to play! Ask a valid question ('> x', '< x', 'odd', 'even') or simply enter a number to guess!")
while True:
    print('$: ', end='', flush=True)

    input = sys.stdin.readline()
    result = {}
    try:
        op = parse_operation(input)
        result = make_request(["operation", user_name], op)
    except Exception as e:
        print("You done did it now... Gone and made ol' Python upset. ({0}).".format(e))
        continue

    handle_result(result)