

CXX= `root-config --cxx`
CXXFLAGS= `root-config --cflags`
LDFLAGS= `root-config --ldflags`
 LDLIBS=`root-config --glibs`
 C=g++



default: all

all: MyFirstHistogram EXAMPLE1 Code solution HistogramLegend signal.o testSignal AnalysisCBPF

MyFirstHistogram: MyFirstHistogram.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o  $@ 
   

EXAMPLE1: EXAMPLE1.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

Code: Code.cc
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

solution: solution.cpp signal.o
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

HistogramLegend:HistogramLegend.cpp
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

signal.o: Signal.cpp
	g++ -c -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

testSignal: signal.o testSignal.cpp
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

AnalysisCBPF: AnalysisCBPF.cpp signal.o
	g++ -g -Wall `root-config --cflags --libs` -L$(ROOTSYS)/lib $(ROOTLIBS) $? -o $@

clean:  
	$(RM) MyFirstHistogram EXAMPLE1 Code solution HistogramLegend  signal.o testSignal AnalysisCBPF
       
.PHONY: clean
