import simple
import numpy
from time import time

a = simple.arange(1000000)

numpy_start = time()
print("Numpy says:", numpy.dot(a,a))
numpy_end = time()

swig_start = time()
print("SWIG says:", simple.dot(a,a))
swig_end = time()
x = simple.heat_transfer(1);
print("Time of numpy:", (numpy_end-numpy_start))
print("Time of SWIG:", (swig_end-swig_start))
