Test: test.o SkewHeap.o LeftistHeap.o
	g++ -g -std=c++11 test.o SkewHeap.o LeftistHeap.o -o Test
test.o: test.cpp SkewHeap/SkewHeap.h LeftistHeap/LeftistHeap.h Timer.cpp
	g++ -g -std=c++11 -c test.cpp
SkewHeap.o: SkewHeap/SkewHeap.cpp
	g++ -g -std=c++11 -c SkewHeap/SkewHeap.cpp
LeftistHeap.o: LeftistHeap/LeftistHeap.cpp
	g++ -g -std=c++11 -c LeftistHeap/LeftistHeap.cpp
clean:
	rm *.o Test
	echo clean done 

