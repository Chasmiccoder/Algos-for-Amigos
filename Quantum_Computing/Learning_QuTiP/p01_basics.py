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
from qutip import Qobj, basis, fock, coherent, fock_dm, coherent_dm, thermal_dm, sigmax, sigmay, sigmaz, destroy, create


"""
                    --- Quantum Objects ---
"""

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
print("Eigenenergies/ Eigenvalues of H: ", H.eigenenergies())

wait()

print("sy: ", sy)
print("Hermitian Conjugate/Conjugate Transpose of sy: ", sy.dag()) # Same as sy
print("Trace of sy: ", sy.tr())

wait()


"""
                    --- States ---
"""

# Fundamental Basis States (Fock states of oscillator modes)
N = 2 # number of states in the hilbert space
n = 1 # state which will be occupied

print("Basis with {N} states, where state {n} is occupied:\n".format(N = N, n = n), basis(N, n) ) # Same as fock(N,n)
print()

# Similarly,
print("Basis with {N} states, where state {n} is occupied:\n".format(N = 4, n = 2), fock(4, 2) )
print()

# Generating a Coherent State
print("Coherent State with {N} fock states in hilbert space and eigenvalue = {alpha} \n".format(N = 10, alpha = 1.0), coherent(N = 10, alpha=1.0))
print()

# Fock state (as a density matrix)
print("Fock State as a Density Matrix with hilbert space size = {dim} and occupied state = {n} \n".format(dim = 5, n = 2), fock_dm(5,2))
print()

print("Coherent State as a Density Matrix with number of fock states = {N} and eigenvalue = {alpha}".format(N = 8, alpha = 1.0), coherent_dm(N = 8, alpha = 1.0))
print()

n = 1 # average number of thermal photons
print("Thermal State as Density Matrix with with number of basis states in hilbert space = {N} and expectation value for number of particles in thermal state = {n}\n".format(N = 8, n = n), thermal_dm(8,n))

wait()

"""
                    --- Operators ---
"""

# Qubit Operators (2 level system)

print("Sigma x:\n", sigmax())
print("Sigma y:\n", sigmay())
print("Sigma z:\n", sigmaz())

wait()

# Harmonic Oscillator Operators

print("Annihilation Operator with {N} fock states (dimensions) in the hilbert space:\n".format(N = 8), destroy(N=8))
print()

print("Creation Operator with {N} dimensions in the hilbert space:".format(N = 8))
print(create(N = 8)) # which is the same as destroy(8).dag()
print()

print("Check if creation operator = annihiliation operator's complex conjugate: ", destroy(N=8).dag() == create(N=8))

wait()

# You can create the position operator from the annihilation operator
annihilation_operator = destroy(N=8)
x = annihilation_operator + annihilation_operator.dag()
print("Position Operator (generated using the annihilation operator):\n", x)


wait()




















print("\n\n--- reached the end ---\n")
