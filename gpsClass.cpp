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
  this->mtype=none;
  this->states = look$;
  this->checkSum=" ";
  this->msg=" ";
  this->buffer = " ";
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
//  cout << "find char "<<this->buffer<<endl;
//  this->pls=x;
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
    //  cout << checkType(x) << endl;
      /*if(checkType(x))
        cout << "Message Type: " << this->msg << endl;
      this->msg=""; */
      //this is to check if there is an ast and checksum
      if(x=='\n'){
        this->states = look$;
        cout << "Message data: "<<this->buffer<<endl;
        this->buffer="";
        //call checksum

      }
    }
    else{//print the message data when the end is reached and reset the buffer
      cout << "Message data: "<<this->buffer<<endl;
      calcCheckSum();
      this->buffer="";
    }
  }/*
  if(x=='\n'&&this->states==found$){
    this->states=look$;
    cout << "Message checksum: " << this->checkSum << endl;
  } */
  //change the state to check sum
  if(this->states == found$ && x == '*'){
    this->states = foundCS;
  }
  /*
  if(this->states==found$&&x=='\n'){
    cout << "Message checksum: " << this->checkSum << endl;
    this->states=look$;
    this->checkSum="";
  } */
  //start filling the checksum when past the asterisk
  if(this->states==foundCS&&x!='*'){
    //fill until new line is achieved
    if(x!='\n'){
      this->checkSum+=x;
    }
    //print the check sum and confirm that it is correct
    else{
      //call calcChecksum
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
//  Uses conditional logic to determine the method type
bool gpsClass::checkType(char a){
//  bool g =false;
message_type test=none;
//cout << none << endl;
  if(a=='G'&&this->mtype==none){
    this->mtype = foundG1;
    this->msg += a;
    cout<<"char: " << a <<endl;

    //g =true;
    cout << "state: none " << this->mtype<<endl;
  }
  else{
      this->states = look$;
      return false;
    }
    cout << "state: " << this->mtype<<endl;
  if(this->mtype== foundG1 && a == 'P'){
    this->mtype = foundP;
    this->msg += a;
    cout << "state for foundG1 and a == P " << this->mtype<<endl;

  }
  else {
    this->states = look$;
    return false;
   }
   if(this->mtype==foundP && a =='G'){
     this->mtype=foundG2;
     this->msg+=a;
   }
   else if(this->mtype==foundP && a =='R'){
     this->mtype=foundR;
     this->msg+=a;
   }
   else{
     this->states = look$;
     return false;
   }
   if(this->mtype==foundG2 && a=='G'){
     this->mtype==foundG3;
     this->msg+=a;
   }
   else if(this->mtype==foundG2 && a=='S'){
     this->mtype=foundS;
     this->msg+=a;
   }
   else if(this->mtype==foundR&&a=='M'){
     this->mtype=foundM;
     this->msg+=a;
   }
   else{
     this->states = look$;
     return false;
   }
   if(this->mtype==foundG3 && a=='A'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return true;
   }
   else if(this->mtype==foundS && a=='V'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return true;
   }
   else if(this->mtype==foundS && a=='A'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return true;
   }
   else if(this->mtype==foundM && a == 'C'){
     this->mtype= none;
     this->msg+=a;
     this->states=look$;
     return true;
   }
   else{
     this->states=look$;
     return false;
   }
}

void gpsClass::calcCheckSum(){
  //int temp = 0;
  cout <<"buffer: " << this->buffer << endl;
  for(int i =0; i< this->buffer.length();i++){
    this->check^=buffer[i];
    //cout << i << endl;
  }
//  return temp;
}

gpsClass::~gpsClass(){
}
