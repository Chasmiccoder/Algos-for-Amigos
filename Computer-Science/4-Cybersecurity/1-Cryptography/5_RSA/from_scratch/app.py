import myRSA

print("\nWelcome to the RSA App!\n")

publicKey  = []
privateKey = []

while True:
    print("Operations:")
    print("1 - Generate Pair of Public and Private Keys")
    print("2 - Load Pair of Public and Private Keys")
    print("3 - Encrypt a message")
    print("4 - Decrypt a message")
    print("5 - Exit!")

    choice = int(input("Enter choice: "))
    print()

    if choice == 1:
        myRSA.generateKeys()

    elif choice == 2:
        publicKey, privateKey = myRSA.loadKeys()
        
        if (publicKey, privateKey) == (-1, -1):
            print("You need to generate the keys first!")
            
        else:
            print("The public and private keys have been loaded!\n")
        
    elif choice == 3:
        if publicKey == [] or privateKey == []:
            print("You need to load the keys first!")
        else:
            message = input("Enter plaintext:\n")
            ciphertext = myRSA.encrypt(message, publicKey)
            print("Ciphertext:\n", ciphertext)
            print()
    
    elif choice == 4:
        if publicKey == [] or privateKey == []:
            print("You need to load the keys first!")
        else:
            ciphertext = input("Enter ciphertext:\n")
            message = myRSA.decrypt(ciphertext, privateKey)
            print("Plaintext:\n", message)
            print()
    
    elif choice == 5:
        print("Thank you for using the app!")
        break

    else:
        print("Invalid Input!")
