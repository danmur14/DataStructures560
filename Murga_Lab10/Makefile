Lab10: main.o MST.o DS.o
	g++ -g -std=c++11 main.o MST.o DS.o -o Lab10
main.o: main.cpp MST.h
	g++ -g -std=c++11 -c main.cpp 
MST.o: MST.cpp DS.cpp
	g++ -g -std=c++11 -c MST.cpp
DS.o: DS.cpp
	g++ -g -std=c++11 -c DS.cpp
clean:
	rm *.o Lab10
	echo clean done 

