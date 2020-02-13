//******************************************************************
// Program #: Reading from serial port
//
// Programmer: Samuel Peake
//
// Due Date: 4/5/2021
//
// EGRE 347, Spring 2021       Instructor: Robert Klenke
//
// Assignment: HW 5
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Main for  reading information from serial port one byte at a time
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
	//calling instanc eof gpsClass and calling the constructor
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
				//calling the find function on each pased byte and letting the find function do the rest
				sm.find(read_buff);
				//printf("Read byte:%c = %d\n", read_buff, read_buff);

			}
		}
	close(sp);
}
