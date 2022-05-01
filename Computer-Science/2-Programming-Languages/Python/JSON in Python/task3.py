"""
Task 3

Modify the example.json file to store the student addresses in a single string 
instead of a list of address lines.

The original file contents are stored in a copy named exampleCopy.json
"""
import json

with open("example.json", "r") as file:
    jsonData = json.load(file)

for name in jsonData:
    address = jsonData[name]["address"]
    addressString = ""
    for line in address:
        addressString += line + " "
    
    jsonData[name]["address"] = addressString[:-1] 
    # -1 because we don't want the last whitespace

with open("example.json", "w") as file:
    json.dump(jsonData, file, indent=4)
print("Process Complete!")
