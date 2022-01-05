""""
Source -
https://qutip.org/tutorials.html
"""

from numpy import pi
from qutip import eseries, sigmax, sigmaz, esval, expect, fock_dm


# Aesthetic function
def wait():
    inp = input("\nProceed? [Y/n]: ")
    while inp != 'y' and inp != 'Y':
        inp = input("Proceed? [Y/n]: ")
    print("\n")


""" --------------- </Exponential Series Objects Examples> --------------- """

print("Exponential Series:\n")
print("sigma-x * exp(i.w.t)")

omega = 1.0  # w
es1   = eseries(sigmax(), 1j * omega)
print(es1)

print("\nsigma-x * cos(w.t)")

omega = 1.0
es2   = eseries(0.5 * sigmax(), 1j * omega) + eseries(0.5 * sigmax(), -1j * omega)
print(es2)

wait()


""" --------------- </Evaluate the eseries object at various times> --------------- """

# At t = 0
print("sigma-x * cos(w.t) at time t = 0\n", esval(es2, 0.0) )

print("sigma-x * cos(w.t) at time t = [0,pi,2pi]\n", esval(es2, [0.0, 1.0 * pi, 2.0*pi]))

wait()

""" --------------- </Expectation of eseries> --------------- """

print("Expectation of sigma-x on sigma-x * cos(w.t)\n", expect(sigmax(), es2))

wait()

""" --------------- </Arithmetic with eseries> --------------- """

es1 = eseries(sigmax(), 1j * omega)
es2 = eseries(sigmax(), -1j * omega)

print("Eseries 1 -\n", es1)
print("Eseries 2 -\n", es2)

print("Eseries 1 + Eseries 2\n", es1 + es2, end="\n\n")
print("Eseries 1 - Eseries 2\n", es1 - es2, end="\n\n")
print("Eseries 1 * Eseries 2\n", es1 * es2, end="\n\n")
print("Eseries: (es1 + es2) * (es1 - es2) \n", (es1 + es2) * (es1 - es2), end="\n\n")

wait()

""" --------------- </Expecation Values of eseries> --------------- """

es3 = eseries([0.5 * sigmaz(), 0.5 * sigmaz()], [1j, -1j]) + eseries([-0.5j * sigmax(), 0.5 * sigmax()], [1j, -1j])
print("*Eseries:\n", es3)
print("Eseries' Value at t = 0.0:\n", es3.value(0.0))
print("Eseries' Value at t = pi/2:\n", es3.value(pi/2))

rho = fock_dm(2,1)
es3_expect = expect(rho, es3)
print("For fock density matrix(2,1) Expectation of fock density matrix(2,1) on the state given above (*Eseries)\n", es3_expect)
print("Expectation values at times 0 and pi/2 are:\n", es3_expect.value([0.0, pi/2]))

wait()

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

Use (in jupyter)-
from qutip.ipynbtools import version_table
version_table()
"""

print("\n\n--- reached the end ---\n")
