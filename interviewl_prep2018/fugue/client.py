import os
import sys
import requests

print("Welcome to Fugue Number Finder!")
print("Enter your name and we'll either create a new game or recover an unfinished one!")
print("(But what about a password? Since we value your time, we've completely removed passwords! Security schmenurity, friend!)")
print("Enter your user name: ")
user_name = sys.stdin.readline()

URL = "http://maps.googleapis.com/maps/api/geocode/json"
 
# location given here
location = "delhi technological university"
 
# defining a params dict for the parameters to be sent to the API
# PARAMS = {'address':location}
 
# sending get request and saving the response as response object
print("Acquiring game...")
r = requests.get('http://127.0.0.1:5000/' + user_name)

print("R.content: " + str(r.content))
