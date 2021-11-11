"""

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

"""



# Euclid's GCD Algorithm
def gcd(x,y):
    if x == 0:
        return y
    return gcd(y%x, x)



# Pick 2 prime numbers P and Q (must be large)

# Secret values talk about the character limit and show it will smaller primes
# p = 2
# q = 7

# p = 719
# q = 457

# p = 1031
# q = 1433

# p = 3319
# q = 2953

# p = 5843
# q = 4871

# p = 19441
# q = 23497



# p = 8683317618811886495518194401279999999 
# q = 87178291199


# with 300 digit primes
p = 170007611163882156467583070449223838584656753148867131633512190380283049593667937234054209916788376143894984910718820080485130228317492395177494053588704733242066260215738749826985323020318900966858054745093276666701971181051299894745771442097807356197274229456637808451705389506462483315002459525647
q = 481643715591972638598218313298174701613643321254523884689569786332541775926781293302556117738302307356981609721753075739005830996780920022755885174107599088199228946117515541982018885577402946246815718309298010594221374531947169982607824253065171036917904012166986458504590468987728792073331236197449


# Public values
N = p * q # This is also called the modulus

# Euler's Totient Function phi(N) [also a secret]
phi = (p-1) * (q-1) 

# Choose e such that 1 < e < phi(N) and e is coprime with N and phi (or: gcd(e,N) = gcd(e,phi) = 1 )
# e = -1 # Typically taken as 2^16 + 1 (for large p,q)
# for i in range(2,phi):
#     if gcd(i,N) == 1 and gcd(i,phi) == 1:
#         e = i


e = pow(2,16) + 1

publicKey = [e,N]


"""
# Choose d such that d * e mod(phi(N)) = 1
d = 2 # This function will take FOREVER
while ((d%phi) * (e%phi)) % phi != 1:
    d += 1

d = d + phi # Picking the next value for d which satisfies the constraint
"""

def extended_gcd(phi, e):
    """
    Gives us the inverse (d)
    """
    d = 1
    top1 = phi
    top2 = phi

    while e != 1:
        k = top1 // e

        oldTop1 = top1
        oldTop2 = top2
        
        top1 = e
        top2 = d

        e = oldTop1 - e * k
        d = oldTop2 - d * k

        if d < 0:
            d = d % phi

    return d




# Finding d with the Extended Euclidean Algorithm
d = extended_gcd(phi,e) # is called the inverse (multiplicative inverse of e mod phi)














# print(66**d % phi)
print("RSA Key Elements:")
print("N:", N)
print("d:", d)
print("phi:", phi, end="\n\n")



# plaintext = "HelloWorld"
# plaintext = "B"
plaintext = "hello, World! 1234567890 @#$%^&*()" # Won't work for unicode characters like the rupee symbol
print("Plaintext: ", plaintext)

def encrypt(plaintext):
    """
    plaintext is the message as a string
    """

    # print("sindel:", N)
    # return (plaintext ** e) % N

    ciphertext = ""
    for character in plaintext:
        ch = ord(character)
        # ch = (ch ** e) % N

        if ch < 100:
            ch = "0" + str(ch)
        else:
            ch = str(ch)
        
        # print(t)
        ciphertext += ch
    
    # ciphertext = int(ciphertext)**e % N
    ciphertext = pow( int(ciphertext), e, N )
    ciphertext = str(ciphertext)

    return ciphertext

ciphertext = encrypt(plaintext)
print("Ciphertext:", ciphertext)


def decrypt(ciphertext):
    """
    ciphertext is the encrypted message as a string
    """

    # plaintext = str( int(ciphertext)**d % N ) #don't do it this way!!
    plaintext = str( pow(int(ciphertext),d,N) )
    
    if len(plaintext)%3 != 0:
        plaintext = "0" + plaintext
    
    message = ""

    for i in range(0, len(plaintext), 3):
        ch = plaintext[i:i+3]

        ch = chr(int(ch))
        message += ch

    return message


new_message = decrypt(ciphertext) 
print("Answer: ", new_message)





    

































