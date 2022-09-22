/*********************************************************
*  file name: Date.cpp
*  programmer name: Lukas Belashov
*  date created:2/18/2020
*  date of last revision:2/18/2020
*  details of the revision: None
*  short description: The Date Class is a class that stores information about a date.
**********************************************************/
#include <iostream>
#include "Date.h"
using namespace std;
namespace team3Belashov
{	//date function
	Date::Date(int m, int d, int y)
	{
		month = m;
		day = d;
		year = y;
	}
	//copy function
	Date::Date(const Date& s)
	{
		month = s.month;
		day = s.day;
		year = s.year;
	}

	//setMonth function
	void Date::setMonth(int m)
	{
		month = m;
	}
	//setDay function
	void Date::setDay(int d)
	{
		day = d;
	}
	//setYear Function
	void Date::setYear(int y)
	{
		year = y;
	}
	//getMonth Function
	int Date::getMonth() const
	{
		return month;
	}
	//getDay Function
	int Date::getDay() const
	{
		return day;
	}
	//getYear Function
	int Date::getYear() const
	{
		return year;
	}

}