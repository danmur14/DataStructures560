Lab6: main.o MinHeap.o
	g++ -g -std=c++11 main.o MinHeap.o -o Lab6
Test: test.o MinHeap.o BinarySearchTree.o 
	g++ -g -std=c++11 test.o MinHeap.o BinarySearchTree.o -o Test
test.o: test.cpp MinHeap.h Timer.cpp
	g++ -g -std=c++11 -c test.cpp 
main.o: main.cpp MinHeap.h
	g++ -g -std=c++11 -c main.cpp 
MinHeap.o: MinHeap.cpp
	g++ -g -std=c++11 -c MinHeap.cpp
BinarySearchTree.o: BinarySearchTree.cpp Node.h queue.cpp
	g++ -g -std=c++11 -c BinarySearchTree.cpp
clean:
	rm *.o Lab6
	echo clean done 

