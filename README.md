# Swig Guide

# Quickstart:
build with command make

swig -python example.i
gcc -c -fpic example.c example_wrap.c -I/home/clinton/anaconda3/include/python3.7m
gcc -shared example.o example_wrap.o -o _example.so

Create Header (.h) and Implementation files (.cpp)

Create swig interface file (.i)
2.4.1 SWIG interface file

/* File : example.i */
%module example
%{
/* Put headers and other declarations here */
extern double My_variable;
extern int    fact(int);
extern int    my_mod(int n, int m);
%}

extern double My_variable;
extern int    fact(int);
extern int    my_mod(int n, int m);

The interface file contains ISO C function prototypes and variable declarations. The %module directive defines the name of the module that will be created by SWIG. The %{ %} block provides a location for inserting additional code, such as C header files or additional C declarations, into the generated C wrapper code.

There are now three files in the folder
# Compiling
Run the following commands to create a python wrapper for the C++ class


$ swig -c++ -python swig_example.i
$ g++ -fpic -c -I/home/clinton/anaconda3/include/python3.7m swig_example.cpp swig_example_wrap.cxx
$ g++ -shared swig_example.o swig_example_wrap.o -o_swig_example.so

the correct parameter for -I can be found via the following command
$ python3-config --cflags

# Usage
after these steps, our C++ program can be imported via python
Simply import the .py file that was created in the commands above by using the standard import format
