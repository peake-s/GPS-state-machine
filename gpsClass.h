//-----------------------------------------------------------------------
// File : gpsClass.h
//
// Programmer: Samuel Peake
//
// Program #: homework 05
//
// Due Date: 3/29/2021
//
// Course: EGRE 347, Spring 2021
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: declaration of the gps class used to parse the input
//-----------------------------------------------------------------------
using namespace std;
//enums that store the state of the machine
enum state{look$, found$, foundast, foundCS};
//Description:
//	This class implements a state machine that parses through gps messages
//
// Data members:
//
//	Private data members for the buffer, check sum, and helper data members
//
//	Methods:
//
//	Public methods to find the state of the machine and act accordingly
class gpsClass{
  private:
    //used to store message type
    int count;
    //used to store calculated checkSum
    int check; 
    //used to store message type
    string typeM;
    //state of the machine
    state states;
    //prints buffer of each message
    string buffer;
    //stores the checkSun
    string checkSum;
  public:
    //constructor to initialize data members
    gpsClass();
    ~gpsClass();
    //main function which determines the state of the machine and acts accordingly
    void find(char x);
    //calculates the checksum
    void calcCheckSum();
    //checks if the message type is valid
    bool checkM();
};
