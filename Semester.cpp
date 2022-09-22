/*********************************************************
*  file name: Semester.cpp
*  programmer name: Nicky Distler
*  date created:2/9/2020
*  date of last revision:2/11/2020
*  details of the revision: None
*  short description: write the functions defined in Semester.h
**********************************************************/
#include <iostream>
#include <string>
#include "Semester.h"
using namespace std;

namespace team3Distler {
	Semester::Semester() {
		season = "Fall";
		year = 2000;
	}

	Semester::Semester(string constructSeason, int constructYear) {
		season = constructSeason;
		year = constructYear;
	}
	Semester::Semester(const Semester& s) {
		season = s.season;
		year = s.year;
	}
	void Semester::setSeason(string userSeason) {
		season = userSeason;
	}
	void Semester::setYear(int userYear) {
		year = userYear;
	}
	string Semester::getSeason()  const {
		return season;
	}
	int Semester::getYear() const {
		return year;
	}
}