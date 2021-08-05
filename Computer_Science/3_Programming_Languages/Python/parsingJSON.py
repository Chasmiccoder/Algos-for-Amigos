import json

f = open("test.json")

json_data = json.load(f)

print(json_data)
print("Type: ", type(json_data))


