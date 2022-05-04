Problems -
https://overthewire.org/wargames/bandit/

Level 0

    ssh bandit.labs.overthewire.org -p 2220 -l bandit0
    ls
    cat readme

Answer -
boJ9jbbUNNfktd78OOpsqOltutMc3MY1

Level 1
Reading a file with the name "-"

    cat ./-

Answer -
CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9

Level 2

    cat "./spaces in this filename"

Answer -
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK

Level 3
    
    cd inhere
    ls
    ls -la
    cat .hidden

Answer -
pIwrPrtPN36QITSp3EQaw936yaFoFgAB

Level 4

    ls
    cat ./-file07

Answer -
koReBOKuIDDepwhWk7jZC0RTdopnAYKh

Level 5

    ls
    cd inhere/
    find . type -f -size 1033c
    cd maybehere07
    ls -la
    cat ./.file2

Answer -
DXjZPULLxYr17uwoI01bNLQbtFemEgo7

Level 6

    ls /
    cd ..
    cd ..
    ls
    find . -user bandit7 -group bandit6 -size 33c

    cat ./var/lib/dpkg/info/bandit7.password

Answer -
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs

Level 7

    cat data.txt | grep millionth

Answer -
cvX2JJa4CFALtqS87jk27qwqGhBM9plV

Level 8

    cat data.txt | sort | uniq -u

Answer -
UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR

Level 9

    strings data.txt | grep ==

Answer -
truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk

Level 10
    
    cat data.txt | base64 -d

Answer -
IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR

Level 11

    cat data.txt  | tr '[a-z]' '[n-za-m]' | tr '[A-Z]' '[N-ZA-M]'

Answer -
5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu

Level 12

    mkdir /tmp/CC
    cp data.txt /tmp/CC
    cat data.txt | xxd -r > data2
    file data2

Output: 
    
    gzip compressed data

Then do,
    
    mv data2 data2.gz
    gzip -d data2.gz
    file data2

Decompress files repeatedly till you get text file. Rename them with the  
appropriate extension before unzipping

    gzip -d data.gz  
    bzip2 -d data.bz  
    tar -xf data.tar  

Answer -
8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL

Level 13













