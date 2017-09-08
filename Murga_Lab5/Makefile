Lab5: main.o BinarySearchTree.o
	g++ -g -std=c++11 main.o BinarySearchTree.o -o Lab5
main.o: main.cpp Node.h Node.hpp BinarySearchTree.h
	g++ -g -std=c++11 -c main.cpp 
BinarySearchTree.o: BinarySearchTree.cpp Node.h queue.cpp
	g++ -g -std=c++11 -c BinarySearchTree.cpp
clean:
	rm *.o Lab5
	echo clean done 

