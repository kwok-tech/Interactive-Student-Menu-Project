/********************************************************
* file name : PhoneNumber.h
* programmer name : David Luo
* date created : 2020/02/18
* date of last revision : 2020/02/18
* details of the revision : N/A
* short description : Implementation for phone number
* *********************************************************/

#include "PhoneNumber.h"
using namespace std;

namespace team3Luo {
    PhoneNumber::PhoneNumber() {
        num = "(123)-456-7890";
        type = "n/a";
    }
    PhoneNumber::PhoneNumber(string cnum, string ctype) {
        num = cnum;
        type = ctype;
    }
    PhoneNumber::PhoneNumber(const PhoneNumber& p) {
        num = p.num;
        type = p.type;
    }
    void PhoneNumber::setNum(string cnum) {
        num = cnum;
    }
    void PhoneNumber::setType(string ctype) {
        type = ctype;
    }
    string PhoneNumber::getNum()  const {
        return num;
    }
    string PhoneNumber::getType()  const {
        return type;
    }
}