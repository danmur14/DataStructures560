Lab4: main.o HashTable.o HashTableQD.o
	g++ -g -std=c++11 main.o HashTable.o HashTableQD.o -o Lab4
main.o: main.cpp Node.h Node.hpp HashTable.h HashTableQD.h Timer.cpp
	g++ -g -std=c++11 -c main.cpp 
HashTable.o: HashTable.cpp Node.h
	g++ -g -std=c++11 -c HashTable.cpp
HashTableQD.o: HashTableQD.cpp NodeQD.h
	g++ -g -std=c++11 -c HashTableQD.cpp
clean:
	rm *.o Lab4
	echo clean done 

