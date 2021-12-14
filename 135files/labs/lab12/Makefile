main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp
	g++ -c main.cpp

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

clean:
	rm -f *.o
