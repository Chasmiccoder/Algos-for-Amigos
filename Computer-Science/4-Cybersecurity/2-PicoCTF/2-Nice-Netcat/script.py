text = "112 105 99 111 67 84 70 123 103 48 48 100 95 107 49 116 116 121 33 95 110 49 99 51 95 107 49 116 116 121 33 95 57 98 51 98 55 51 57 50 125 10 "

text = [chr(int(x)) for x in text.split()]

for i in text:
    print(i, end='')


