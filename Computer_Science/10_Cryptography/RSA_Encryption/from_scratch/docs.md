Do rsa explanation


Talk about how the strings we can encrypt are limited.
Won't work for rupee symbol
print(u"\u20B9") will not work

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
