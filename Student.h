/*********************************************************
*  file name: Student.h
*  programmer name: Jack Kwok
*  date created:2/4/2020
*  date of last revision:2/4/2020
*  details of the revision: None
*  short description: The Student Class is a class that stores information about a student.
**********************************************************/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector> 
#include "MailingAddress.h"
#include "Email.h"
#include "PhoneNumber.h"
#include "Date.h"
#include "Semester.h"
#include "CourseNode.h"
using namespace std;
using namespace team3Belashov;
using namespace team3Distler;
using namespace team3Luo;

namespace team3Kwok
{
	
	class Student {
		//need a used var
		private:
			string firstName;
			string middleName;
			string lastName;
			int studentID;
			string userIDNum;
			MailingAddress stuAddress;
			Date birthDate;
			Date acceptDate;
			Semester startSemester;
			string intendedMajor;
			string intendedMinor;
			string status;
		public:
			//vectors for email and phone numbers
			vector <Email> emailArr;
			vector <PhoneNumber> phoneArr;
			//linked list of courses
			CourseNode* courseList = NULL;
			//Constructors
			Student();
			Student(string, string, string, int, string, MailingAddress, Date, Date, Semester, string, string, string);
			//Copy Constructor
			Student(const Student& s);
			//Function to get all student's data and return as a string
			string getAllStudentData() const;
			string getCourseList(CourseNode* head_ptr) const;
			//functions that gets some student's data and return as a string (Lukas)
			string getSomeStudentData() const;
			string getCourseListPartial(CourseNode* head_ptr) const;
			//Mutator Functions
			void setName(string, string, string);
			void setFirstName(string);
			void setMiddleName(string);
			void setLastName(string);
			void setStuID(int);
			void setUserID(string);
			void setStuAddress(MailingAddress);
			void setBirthDate(int m, int d, int y);
			void setAcceptanceDate(int m, int d, int y);
			void setStartSemester(Semester);
			void setIntendedMajor(string);
			void setIntendedMinor(string);
			void setStatus(string);
			//Accessor Functions
			string getFirstName() const;
			string getMiddleName() const;
			string getLastName() const;
			int getStuID() const;
			string getUserID() const;
			MailingAddress getStuAddress() const;
			Date getBirthDate() const;
			Date getAcceptanceDate() const;
			Semester getStartSemester() const;
			string getIntendedMajor() const;
			string getIntendedMinor() const;
			string getStatus() const;
			//insert functions for the vectors
			void insertEmail(Email);
			void insertPhoneNum(PhoneNumber);
			//file
			void writeFile(ofstream&);
			void readFile(ifstream&);
	};
}
#endif