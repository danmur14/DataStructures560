Lab3: main.o HashTable.o
	g++ -g -std=c++11 main.o HashTable.o -o Lab3
main.o: main.cpp Node.h Node.hpp HashTable.h
	g++ -g -std=c++11 -c main.cpp 
HashTable.o: HashTable.cpp Node.h
	g++ -g -std=c++11 -c HashTable.cpp
clean:
	rm *.o Lab3
	echo clean done 

