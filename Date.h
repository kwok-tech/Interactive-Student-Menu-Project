/*********************************************************
*  file name: Date.h
*  programmer name: Lukas Belashov
*  date created:2/4/2020
*  date of last revision:2/4/2020
*  details of the revision: None
*  short description: The Date Class is a class that stores information about a date.
**********************************************************/
#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
namespace team3Belashov
{
	class Date
	{
	private:
		int month, day, year;
	public:
		Date(const Date& s);
		Date(int month = 1, int day = 1, int year = 1998);//construtor
		//mutator functions
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		//accessor functions
		int getMonth() const;
		int getDay() const;
		int getYear() const;

	};
}
#endif