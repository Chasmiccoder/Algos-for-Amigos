""""
Source -
https://qutip.org/tutorials.html
"""

""" --------------- </Groundstate of an Ultra Strong Coupled Atom Cavity System> --------------- """

import matplotlib.pyplot as plt
import numpy as np
from qutip import tensor, destroy, qeye, shape, expect, ket2dm
import time
from mpl_toolkits.mplot3d import Axes3D


def compute(N, wc, wa, glist, use_rwa):
    # Pre-compute operators for the hamiltonian 
    a = tensor(destroy(N), qeye(2))
    sm = tensor(qeye(N), destroy(2))
    nc = a.dag() * a
    na = sm.dag() * sm

    i = 0
    na_expt = np.zeros(shape(glist))
    nc_expt = np.zeros(shape(glist))

    for g in glist:
        # recalculate the hamiltonian for each g
        if use_rwa:
            H = wc * nc + wa * na + g * (a.dag() * sm + a * sm.dag())
        else:
            H = wc * nc + wa * na + g * (a.dag() + a) * (sm + sm.dag())

        
        # ground state of the composite system
        evals, ekets = H.eigenstates()
        psi_ground = ekets[0]
        na_expt[i] = expect(na, psi_ground)
        nc_expt[i] = expect(nc, psi_ground)

        i += 1

    return nc_expt, na_expt, ket2dm(psi_ground)









