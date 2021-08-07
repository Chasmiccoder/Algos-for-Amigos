"""
Reading a Json File
"""

import json

# We can straight away open the json file in 'read' mode, 
# the way we do it with .txt and .csv files
with open("example.json","r") as file:
    jsonData = json.load(file)

print("Type of JSON Object: ", type(jsonData))

# Traversing the json file
for name in jsonData:
    print("Name: ", name)
    print("Phone Number: ", jsonData[name]["number"])
    print("Age: ", jsonData[name]["age"])
    
    print("Address:")
    for line in jsonData[name]["address"]:
        print(line)
    print()
