import hashlib

username_trial = b"MORTON"
# print(hashlib.sha256(username_trial).hexdigest())

pos = [4,5,3,6,2,7,1,8]
m = ""
for i in pos:
    m += hashlib.sha256(username_trial).hexdigest()[i]

print(m)

print("picoCTF{1n_7h3_|<3y_of_" + m + "}")

