# $Id: Makefile,v 1.30 2009/11/11 17:18:14 gcowan Exp $
SHELL = /bin/sh
UNAME = $(shell uname)

################
##linux
CXX          = g++
RM           = rm -f
AR           = ar cru

##Flags
#CXXFLAGS     += -D_DEBUG
CXXFLAGS     = -O3 -gstabs -fPIC -funroll-loops -larmadillo -llapack -lblas # -Wall

ROOTCFLAGS   = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS     = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS    = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --glibs)

CXXFLAGS += $(ROOTCFLAGS)

LIBS       += $(ROOTLIBS) -lHtml -lThread -lMinuit -lRooFit -lRooFitCore -lMathCore #-lboost_thread-xgcc40-mt #-lMathMore

GARBAGE  = $(OBJDIR)/*.o *.so *.rootmap 

MCSimulation: Main.cpp LinearTheory.cpp MaxLikelihood.cpp MyChiSquared.cpp MyFileReader.cpp MyPdf.cpp 
	$(CXX) $(CXXFLAGS) $(LIBS) Main.cpp LinearTheory.cpp MaxLikelihood.cpp MyChiSquared.cpp MyFileReader.cpp MyPdf.cpp -o MCSimulation

clean   :
	$(RM) $(GARBAGE)

cleanall:
	$(RM) $(GARBAGE)


