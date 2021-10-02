"""
Problem:
Given n and e, crack c

c = 10400286653072418349777706076384847966640064725838262071
n = 23519325203263800569051788832344215043304346715918641803
e = 71

"""
c = 10400286653072418349777706076384847966640064725838262071 # ciphertext
n = 23519325203263800569051788832344215043304346715918641803
e = 71

# paste n in factordb.com get p value and q value (left and right ones until status becomes P)
p = 4655885807254867892895911581
q = 5051525354555657585960616263

phi = (p-1) * (q-1)

from Crypto.Util.number import inverse

d = inverse(e, phi)

m = pow(c,d,n) # do (c ** d) mod n

message = hex(m)
print(message) # 0x6473637b7430305f6d7563685f6d3474685f383839387d

# Now convert that hex string to ascii
# dsc{t00_much_m4th_8898}
