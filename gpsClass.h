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
#include <string>

enum message_type{none,foundG, foundP, foundS, foundR, foundM,foundV};
enum state{look$, found$, foundast, foundCS};
/*
int checksum = 0;
for (inti = 0; i < stringToCalculateTheChecksumOver.length; i++){
c =
checksum ^= Convert.ToByte(sentence[i]);} */
class gpsClass{
  private:
    string type[4]={"GPGSA", "GPGGA", "GPRMC", "GPGSV"};
    int count;
    char pls;
    state states;
    string buffer;
    string msg;
    message_type mtype;
    string checkSum;
  public:
    gpsClass();
    ~gpsClass();
    //checks if it is at the beginning
    void find(char x);
    string fillBuffer(char a);
    bool calcChecksum();
    bool checkType(char a);
    bool checkGPGSA(char a);
    bool checkGPGGA(char a);
    bool checkGPRMC(char a);
    bool checkGPGSV(char a);

};
