""""
Source -
https://qutip.org/tutorials.html
"""

# Aesthetic function
def wait():
    inp = input("\nProceed? [Y/n]: ")
    while inp != 'y' and inp != 'Y':
        inp = input("Proceed? [Y/n]: ")
    print("\n")

import matplotlib.pyplot as plt
import numpy as np
from qutip import Qobj


# Creating a Quantum Object
q = Qobj([[1],[0]])
print("Q object -", q)
print("Dims : ", q.dims)
print("Shape: ", q.shape)
print("Data : ", q.data) # Matrix in sparse matrix format

# Dense Matrix Representation
print("Dense Matrix: ", q.full())
print("is Hermitian?: ", q.isherm)
print("Type: ", q.type)

wait()

# Pauli Y Gate
sy = Qobj( [[0, -1j], 
            [1j,  0]])

print("Sigma Y: ", sy)

sz = Qobj( [[1, 0],
            [0,-1]])

print("Sigma Z: ", sz)

wait()

# Arithmetic with quantum objects
H = 1.0 * sz + 0.1 * sy
print("Qubit Hamiltonian (H = sz + 0.1 * sy):\n", H)




















print("\n\n--- reached the end ---\n")
