import os

def generatePrimes():
    """
    Generates two large primes P and Q
    """
    
    P = 170007611163882156467583070449223838584656753148867131633512190380283049593667937234054209916788376143894984910718820080485130228317492395177494053588704733242066260215738749826985323020318900966858054745093276666701971181051299894745771442097807356197274229456637808451705389506462483315002459525647
    Q = 481643715591972638598218313298174701613643321254523884689569786332541775926781293302556117738302307356981609721753075739005830996780920022755885174107599088199228946117515541982018885577402946246815718309298010594221374531947169982607824253065171036917904012166986458504590468987728792073331236197449

    return P, Q

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

def checkKeys():
    """
    Returns true if both the public and private key files have been generated
    """
    return os.path.isfile('./publicKey.txt') and os.path.isfile('./privateKey.txt')


def generateKeys():
    P, Q = generatePrimes()
    N    = P * Q
    phi  = (P-1) * (Q-1)
    e    = pow(2,16) + 1
    d    = extended_gcd(phi, e)

    if checkKeys():
        print("Warning! Previously generated keys will be overwritten")
        choice = input("Do you want to proceed? [Y/N] - ")
        
        if choice == "y" or choice == "Y":
            pass
        elif choice == "n" or choice == "N":
            print("No changes were made")
            return

    with open("publicKey.txt", "w") as file:
        file.writelines([str(e)+"\n", str(N)+"\n"])
    
    with open("privateKey.txt", "w") as file:
        file.writelines([str(d)+"\n", str(N)+"\n"])
    
    print("Public and Private Keys have been generated!\n")


def loadKeys():
    """
    Returns a tuple - (publicKey, privateKey)
    Where,
    publicKey  = [e, N]
    privateKey = [d, N]
    """
    if not checkKeys():
        return (-1,-1)
    
    file1 = open('publicKey.txt', 'r')
    file2 = open('privateKey.txt', 'r')

    publicKey = file1.readlines()
    privateKey = file2.readlines()

    publicKey = [int(publicKey[0]), int(publicKey[1])]
    privateKey = [int(privateKey[0]), int(privateKey[1])]

    file1.close()
    file2.close()

    return publicKey, privateKey

def encrypt(plaintext, publicKey):
    """
    plaintext is the message as a string
    publicKey = [e, N]
    """

    e = publicKey[0]
    N = publicKey[1]

    ciphertext = ""
    for character in plaintext:
        ch = ord(character)

        if ch < 100:
            ch = "0" + str(ch)
        else:
            ch = str(ch)
        
        ciphertext += ch
    
    ciphertext = str( pow( int(ciphertext), e, N ) )

    return ciphertext


def decrypt(ciphertext, privateKey):
    """
    ciphertext is the encrypted message as a string
    privateKey = [d, N]
    """

    d = privateKey[0]
    N = privateKey[1]

    plaintext = str( pow(int(ciphertext),d,N) )
    
    if len(plaintext)%3 != 0:
        plaintext = "0" + plaintext
    
    message = ""

    for i in range(0, len(plaintext), 3):
        ch = plaintext[i:i+3]
        ch = chr(int(ch))
        message += ch

    return message
