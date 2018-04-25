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
T="T="+filename.split('_')[4]
ax = plt.subplot(111)
plt.xlabel("Step")
plt.ylim((-1.1,1.1))
plt.ylabel("< M >")
i=1000
tmp=0
for j in range(199):
    i += 1000*j
    if(abs(tmp-np.mean(data[1][i-1000:i]))<1.0e-4):break;
    tmp=np.mean(data[1][i-1000:i])
    print(tmp)
ax.plot(data[0][:i], data[1][:i],label=T)
#ax.plot(data[0], data[3],'y',label="xc energy of pbe")
ax.legend()
tmp = filename[:-4]+'.png'
fig.savefig(tmp,dpi=320)
