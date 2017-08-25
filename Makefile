CXX=@g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

all: runner prog utilities
	$(CXX) $(CXXFLAGS) -o bin/MoneyManager bin/*.o

runner:
	$(CXX) $(CXXFLAGS) -o bin/main.o -c src/main.cpp

prog:
	$(CXX) $(CXXFLAGS) -o bin/CommandParser.o -c src/CommandParser.cpp
	$(CXX) $(CXXFLAGS) -o bin/Executor.o -c src/Executor.cpp

utilities:
	$(CXX) $(CXXFLAGS) -o bin/StringUtils.o -c src/Utilities/StringUtils.cpp

clean:
	@rm -rf bin/*.o bin/MoneyManager
