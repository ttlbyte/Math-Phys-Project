# -*- coding: utf-8 -*-

#!/usr/bin/env python3
import os
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
filename = []
for i in os.listdir('.'):
    if r".dat" in i: filename.append(i)

for i in filename:
    data = np.transpose(np.loadtxt(i,skiprows=1))
    nr = data[1][0]
    nf = data[2][0]
    fig = plt.figure()
    ax = plt.subplot(111)
    ax.plot(data[0], data[1],'r', label=r'$n_R$')
    ax.plot(data[0], data[2],'b', label=r'$n_F$')
    plt.xlabel(r'$\tau $')
    plt.ylabel('population density')
    plt.title(i[:-4])
    ax.legend()
    tmp = i[:-4]+'.png'
    fig.savefig(tmp)
