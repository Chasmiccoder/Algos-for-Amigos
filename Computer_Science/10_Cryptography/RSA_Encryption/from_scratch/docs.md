Do rsa explanation


Ideally, you want to pick a relatively small value for e.
This is to make encryption faster (without worrying about losing encryption strength)
That way, d will be really large, which makes it harder to guess.

Current status of encryption -
Algorithms like AES and RSA are still used extensively. Now, while Elliptic Curve Cryptography is 
replacing RSA in many scenarios, the encryption is still symmetric, which means that we first need to
pass the private keys via communication channels which may or may not be secure. 

This is why things like SSH certificates still use RSA. Infact, we can use RSA to establish 
a secure channel and then exchange keys involving more powerful encryption algorithms.

Algos like DES, SHA, and Blowfish are also some of the popular encryption protocols used today.




Why Python is making our life simpler:
    You can't store a 300 digit number in a variable in C, C++ and many other languages, so to store
    these numbers you need to use arrays. 
    The largest integer you can store in long long datatype is 9223372036854775807

    In Python, however, supports arbitrary precision of integers. It can handle numbers as large as 
    those that can be supported by your memory :) 

Talk about how the strings we can encrypt are limited.
Won't work for rupee symbol
print(u"\u20B9") will not work


# plaintext = str( int(ciphertext)**d % N ) #don't do it this way!!

app.py is basically a menu driver program

Limitations of RSA -
We can't encrypt data that is larger in size than the key size

For a 1024 bit RSA Key, the string size limit is about 117 bytes  per message (each character is 1 byte / 8 bits)
Then why is RSA still used? RSA encryption is asymmetric which means that we
can send messages through an unsafe channel and still expect to maintain the encryption.
In symmetric encryption we have to worry about first sending the private key to the recipient
which may not always be possible.

This is why in practice, we use RSA to encrypt the private key of a much stronger and reliable 
encryption (like AES), and then we send this private key to the receiver, with which we can
send large files encrypted in AES!

A 1024 bit RSA key means that the modulus (N) is in the range (2^1023, 2^1024)
The limit is decided by: 
floor(n/8)-11 
(Derived from PKCS#1 Public Key Cryptography Standards)

In summary, to send larger messages, you need a larger modulus, and since the modulus has
to be finite, there is a limit to the size of the message we can send.

short note on attacks



Resources + References:
=======================

To get large primes
https://bigprimes.org/

If you want to revise the whole algo (especially for Euclid's Algo)
https://www.youtube.com/watch?v=Z8M2BTscoD4

Further Reading:
================

How to generate large primes from scratch
https://www.geeksforgeeks.org/how-to-generate-large-prime-numbers-for-rsa-algorithm/
