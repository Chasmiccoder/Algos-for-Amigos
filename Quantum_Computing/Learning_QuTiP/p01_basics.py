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
from qutip import Qobj, basis, fock, coherent, fock_dm, coherent_dm, thermal_dm, sigmax, sigmay, sigmaz, destroy, create, qeye, tensor


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

# Commutation relations (represented by [op1, op2])
def commutator(op1, op2):
    return op1*op2 - op2*op1

a = destroy(5)
print("Commutator of Annihilation and Creation Operators [a, a.dag()]:\n", commutator( a, a.dag() ) )
print()
# We don't get an identity matrix because we have truncated the hilbert space
# (Should be okay if highest Fock State is not involved)

# Checking if both momentum and position operators commute
x = (a + a.dag()) / pow(2, 0.5)
p = (a - a.dag()) / pow(2, 0.5) * (-1j)
print("Checking if both momentum and position operators commute [x,p]:\n", commutator(x,p))


wait()


# Trying Pauli Spin Inequalities
print("Verifying Pauli Spin Inequalities:")

# [sigmax, sigmay] = 2 . i . sigmaz
print("[sigmax, sigmay] - 2 . i . sigmaz = 0\n", commutator(sigmax(), sigmay()) - 2j*sigmaz() )
print()

# -i . sigmax . sigmay . sigmaz = 1
print("-i . sigmax . sigmay . sigmaz = 1\n", -1j * sigmax() * sigmay() * sigmaz() )
print()

# sigmax^2 = sigmay^2 = sigmaz^2 = 1
print("sigmax^2 = sigmay^2 = sigmaz^2 = 1\n", sigmax()**2 == sigmay()**2 == sigmaz()**2 == qeye(2))
print()
# qeye(2) is the 2x2 identity matrix


wait()


"""
                    --- Composite Systems ---
(Multi Qubit Systems)
"""

print("2 Qubit Composite System:\n")

sz1 = tensor(sigmaz(), qeye(2)) 
print("Creating an operator that does Sigma Z on the first qubit, but leaves the second qubit as it:\n", sz1)
print()
# For an operator that leaves the first qubit, and does Sigma Z on the second,  tensor(qeye(2), sigmaz()) 


psi1 = tensor(basis(2,1), basis(2,0))
print("Wave function where only first qubit is excited:\n", psi1)
print()

print("Action of the above operator on this wave function (excited first qubit):\n", sz1 * psi1)
print()

psi2 = tensor(basis(2,0), basis(2,1))
print("Wave function where only second qubit is excited:\n", psi2)
print()

print("Action of the above operator on this wave function (excited second qubit):\n", sz1 * psi2)
print()

# Therefore, sz1 * psi1 != psi1 and sz1 * psi2 == psi2  as expected

wait()

print("Coupling Term with tensor(sigmax, sigmax):\n", tensor(sigmax(), sigmax()))
print()

print("Coupled Two Qubit Hamiltonian,   H = e1 . sigmaz(1) + e2 . sigmaz(2) + g . sigmax(1)sigmax(2)")
epsilon = [1.0, 1.0]
g = 0.1

sz1 = tensor(sigmaz(), qeye(2) )
sz2 = tensor(qeye(2) , sigmaz())

H = epsilon[0] * sz1   +   epsilon[1] * sz2   +   g * tensor(sigmax(), sigmax())
print(H)



















print("\n\n--- reached the end ---\n")
