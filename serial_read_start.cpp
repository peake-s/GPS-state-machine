//******************************************************************
// Program #: Reading from serial port
//
// Programmer: Matthew Gelber/Robert Klenke
//
// Due Date: NA
//
// EGRE 347, Fall 2020       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: C++ example for reading information from serial port one byte at a time
//
// Input: command line argument of the desired serial port
//
// Output: none
//
//******************************************************************
using namespace std;

#include <iostream>
#include <string>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "gpsClass.h"


int main(int argc, char *argv[])
{
	//unsigned char read_buff;
	char read_buff;
	gpsClass sm = gpsClass();
	cout << argv[1] << endl;
	int sp = open(argv[1], O_RDONLY | O_NOCTTY | O_NDELAY);	//opens the serial port inputted as argument as read only

	if(sp < 0)
		cout << "unable to open port " << argv[1] << endl;
	else
		cout << "port successfully opened" << endl;

	while(1){
		int n = read(sp, &read_buff, sizeof(read_buff));
			if(n > 0){
				//printf("Read byte:%c = %d\n", read_buff, read_buff);
				sm.find(read_buff);
				sm.print();

				//printf("Read byte:%c = %d\n", read_buff, read_buff);

			}
		}
	close(sp);
}
