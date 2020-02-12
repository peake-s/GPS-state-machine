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


enum message_type{none,foundG1, foundG2,foundG3,foundP, foundS, foundR, foundM,foundV,foundA};
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
    unsigned char calculate;
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
    void calcChecksum();
    bool checkType(char a);
    bool checkGPG(char a);
    bool checkGPGSA(char s);
    bool checkGPGGA(char a);
    bool checkGPRMC(char a);
    bool checkGPGSV(char s);
    bool checkGPGSAV(char s);


};
/*
//GPGGA,GPGSA, GPGSV, and GPRMC
bool gpsClass::checkGPG(char a){
  //bool f = false;
  if(a=='G'){
    this->mtype = foundG;
    this->msg+=a;
    return checkGPGGA(a);
  }
  else return false;
  if(a=='S'&&this->mtype==foundG){
    this->msg+=a;
    this->mtype =foundS;
    return checkGPGSA(a);
  }
  else return false;
  if(a=='A'&& this->mtype == foundG){
    this->msg+=a;
    this->mtype=none;
    return true;
  }
  else return false;
}
bool gpsClass::checkGPGSV(char s){
  return true;
}
bool gpsClass::checkGPGGA(char a){
  return true;
}
bool gpsClass::checkGPGSAV(char s){
  if(this->mtype=foundS && s==)
    ;
  return true;
}
bool gpsClass::checkGPRMC(char a){
  return true;
}
*/
