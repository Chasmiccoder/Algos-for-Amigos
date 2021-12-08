""""
Source -
https://qutip.org/tutorials.html
"""

from numpy import pi
from qutip import eseries, sigmax


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












print("\n\n--- reached the end ---\n")
