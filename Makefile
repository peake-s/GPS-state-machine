CXX = g++

prog1 : hw5main.o gpsClass.o
	$(CXX)  hw5main.o gpsClass.o -o prog1
main.o: hw5main.cpp gpsClass.h
	$(CXX) -c hw5main.cpp
gpsClass.o: gpsClass.h gpsClass.cpp
	$(CXX) -c gpsClass.cpp
clean :
	rm prog*
	rm *.o
