/*********************************************************
*  file name: MailingAddress.cpp
*  programmer name: Lukas Belashov
*  date created:2/18/2020
*  date of last revision:2/18/2020
*  details of the revision: None
*  short description: The MailingAddress Class is a class that stores information about a student's mailing address.
**********************************************************/
#include <iostream>
#include "MailingAddress.h"
using namespace std;
namespace team3Belashov
{	//MailingAddress Function
	MailingAddress::MailingAddress(string str, string ci, string stat, int zi, string typ)
	{
		street = str;
		city = ci;
		state = stat;
		zip = zi;
		type = typ;


	}
	//copy function
	MailingAddress::MailingAddress(const MailingAddress& s)
	{
		street = s.street;
		city = s.city;
		state = s.state;
		zip = s.zip;
		type = s.type;

	}
	//setStreet Function
	void MailingAddress::setStreet(string str)
	{
		street = str;
	}
	//setCity Function
	void MailingAddress::setCity(string ci)
	{
		city = ci;
	}
	//setState Function
	void MailingAddress::setState(string stat)
	{
		state = stat;
	}
	//setZip Function
	void MailingAddress::setZip(int zi)
	{
		zip = zi;
	}
	//setType Function
	void MailingAddress::setType(string typ)
	{
		type = typ;
	}
	//setStreet Function
	string MailingAddress::getStreet() const
	{
		return street;
	}
	//getCity Function
	string MailingAddress::getCity() const
	{
		return city;
	}
	//getState Function
	string MailingAddress::getState() const
	{
		return state;
	}
	//getZip Function
	int MailingAddress::getZip() const
	{
		return zip;
	}
	//getType Function
	string MailingAddress::getType() const
	{
		return type;
	}

}