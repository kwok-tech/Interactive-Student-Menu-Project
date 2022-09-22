/*********************************************************
*  file name: MailingAddress.h
*  programmer name: Lukas Belashov
*  date created:2/4/2020
*  date of last revision:2/4/2020
*  details of the revision: None
*  short description: The MailingAddress Class is a class that stores information about a student's mailing address.
**********************************************************/
#ifndef MAILINGADDRESS_H
#define MAILINGADDRESS_H
#include <string>
using namespace std;
namespace team3Belashov
{

	class MailingAddress
	{
	private:
		string street;
		string city;
		string state;
		int zip;
		string type;
	public:
		//constructor
		MailingAddress(string street = "unknown street", string city = "unknown city", string state = "PA", int zip = 00000, string type = "local");
		MailingAddress(const MailingAddress& s);
		//mutator functions
		void setStreet(string street);
		void setCity(string city);
		void setState(string state);
		void setZip(int zip);
		void setType(string type);
		//accessor functions
		string getStreet() const;
		string getCity() const;
		string getState() const;
		int getZip() const;
		string getType() const;
	};
}
#endif 