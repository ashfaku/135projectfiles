main: main.o
	g++ -o main main.o

tests: tests.o
	g++ -o tests tests.o

main.o: main.cpp myvector.h myvector.cxx
	g++ -c main.cpp -std=c++11

tests.o: tests.cpp doctest.h myvector.h myvector.cxx
	g++ -c tests.cpp -std=c++11

clean:
	rm -f *.o
