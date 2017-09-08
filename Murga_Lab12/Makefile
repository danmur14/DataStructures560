Lab12: main.o Dijkstra.o 
	g++ -g -std=c++11 main.o Dijkstra.o -o Lab12
main.o: main.cpp Dijkstra.h
	g++ -g -std=c++11 -c main.cpp 
Dijkstra.o: Dijkstra.cpp
	g++ -g -std=c++11 -c Dijkstra.cpp
clean:
	rm *.o Lab12
	echo clean done 

