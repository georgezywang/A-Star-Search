CXX:= g++
CXXFLAGS:= -std=c++17 -Wall -Wextra -Wpedantic

main: driver.cpp FPKState.hpp StateBase.hpp SuperQueenState.hpp driver.hpp
	$(CXX) -o driver.o driver.cpp $(CXXFLAGS) -lboost_program_options

WO_Boost: driver.cpp FPKState.hpp StateBase.hpp SuperQueenState.hpp driver.hpp
	$(CXX) -o driver.o driver.cpp $(CXXFLAGS) -DNO_INCLUDE_BOOST

test:
	make main
	./driver.o --filePath Tests/input_FPK_1.txt --pSet 1
	./driver.o --filePath "Tests/SQP_1_(size_18).txt" --pSet 2

	make WO_Boost
	./driver.o --filePath Tests/input_FPK_1.txt --pSet 1
	./driver.o --filePath "Tests/SQP_1_(size_18).txt" --pSet 2

clean:
	find . -name '*.o' -delete