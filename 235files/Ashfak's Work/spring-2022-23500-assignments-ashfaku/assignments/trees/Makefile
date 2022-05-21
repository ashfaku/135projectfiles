
main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

tests: tests.o Node.o BSTree.o
	g++ -o tests tests.o Node.o BSTree.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp Node.h
	g++ -c main.cpp


BSTree.o: BSTree.cpp BSTree.h
	g++ -c BSTree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
