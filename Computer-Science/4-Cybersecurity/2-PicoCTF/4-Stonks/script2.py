
string = "88be350-804b000-80489c3-f7f93d80-ffffffff-1-88bc160-f7fa1110-f7f93dc7-0-88bd180-3b-88be330-88be350-6f636970-7b465443-306c5f49-345f7435-6d5f6c6c-306d5f79-5f79336e-38343136-34356562-fff2007d-f7fceaf8-f7fa1440-df64fb00-1-0-f7e30ce9-f7fa20c0-f7f935c0-f7f93000-fff291c8-f7e2168d-f7f935c0-8048eca-fff291d4-0-f7fb5f09-804b000"

s = ''
for i in string.split('-'):
    if(len(i) == 8):

        ch = bytearray.fromhex(i)

        for b in reversed(ch):
            if b > 32 and b < 128:
                s += chr(b)


print(s)


