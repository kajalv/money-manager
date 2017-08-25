all:
	@g++ -o bin/main.o -c src/main.cpp
	@g++ -o bin/MoneyManager bin/*.o

tests: all
	@./bin/MoneyManager

clean:
	@rm -rf bin/*.o bin/MoneyManager
