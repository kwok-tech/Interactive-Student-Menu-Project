/********************************************************
* file name : PhoneNumber.h
* programmer name : David Luo
* date created : 2020/02/18
* date of last revision : 2020/02/18
* details of the revision : N/A
* short description : Implementation for email address
* *********************************************************/

#include "Email.h"
using namespace std;

namespace team3Luo {
    Email::Email() {
        address = "abc1234@psu.edu";
        type = "Univeristy";
    }
    Email::Email(string caddress, string ctype) {
        address = caddress;
        type = ctype;
    }
    Email::Email(const Email& p) {
        address = p.address;
        type = p.type;
    }
    void Email::setAddress(string caddress) {
        address = caddress;
    }
    void Email::setType(string ctype) {
        type = ctype;
    }
    string Email::getAddress()  const {
        return address;
    }
    string Email::getType()  const {
        return type;
    }
}