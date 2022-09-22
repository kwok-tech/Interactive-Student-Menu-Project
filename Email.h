/*********************************************************
* file name: Email.h
* programmer name: David Luo
* date created: 2020/02/04
* date of last revision: 2020/02/05
* details of the revision: N/A
* short description: Class which includes address & type (university, personal)
**********************************************************/

#pragma once
#ifndef EMAIL_H
#define EMAIL_H
#include <string>
using namespace std;

namespace team3Luo {
    class Email {
    private:
        string address, type;
    public:
		Email();
		Email(string, string); //constructor
		Email(const Email& p); //copy constructor
        //mutators
        void setAddress(string);
        void setType(string);
        //accessors
        string getAddress() const;
        string getType() const;
    };
}
#endif