import simple
import numpy
from time import time
import matplotlib.pyplot as plt

# declarations to append
num=[]
s=[]
n=[]
m=[]
p=[] 

# loop through increasingly large arrays
for i in range(100000,1000000,100000):
        a = simple.arange(i)
        p.append(i)

        # run and time Numpy function
        numpy_start = time()
        num.append(numpy.dot(a,a))
        numpy_end = time()
        n.append(numpy_end-numpy_start)
        
        # run and time simple.c
        swig_start = time()
        s.append(simple.dot(a,a))
        swig_end = time()
        m.append(swig_end-swig_start)
        x = simple.heat_transfer(1);

# plot times for comparison
plt.figure()
plt.plot(p,n, p,m)
plt.figlegend(labels=('Numpy', 'SWIG'))
plt.xlabel('Array Dimension')
plt.ylabel('Time')

plt.figure()
plt.plot(p,num, p,s)
plt.figlegend(labels=('Numpy', 'SWIG'))
plt.xlabel('Array Dimension')
plt.ylabel('Solution')
