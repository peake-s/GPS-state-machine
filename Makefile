CXX = g++

prog1 : serial_read_start.cpp gpsClass.cpp
	$(CXX)  serial_read_start.cpp gpsClass.cpp -o prog1
gpsClass.o: gpsClass.h gpsClass.cpp
	$(CXX) -c gpsClass.cpp
clean :
	rm prog1
	rm *.o
