/********************************************************
* file name : PhoneNumber.h
* programmer name : David Luo
* date created : 2020/02/04
* date of last revision : 2020/02/05
* details of the revision : N/A
* short description : Class which includes phone number & type(home, mobile)
* *********************************************************/

#pragma once
#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>
using namespace std;

namespace team3Luo {
    class PhoneNumber {
    private:
        string num;
        string type;
    public:
		PhoneNumber();
		PhoneNumber(string, string); //constructor
        PhoneNumber(const PhoneNumber& p); //copy constructor
        //mutators
        void setNum(string);
        void setType(string);
        //accessors
        string getNum() const;
        string getType() const;
    };
}
#endif