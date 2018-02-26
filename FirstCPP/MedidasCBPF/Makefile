

CXX= `root-config --cxx`
CXXFLAGS= `root-config --cflags`
LDFLAGS= `root-config --ldflags`
 LDLIBS=`root-config --glibs`
 C=g++



default: all

all: MyFirstHistogram EXAMPLE1 Code solution 

MyFirstHistogram: MyFirstHistogram.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o  $@ 
   

EXAMPLE1: EXAMPLE1.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

Code: Code.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

solution: solution.cpp
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

clean:  
	$(RM) MyFirstHistogram EXAMPLE1 Code solution


       
.PHONY: clean
