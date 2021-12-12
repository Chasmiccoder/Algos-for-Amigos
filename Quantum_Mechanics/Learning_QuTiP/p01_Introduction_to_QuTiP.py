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
from qutip import Qobj, basis, fock, coherent, fock_dm, coherent_dm, thermal_dm, \
                        sigmax, sigmay, sigmaz, destroy, create, qeye, tensor, \
                        mesolve, expect


""" --------------- </Quantum Objects> --------------- """

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


""" --------------- </States> --------------- """

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


""" --------------- </Operators> --------------- """

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


""" --------------- </Composite Systems (Multi Qubit Systems)> --------------- """

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


wait()

# By passing different operators to tensor(), we can create different composite systems
print("Jaynes-Cumming Hamiltonian for a qubit-cavity system:")

# Cavity Frequency
wc = 1.0

# Qubit/Atom Frequency
wa = 1.0

# Coupling Strength
g = 0.1

# Cavity made operator
a = tensor(destroy(5), qeye(2))

# Qubit/Atom operators
sz = tensor(qeye(5), sigmaz()) # Sigma z on the second qubit
sm = tensor(qeye(5), destroy(2)) # Sigma Minus Operator

# Jaynes-Cumming Hamiltonian
H = wc * a.dag() * a - 0.5 * wa * sz + g * (a * sm.dag() + a.dag() * sm)

print(H)
print()

print("Identity with Sigma+\na.sigma+ = tensor(a,1).tensor(1,sigma+)\n[1 is identity]")
a  = tensor(destroy(3), qeye(2))
sp = tensor(qeye(3), create(2))

print("a . sigma+\n", a * sp )
print("\ntensor(destroy(3), create(2))\n", tensor(destroy(3), create(2)))

wait()

""" --------------- </Unitary Dynamics> --------------- """

# The Unitary evolution of a quantum system can be calculated by the Master-Equation Solve mesolve()
# If no collapse operators are given (non-dissipative dynamics), then mesolve() adopts  - 
#   the unitary evolution of the Schrodinger (for initial state in state vector form)
#   the von Neuman Equation (for initial state in density matrix form)
# An object of Odedata is returned

print("Evolution of Hamiltonian, H = sigma-x, with initial state |1> (in the sigma-z basis)")
H = sigmax()

# initial state
psi0 = basis(2,0)  

# list of times for which the solver should store the state vector
tlist = np.linspace(0,10,100)

result = mesolve(H, psi0, tlist, [], [])
print("\nresult: ", result)

# result.states is a list of quantum objects of the wavefunctions at the times request (tlist)
print("Number of captured wavefunctions: ", len(result.states))
print("Initial State:\n", result.states[0])
print("Final State:\n", result.states[-1])
print("\n")

""" --------------- </Expectation Values> --------------- """

# The expectation values of an operator, when given a state vector or density matrix 
# can be calculated using expect()

print("Expectation of sigma-z on the final state in the above Unitary evolution:\n", expect(sigmaz(), result.states[-1]))

print("\n\nExpectation of the first 5 states in the above Unitary evolution:\n", expect(sigmaz(), result.states[:5]))
# similarly, but just passing, result.states, we can get the expectations of sigma-z on all the 100 wavefunctions


print("Plot of the expectation of sigma-z over all the states of the above Unitary evolution:")
fig, axes = plt.subplots(1,1)
axes.plot(tlist, expect(sigmaz(), result.states))

axes.set_title("Expectation of sigma-z over all the states of the Unitary evolution:")
axes.set_xlabel(r'$t$', fontsize=20)
axes.set_ylabel(r'$\left<\sigma_z\right>$', fontsize=20)

plt.show()


# if we only need the expectation values (and not the wavefunctions themselves),
# we can pass a list of the operators to mesolve()
result = mesolve(H, psi0, tlist, [], [sigmax(), sigmay(), sigmaz()])

fig, axes = plt.subplots(1,1)

axes.plot(tlist, result.expect[2], label=r'$\left<\sigma_z\right>$')
axes.plot(tlist, result.expect[1], label=r'$\left<\sigma_y\right>$')
axes.plot(tlist, result.expect[0], label=r'$\left<\sigma_x\right>$')

axes.set_title('Expectations of sigma x,y,z, for the Unitary Evolution')
axes.set_ylabel('Expectations of sigma x,y,z')
axes.set_xlabel(r'$t$', fontsize=20)

axes.legend(loc=2)
plt.show()

wait()

""" --------------- </Dissipative Dynamics> --------------- """

# Adding the collapse operators to mesolve() to add dissipation
# A collapse operator is one that describes how the system is interacting with its environment
# E.g. for quatum harmonic oscillator with
#       H = h_bar * omega * a.dag * a
#
# which loses photons to its environment with a relaxation rate of k (kappa)
# The collapse is described by root(k) . a
# (a is the photon annihilation operator) of the oscillator

print("Dissipative Dynamics of a Quantum Oscillator with H = h_bar * omega * a.dag * a")

w     = 1.0              # oscillator frequency
kappa = 0.1              # relaxation rate
a     = destroy(10)      # oscillator annihilation operator
rho0  = fock_dm(10, 5)   # Initial state (fock state with 5 photons)
H     = w * a.dag() * a  # Hamiltonian

c_ops = [pow(kappa, 0.5) * a]  # List of collapse operators (only 1 in this case)

tlist = np.linspace(0,50,100)

# Solver will return the expectation value of the photon number state operator a.dag()*a
result = mesolve(H, rho0, tlist, c_ops, [a.dag() * a])

fix, axes = plt.subplots(1,1)
axes.plot(tlist, result.expect[0])

axes.set_title('Dissipation of the harmonic oscillator with relaxation rate: {k}'.format(k=kappa))
axes.set_xlabel(r'$t$', fontsize=20)
axes.set_ylabel(r"Photon number", fontsize=16);
plt.show()


""" --------------- </Software Versions> --------------- """
"""

Software	Version
QuTiP	    4.6.2
Numpy	    1.21.4
SciPy	    1.7.2
matplotlib	3.5.0
Cython	    0.29.25
Number of CPUs	8
BLAS Info	OPENBLAS
IPython 	7.30.1
Python	    3.9.6
OS	nt [win32]

Use -
from qutip.ipynbtools import version_table
version_table()
in jupyter
"""

print("\n\n--- reached the end ---\n")
