main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

main.o: main.cpp funcs.h
	g++ -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h
	g++ -c sample.cpp

imageio.o: imageio.cpp imageio.h
	g++ -c imageio.cpp

clean:
	rm -f sample.o imageio.o main.o funcs.o
