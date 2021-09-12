CXX:= g++
CXXFLAGS:= -std=c++17 -Wall -Wextra -Wpedantic

main: driver.cpp FPKState.hpp StateBase.hpp SuperQueenState.hpp driver.hpp
	$(CXX) -o driver.o driver.cpp $(CXXFLAGS) -lboost_program_options

WO_Boost: driver.cpp FPKState.hpp StateBase.hpp SuperQueenState.hpp driver.hpp
	$(CXX) -o driver.o driver.cpp $(CXXFLAGS) -lboost_program_options -DNO_INCLUDE_BOOST

clean:
	find . -name '*.o' -delete