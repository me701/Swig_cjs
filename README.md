# Swig_cjs

Quickstart:
Create Header (.h) and Implementation files (.cpp)

Create swig interface file (.i)
EX:
    %module swig_example
    %{
    #include "swig_example.h"
    %}

    %include "std_vector.i"
    %template(DoubleVector) std::vector<double>;

    %include "swig_example.h"

There are now three files in the folder

Run the following commands to create a python wrapper for the C++ class


$ swig -c++ -python swig_example.i
$ g++ -fpic -c -I/home/clinton/anaconda3/include/python3.7m swig_example.cpp swig_example_wrap.cxx
$ g++ -shared swig_example.o swig_example_wrap.o -o _swig_example.so
_
