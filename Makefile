p8: main.o Graph.o
	g++ -o p8 main.o Graph.o

main.o: main.cpp Node.h Graph.h
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

clean:
	rm -f p8 *.o *.~