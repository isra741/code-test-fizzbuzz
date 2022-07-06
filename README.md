# code-test-fizzbuzz
Simple Fizzbuzz test

# Project structure
- Decoder.hpp - Class definition of the application core
- Decoder.cpp - Class implementation of the application core
- main.cpp - Application wrape proving command line verification and exception catching
- Makefile - Makefile for cleaning and building the standalone application 
- Tester.py - Automated software test script in Python 

# Building the Application

On **Windows**:

MingGW-make is required to build this application on linux

```
mingw32-make clean
mingw32-make 
```

On **Linux**:

In linux, the bult-in g++ commands can be used:

```
$ make clean
$ make 
```

# Testing Code

In order to test the code, the Tester python script should be executed.
This script will execute the application collect to the output and compare to
the reference generator in order to report possible errors. The configurable 
automated test also provides some configurations like fault injections and random 
number generation for each execution.

```
$ python tester.py 
```

# Security

This code is secured by configuring the merge request requirement and the owner review

# License

This code is licensed by the MIT license.
