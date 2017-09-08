Lab9: main.o BinomialQueue.o
	g++ -g -std=c++11 main.o BinomialQueue.o -o Lab9
main.o: main.cpp BinomialQueue.h
	g++ -g -std=c++11 -c main.cpp 
BinomialQueue.o: BinomialQueue.cpp
	g++ -g -std=c++11 -c BinomialQueue.cpp
clean:
	rm *.o Lab9
	echo clean done 

