Lab2: main.o HashTable.o
	g++ -g -std=c++11 main.o HashTable.o -o Lab2
main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp HashTable.h
	g++ -g -std=c++11 -c main.cpp 
HashTable.o: HashTable.cpp DoubleLinkedList.h
	g++ -g -std=c++11 -c HashTable.cpp
clean:
	rm *.o Lab2
	echo clean done 

