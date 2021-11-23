"""
Task 1

Parse the above example file after deserializing it with the json.load( ) function 
and count the number of lines needed to store the addresses of the students. 
Store these values in a list along with the person’s name, and print the list.
"""
import json

with open("example.json","r") as file:
    jsonData = json.load(file)

result = []

for name in jsonData:
    data = [name, len(jsonData[name]["address"])]
    result.append( data )

print("Person vs Number of Address Lines:")
for name, lines in result:
    print( name + " " + str(lines) )
