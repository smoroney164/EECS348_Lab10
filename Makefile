CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: matrix

matrix: main.cpp
	$(CXX) $(CXXFLAGS) -o matrix main.cpp

clean:
	rm -f matrix