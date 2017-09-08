Lab7: main.o MinMaxHeap.o
	g++ -g -std=c++11 main.o MinMaxHeap.o -o Lab7
main.o: main.cpp MinMaxHeap.h
	g++ -g -std=c++11 -c main.cpp 
MinMaxHeap.o: MinMaxHeap.cpp
	g++ -g -std=c++11 -c MinMaxHeap.cpp
clean:
	rm *.o Lab7
	echo clean done 

