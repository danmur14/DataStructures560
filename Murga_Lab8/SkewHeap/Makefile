Lab8: main.o SkewHeap.o
	g++ -g -std=c++11 main.o SkewHeap.o -o Lab8
main.o: main.cpp SkewHeap.h
	g++ -g -std=c++11 -c main.cpp 
SkewHeap.o: SkewHeap.cpp
	g++ -g -std=c++11 -c SkewHeap.cpp
clean:
	rm *.o Lab8
	echo clean done 

