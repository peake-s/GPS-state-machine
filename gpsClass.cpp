//-----------------------------------------------------------------------
// File : DSI.h
//
// Programmer: Samuel Peake
//
// Program #: homework 02
//
// Due Date: 2/26/2021
//
// Course: EGRE 347, Spring 2020
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: header file for the dsi class, intializes all the methods and private variables
//
//-----------------------------------------------------------------------
using namespace std;
#include <iostream>
#include <string>
#include "gpsClass.h"

gpsClass::gpsClass(){
  this->count = 0;
  this->mtype=none;
  this->states = look$;
  this->checkSum=" ";
  this->msg=" ";
  this->buffer = " ";
}

void gpsClass::find(char x){
//  cout << "find char "<<this->buffer<<endl;
  this->pls=x;
  if(this->states == look$ && x=='$'){
    this->states = found$;
  }
  if(this->states == found$ && x!='$'){
    if(x!='*')
      this->buffer+=x;
    else{
      //call find message type
      //cout << "Message Type: " << this->msg << endl;
      cout << "Message data: "<<this->buffer<<endl;
      this->buffer="";
    }
  }
  if(this->states == found$ && x == '*'){
    this->states = foundCS;
  }
  if(this->states==foundCS&&x!='*'){
    if(x!='\n'){
      this->checkSum+=x;
    }
    else{
      //call calcChecksum
      cout << "Message checksum: " << this->checkSum << endl;
      this->states=look$;
      this->checkSum="";
    }
  }

}

bool gpsClass::checkType(char a){

  if(a=='G')
    this->mtype = foundG;
  else
      return false;

      return true;
  this->msg += a;
}

void gpsClass::print(){
//  if(this->states==found)
//    cout << "Message data: "<<this->buffer<<endl;
  //cout << "state" << this->states<<endl;
//  cout << "cs " << this->checkSum << endl;
}
gpsClass::~gpsClass(){
}
