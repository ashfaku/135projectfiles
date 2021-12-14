main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o

profile.o: profile.cpp profile.h
	g++ -c profile.cpp

network.o: network.cpp network.h
	g++ --std=c++11 -c network.cpp

main.o: main.cpp
	g++ -c main.cpp

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

clean:
	rm -f main.o profile.o network.o tests.o
