CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: matrix

matrix: matrix.cpp
	$(CXX) $(CXXFLAGS) -o matrix matrix.cpp

clean:
	rm -f matrix
