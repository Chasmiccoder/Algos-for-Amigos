## Learnings from Pico CTF

---

### Linux Basics

Storing output in a file

	command > out.txt  

Grep to get line with a particular string str

	grep str filename

Open the cwd in files

	nautilus .

Print properties of file

	file filename

Rename a file

	mv oldName newName

Eye of gnome (to display image)

	eog filename



### Web Exploitation

Types of request - GET, POST, HEAD

Making a HEAD request

	curl -I <url>

### Cryptography

RSA in a nutshell

```
P, Q are large primes
N = P * Q
phi = (P-1) * (Q-1)

Choose e
	such that gcd(e, phi) = 1

Choose d
	such that (e * d) mod phi = 1

To encrypt
	c = m^e mod N

To decrypt
	m = c^d mod N
```

hashlib usage to to get sha256 hash of a string str
```py
	hashlib.sha256(str).hexdigest()
```

```py
# Finding d directly,
from Crypto.Util.number import inverse
d = inverse(e, phi)
```

### Binary Files
	strings filename  

Looks for printable characters in a binary file

	chmod 777 filename

Change file permission

	./filename -h

Run the file with the -h flag


### Binary Exploitation
Need to find some sort of exploit in the code.

For C code that involves stack memory, try inputting many '%x's.
'%x' Reads one byte from the stack memory.

Note: use 

	wget "link-to-download"

to download files straight into the cwd

Copy python script output to clipboard

	python script.py | xclip -sel copy

### Forensics

Terminal based hex editor - xxd
To print the image header

	xxd image | head

Get it in terms of 2 hex bytes
	xxd -g 1 tunn3l_v1s10n.bmp | head

### Network Communication
netcat
For reading and writing to network communications using TCP, or UDP.
Usage:

	nc mercury.picoctf.net 59616


### Reverse Engineering
Given a way of encoding a string, find the script that decodes the string.
For example,
Encode(flag) with the following code
```py
''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])
```
To get - 灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弰摤捤㤷慽

Script that decodes this message -
```py
flag = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弰摤捤㤷慽"
ans = ''
for i in range(len(flag)):
	ans += chr( ord(flag[i]) >> 8 )
	ans += chr((ord(flag[i]))-((ord(flag[i])>>8)<<8))
```


### Resources to checkout

1. https://www.youtube.com/watch?v=uIkxsBgkpj8



