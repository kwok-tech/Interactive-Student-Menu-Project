/*********************************************************
*  file name: Semester.h
*  programmer name: Nicky Distler
*  date created:2/9/2020
*  date of last revision:2/4/2020
*  details of the revision: None
*  short description: defines the Semester class and its members
**********************************************************/
#include <string>
#ifndef SEMESTER_H
#define SEMESTER_H
using namespace std;
namespace team3Distler {
	class Semester {

	private:
		std::string season;
		int year;
	public:
		Semester();
		Semester(string, int);
		Semester(const Semester& s);
		void setSeason(string);
		void setYear(int);
		string getSeason() const;
		int getYear() const;
	};

};
	
#endif 

