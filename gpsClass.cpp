//-----------------------------------------------------------------------
// File : DSI.h
//
// Programmer: Samuel Peake
//
// Program #: homework 05
//
// Due Date: 4/5/2021
//
// Course: EGRE 347, Spring 2020
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: implementation of gps state machine
//
//-----------------------------------------------------------------------
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include "gpsClass.h"

//gpsClass()- constructor
//Summary:
// gpsClass constructor initializes buffer, message, and states the
//  to their checking state
//
//parameters: none, initializes private variables
//
// return value: none, but initializes the private variables
//
// Description:
//
//  Uses standard c++ class features to implement a constructor
gpsClass::gpsClass(){
  this->count = 0;
  this->states = look$;
  this->checkSum="";
  this->buffer = "";
  this->check =0;
  this->typeM = "";
}
//void find(char x)
//Summary:
// find is the main state machine and determines the state and what should be done as a
//  as a result of the previous state
//
//parameters: passed a char to determine what to do
//
// return value: none but prints necessary statements
//
// Description:
//
//  Uses conditional logic to guide the statemachine
void gpsClass::find(char x){
  char temp=x;
//determine the states: 1st check if we are looking for the money sign and if the money
// sign is found change the state to found $
  if(this->states == look$ && x=='$'){
    this->states = found$;
  }
  //if the machine has found a money sign and the current char is not a money sign
  // exclude the money sign in the buffer as is unnecessary to print and calc check sum
  if(this->states == found$ && x!='$'){
    //add characters to the buffer before the asterisk
    if(x!='*'){
      this->buffer+=x;
    if(count<5){
      this->typeM+=temp;
      this->count++;

    }
      if(x=='\n'){
        this->states = look$;
        this->buffer="";
      }
    }
    else{//print the message data when the end is reached and reset the buffer
      this->count=0;
      if(checkM()){
        cout << "Message Type: " << this->typeM << endl;
      cout << "Message data: "<<this->buffer<<endl;
      calcCheckSum();
    }
      else this->states=look$;
      this->buffer="";
      this->typeM = "";
    }
  }
  //change the state to check sum
  if(this->states == found$ && x == '*'){
    this->states = foundCS;
  }
  //start filling the checksum when past the asterisk
  if(this->states==foundCS&&x!='*'){
    //fill until new line is achieved
    if(x!='\n'){
      this->checkSum+=x;
    }
    //print the check sum and confirm that it is correct
    else{
      cout << "Message checksum: " << this->checkSum << endl;
      this->states=look$;
      cout << "Calculated Checksum: " << hex<< this->check << endl;
      this->checkSum="";
      this->check =0;
    }
  }

}
//bool checkType(char a)
//Summary:
// check type is a method set to determine the method type. It is called
//  within the statemachine to verify that the method type is valid
//parameters: passed a char to determine what to do
//
// return value: true if the character represents a message type
//  in the correct order, false otherwise
// Description:
//
//  compares the message type string to one of the valid types
bool gpsClass::checkM(){
  if(this->typeM=="GPGSA")
    return true;
  else if(this->typeM=="GPGGA")
    return true;
  else if(this->typeM=="GPRMC")
    return true;
  else if(this->typeM=="GPGSV")
    return true;
  else
    return false;
}

//void calcCheckSum()
//Summary:
// Calculates the checksum of the message to make sure that the given one is correct
//
//parameters: none, uses the buffer to calculate the check sum
//
// return value: none, but calculates the check sum that is to be printed
//
// Description:
//
//  uses the bit wise ^ xor bit wise operator to calculate the check sum
void gpsClass::calcCheckSum(){
  for(int i =0; i< this->buffer.length();i++)
    this->check^=buffer[i];
}

gpsClass::~gpsClass(){
}
