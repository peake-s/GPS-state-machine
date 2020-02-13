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
  this->check =0;
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
  //int count =0;

//determine the states: 1st check if we are looking for the money sign and if the money
// sign is found change the state to found $
  if(this->states == look$ && x=='$'){
    this->states = found$;
  }
  //if the machine has found a money sign and the current char is not a money sign
  // exclude the money sign in the buffer as is unnecessary to print and calc check sum
  /*if(this->states == found$ && x!='$'&&this->count<5){
    //cout << "char x in count if: " << x << endl;
    //cout << "count: " << this->count<<endl;
      cout << "count: " <<this->count<<endl;
      cout << "char in: " << x << endl;
      this->count++;
      checkType(x);
      if(this->count==5){
      //  cout << "Message Type: " << this->msg << endl;
        this->msg="";
        this->count=0;
      }
    //cout << "char x in count if: " << x << endl;
  //  cout << "count: " << this->count << endl;

  }
  /*
  else if(this->count==5){
    cout << "enter else"<<endl;
    //cout << "count: " <<this->count<<endl;
    if(this->count==5){
      cout << "Message Type: " << this->msg << endl;
      this->msg="";
    }
  } */
  bool p=true;

  if(this->states == found$ && x!='$'){
    //add characters to the buffer before the asterisk
    if(x!='*'){
      this->buffer+=x;

    //cout << "char x out count if: " << x << endl;

    if(count<5){
      //cout << "char x in count if: " << x << endl;
      //cout << "count: " << this->count<<endl;
      checkType(x);
      //cout << "char x in count if: " << x << endl;
    }

      /*
      if(count==4){
        cout << "Message Type: " << this->msg << endl;
        this->msg="";
        this->count=0;

      } */
      this->count++;
      if(this->count==5){
        cout << "this->message: " << this->msg <<endl;
        this->count=0;
        p=false;
        //cout << "count: " <<this->count <<endl;
        this->msg = "";
      }
    //  cout << "count: " <<this->count<<endl;
    /*
    if(this->count==0&&p==false){
      cout << "Message Type: " << this->msg << endl;
      this->msg = "";
    } */
      if(x=='\n'){
        this->states = look$;
        //cout << "Message data: "<<this->buffer<<endl;
        this->buffer="";
        //call checksum

      }
    //  cout << "count in if: " << this->count << endl;
    //  cout << "Message data: "<<this->buffer<<endl;

    }
    else{//print the message data when the end is reached and reset the buffer
      /*cout << "count " << this->count<< endl;
      cout << "p" << p<<endl; */
    /*  if(this->count==0&&p==false){
        cout << "Message Type: " << this->msg << endl;
        p=true;
        this->msg = "";
      } */
      //cout << "Message Type: " << this->msg << endl;
      //cout << "Message data: "<<this->buffer<<endl;
      calcCheckSum();
      this->buffer="";
      //this->msg = "";
      //this->count=0;
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
    //  cout << "Message checksum: " << this->checkSum << endl;
      this->states=look$;
    //  cout << "Calculated Checksum: " << hex<< this->check << endl;
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
void gpsClass::checkType(char a){
//  bool g =false;
message_type test=none;
  if(count>4)
    return;
  if(a=='G'&&this->mtype==none){
    this->mtype = foundG1;
    this->msg += a;
    return;
  }
  //cout << "msg: " << this->msg<<endl;
  if(this->mtype==none&&a!='G'){
      this->states = look$;
  //    return false;
      return;
    }

  if(this->mtype== foundG1 && a == 'P'){
    this->mtype = foundP;
    this->msg += a;
    //cout << "state for foundG1 and a == P " << this->mtype<<endl;
    return;
  }
  else if(this->mtype== foundG1 && a != 'P'){
    this->states = look$;
  //  return false;
      return;
   }
   /*
   cout << "state after foundG: " << this->mtype<<endl;
   cout << "input char? " << a<<endl;
   cout << "message1: " <<this->msg<<endl; */
   if(this->mtype==foundP && a =='G'){
     this->mtype=foundG2;
     this->msg+=a;
  //   cout << "foundP && a == G" <<endl;
     return;
   }
   else if(this->mtype==foundP && a =='R'){
     this->mtype=foundR;
     this->msg+=a;
     return;
   }
   else if(this->mtype==foundP && (a!='R'||a!='G')){
     this->states = look$;
    // return false;
        return;
   }
  // cout << "state, 6=R: " << this->mtype << endl;
   if(this->mtype==foundG2 && a=='G'){
     this->mtype=foundG3;
     this->msg+=a;
     return;
   }
   else if(this->mtype==foundG2 && a=='S'){
     //cout << "S" << endl;
     this->mtype=foundS;
     this->msg+=a;
     return;
   }
   else if(this->mtype==foundR&&a=='M'){
  //   cout << "R" << endl;
     this->mtype=foundM;
     this->msg+=a;
     return;
   }
   else if((this->mtype==foundR||this->mtype==foundG2)&&(a!='G'||a!='S'||a!='M')){
     this->states = look$;
     return;
     //return false;
   }

   //cout << "message after foundP: " <<this->msg<<endl;
   //cout << "char in: " << a << endl;
   if(this->mtype==foundG3 && a=='A'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return;
     //return true;
   }
     //cout << "Message Type: " << this->msg << endl;
   /*
   else if(this->mtype==foundS && a=='V'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return;
     //return true;
   }
   else if(this->mtype==foundS && a=='A'){
     this->mtype=none;
     this->msg+=a;
     this->states=look$;
     return;
     //return true;
   }
   else if(this->mtype==foundM && a == 'C'){
     this->mtype= none;
     this->msg+=a;
     //cout << "enter c" <<endl;
     this->states=look$;
     return;
     //return true;
   }
   else{
     this->states=look$;
     return;
    // return false;
  } */
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
  for(int i =0; i< this->buffer.length();i++){
    this->check^=buffer[i];
  }
}

gpsClass::~gpsClass(){
}
