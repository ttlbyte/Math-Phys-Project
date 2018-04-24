#!/usr/bin/env python3
import os
import numpy as np
from scipy.interpolate import splrep, splev
import matplotlib
import matplotlib.pyplot as plt
filename = "mk_N_300_T_0.010000_Step_2000.dat"
data=np.transpose(np.loadtxt(filename))
fig = plt.figure()
ax = plt.subplot(111)
plt.xlabel("Step")
plt.ylim((-1,1))
plt.ylabel("Average moment")
ax.plot(data[0], data[1])
#ax.plot(data[0], data[3],'y',label="xc energy of pbe")
#ax.legend(loc=2)
tmp = filename[:-4]+'.png'
fig.savefig(tmp)
