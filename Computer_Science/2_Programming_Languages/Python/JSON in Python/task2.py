"""
Task 2

Open example.json with the json.loads( ) function and using it, create a new json file 
that stores only the mappings between the students’ names and their phone numbers.
"""
import json

with open("example.json", "r") as file:
    fileData  = file.read()
    jsonData = json.loads(fileData)

phoneRecord = {}

for name in jsonData:
    phoneRecord[name] = jsonData[name]["number"]

with open("output.json", "w") as outputFile:
    json.dump(phoneRecord, outputFile, indent=4)
print("Process Complete!")

