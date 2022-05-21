main: main.o OList.o Node.o
	g++ -o main main.o OList.o Node.o

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp OList.h
	g++ -c main.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
