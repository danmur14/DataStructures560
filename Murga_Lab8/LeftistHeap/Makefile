Lab8: main.o LeftistHeap.o
	g++ -g -std=c++11 main.o LeftistHeap.o -o Lab8
main.o: main.cpp LeftistHeap.h
	g++ -g -std=c++11 -c main.cpp 
LeftistHeap.o: LeftistHeap.cpp
	g++ -g -std=c++11 -c LeftistHeap.cpp
clean:
	rm *.o Lab8
	echo clean done 

