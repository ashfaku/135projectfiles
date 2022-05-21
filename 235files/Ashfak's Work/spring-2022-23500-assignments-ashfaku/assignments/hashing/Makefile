main: main.o OList.o Node.o Person.o Dictionary.o
	g++ -o main main.o OList.o Node.o Person.o Dictionary.o

tests: tests.o OList.o Node.o Person.o Dictionary.o
	g++ -o tests tests.o OList.o Node.o Person.o Dictionary.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp OList.h
	g++ -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -c OList.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Node.o: Node.cpp Node.h Person.h
	g++ -c Node.cpp

clean:
	rm -f *.o
