#!/usr/bin/env python3
import os, sys
import numpy as np
from scipy.interpolate import splrep, splev
import matplotlib
import matplotlib.pyplot as plt
#filename = "mk_N_500_T_0.100000_Step_5000.dat"
filename=sys.argv[1]
data=np.transpose(np.loadtxt(filename))
fig = plt.figure()
ax = plt.subplot(111)
plt.xlabel("Step")
plt.ylim((-0.1,1.1))
plt.ylabel("< M >")
plt.xlabel('T')
ax.plot(data[0], data[1],"o-")
#ax.plot(data[0], data[3],'y',label="xc energy of pbe")
#ax.legend(loc=2)
tmp = filename[:-4]+'.png'
fig.savefig(tmp,dpi=320)
