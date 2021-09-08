CXX:= g++
CXXFLAGS:= -std=c++17 -Wall -Wextra -Wpedantic

main: driver.cpp FPKState.hpp StateBase.hpp SuperQueenState.hpp
	$(CXX) -o driver.o driver.cpp $(CXXFLAGS) -lboost_program_options

clean:
	find . -name '*.o' -delete