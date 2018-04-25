#!/usr/bin/env python
# encoding: utf-8

import os
from numpy import *
filename=[]
for i in os.listdir('.'):
    if i.startswith('mk_'):filename.append(i)

data={}
for i in filename:
    fp=open(i)
    lines=fp.readlines()[-20000:]
    sum=0
    for j in lines:
        sum+=float(j.split()[-1])
    sum = abs(sum/20000.0)
    data[float(i.split('_')[4])]=sum

a=[]
for i in data:
    a.append(i)

b=array(a)
for i in sort(b):
    print(str(i)+'\t'+str(data[i]))
