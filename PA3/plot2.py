# -*- coding: utf-8 -*-

#!/usr/bin/env python
import os
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
filename = "prog2.dat"
data = np.transpose(np.loadtxt(filename))
fig = plt.figure()
ax = plt.subplot(111)
ax.plot(data[0], data[1],'ro',label="numeric")
#ax.plot(data[0], data[2],'b',label="exact")
plt.legend()
tmp = filename[:-4]+'.png'
fig.savefig(tmp)
