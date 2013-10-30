all:
	g++ Main.cpp LinearTheory.cpp MyChiSquared.cpp MyMinimizer.cpp MyFileReader.cpp -o testprogram -O3 -larmadillo -llapack -lblas
