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
    if(x!='*'){
      this->buffer+=x;
      /*s
      if(checkType(x))
        cout << "Message Type: " << this->msg << endl;
      this->msg=""; */
    }
    else{
      cout << "Message data: "<<this->buffer<<endl;
      this->buffer="";
    }
  }/*
  if(x=='\n'&&this->states==found$){
    this->states=look$;
    cout << "Message checksum: " << this->checkSum << endl;
  } */
  if(this->states == found$ && x == '*'){
    this->states = foundCS;
  }
  /*
  if(this->states==found$&&x=='\n'){
    cout << "Message checksum: " << this->checkSum << endl;
    this->states=look$;
    this->checkSum="";
  } */
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
//  bool g =false;
cout<<"char: " << a <<endl;
  if(a=='G'&&this->mtype==none){
    this->mtype = foundG1;
    this->msg += a;
    //g =true;
  }
  else{
      this->states = look$;
      return false;
    }
  if(this->mtype== foundG1 && a == 'P'){
    this->mtype = foundP;
    this->msg += a;
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



gpsClass::~gpsClass(){
}
