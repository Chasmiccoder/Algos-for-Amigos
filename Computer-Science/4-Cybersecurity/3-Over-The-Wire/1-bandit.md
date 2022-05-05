## OverTheWire - Bandit

Problems -
https://overthewire.org/wargames/bandit/

Answer refers to the password used to log into the next level

### Level 0

    ssh bandit.labs.overthewire.org -p 2220 -l bandit0
    ls
    cat readme

Answer -  
boJ9jbbUNNfktd78OOpsqOltutMc3MY1

### Level 1
Reading a file with the name "-"

    cat ./-

Answer -  
CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9

### Level 2

    cat "./spaces in this filename"

Answer -  
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK

### Level 3
    
    cd inhere
    ls
    ls -la
    cat .hidden

Answer -  
pIwrPrtPN36QITSp3EQaw936yaFoFgAB

### Level 4

    ls
    cat ./-file07

Answer -  
koReBOKuIDDepwhWk7jZC0RTdopnAYKh

### Level 5

    ls
    cd inhere/
    find . type -f -size 1033c
    cd maybehere07
    ls -la
    cat ./.file2

Answer -  
DXjZPULLxYr17uwoI01bNLQbtFemEgo7

### Level 6

    ls /
    cd ..
    cd ..
    ls
    find . -user bandit7 -group bandit6 -size 33c

    cat ./var/lib/dpkg/info/bandit7.password

Answer -  
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs

### Level 7

    cat data.txt | grep millionth

Answer -  
cvX2JJa4CFALtqS87jk27qwqGhBM9plV

### Level 8

    cat data.txt | sort | uniq -u

Answer -  
UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR

### Level 9

    strings data.txt | grep ==

Answer -  
truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk

### Level 10
    
    cat data.txt | base64 -d

Answer -  
IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR

### Level 11

    cat data.txt  | tr '[a-z]' '[n-za-m]' | tr '[A-Z]' '[N-ZA-M]'

Answer -  
5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu

### Level 12

    mkdir /tmp/CC
    cp data.txt /tmp/CC
    cat data.txt | xxd -r > data2
    file data2

### Output: 
    
    gzip compressed data

Then do,
    
    mv data2 data2.gz
    gzip -d data2.gz
    file data2

Decompress files repeatedly till you get text file.  
Rename them with the appropriate extension before unzipping

    gzip -d data.gz  
    bzip2 -d data.bz  
    tar -xf data.tar  

Answer -  
8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL

### Level 13

    ssh bandit14@localhost -i sshkey.private

Answer -  
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e

### Level 14
You can find the password for the current level by going to -

    cd /etc/bandit_pass/
    cat bandit14

Password for level 14  
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e

    nc localhost 30000

Type the password of level 14

    4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e

Answer -  
BfMYroe26WYalil77FoDi9qh59eK5xNr

### Level 15
Helpful link -  
https://www.openssl.org/docs/man1.0.2/man1/s_client.html

    openssl s_client -connect localhost:30001

Then put the current level's password as input

Answer -  
cluFn7wTiGryunymYOu4RcffSxQluehd

### Level 16
Helpful links -  
https://www.lisenet.com/2013/finding-open-ports-and-listening-services-on-linux/  
https://nmap.org/book/man-port-specification.html


Simple ping scan
    
    nmap -sP localhost

Scanning from port 31000 to 32000 and finding their services

    nmap -v -sV -p 31000-32000 localhost

Output -
```
PORT      STATE SERVICE     VERSION
31046/tcp open  echo
31518/tcp open  ssl/echo
31691/tcp open  echo
31790/tcp open  ssl/unknown
31960/tcp open  echo
```

Then try connecting to 31518, 31790

    openssl s_client -connect localhost:31518

After inserting the current level's password, it gives the same password.  
Trying the next one, (directly input the password with cat and pipe).
We get an rsa key

Navigate to your tmp folder to save the rsa private key into out.txt

    cat /etc/bandit_pass/bandit16 | openssl s_client -connect localhost:31790 -quiet > out.txt

Then login to the next level with the private key

    ssh bandit14@localhost -i out.txt

Output - `unprotected private key`

    chmod 700 out.txt
    ssh bandit14@localhost -i out.txt

And we're in!

Answer (fetched from /etc/bandit_pass of level 17)  
xLYVMN9WE5zQ5vHacb0sZEVqbrp7nBTn

### Level 17




    





































