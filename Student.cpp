/*********************************************************
*  file name: Student.cpp
*  programmer name: Jack Kwok
*  date created:2/5/2020
*  date of last revision:2/5/2020
*  details of the revision: None
*  short description: This implementation file writes the functions for the Student class.
**********************************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;
using namespace team3Belashov;
using namespace team3Distler;
using namespace team3Luo;
using namespace team3Kwok;

namespace team3Kwok {
	//default constructor
	Student::Student() {
		firstName = "n/a";
		middleName = "n/a";
		lastName = "n/a";
		studentID = 123456789;
		userIDNum = "abc1234";
		intendedMajor = "Computer Science";
		intendedMinor = "n/a";
		status = "Not Enrolled";
	}
	//constructor for everything
	Student::Student(string firstName, 
		string middleName, 
		string lastName, 
		int studentID, 
		string userIDNum, 
		MailingAddress stuAddress,
		Date birthDate,
		Date acceptDate,
		Semester startSemester,
		string intendedMajor,
		string intendedMinor,
		string status) {
			this->firstName = firstName;
			this->middleName = middleName;
			this->lastName = lastName;
			this->studentID = studentID;
			this->userIDNum = userIDNum;
			this->stuAddress = stuAddress;
			this->birthDate = birthDate;
			this->acceptDate = acceptDate;
			this->startSemester = startSemester;
			this->intendedMajor = intendedMajor;
			this->intendedMinor = intendedMinor;
			this->status = status;
	}
	//Copy Constructor
	Student::Student(const Student& s) {
			firstName = s.firstName;
			middleName = s.middleName;
			lastName = s.lastName;
			studentID = s.studentID;
			userIDNum = s.userIDNum;
			stuAddress = s.stuAddress;
			for (int i = 0; i < s.emailArr.size(); i++) {
				emailArr[i] = s.emailArr[i];
				
			}
			for (int i = 0; i < s.phoneArr.size(); i++) {
				phoneArr[i] = s.phoneArr[i];
				
			}
			birthDate = s.birthDate;
			acceptDate = s.acceptDate;
			startSemester = s.startSemester;
			intendedMajor = s.intendedMajor;
			intendedMinor = s.intendedMinor;
			status = s.status;
	}

	//get all student as a string
	string Student::getAllStudentData() const{
		string all;
		all = "\nName: " + firstName + " " + middleName + " " + lastName
			+ "\nStudent ID: " + to_string(studentID)
			+ "\nUser ID Number: " + userIDNum
			+ "\nMailing Addresses:\n";
			all+= (stuAddress.getStreet() + ", "
				+ stuAddress.getCity() + ", "
				+ stuAddress.getState() + "  "
				+ to_string(stuAddress.getZip()) + " ("
				+ stuAddress.getType() + ")\n\n");
		all+= "\nEmails:\n";
		for (int i = 0; i < emailArr.size(); i++) {
			all+= emailArr[i].getAddress() + " ("
				+ emailArr[i].getType() + ")\n\n";
		}
		all += "\nPhone Numbers:\n";
		for (int i = 0; i < phoneArr.size(); i++) {
			all+= phoneArr[i].getNum()+ " ("
			+ phoneArr[i].getType() + ") \n";
		}
		all+= "\nDOB: " + to_string(birthDate.getMonth()) + "/" + to_string(birthDate.getDay()) + "/" + to_string(birthDate.getYear())
			+ "\nDate Accepted: " + to_string(acceptDate.getMonth()) + "/" + to_string(acceptDate.getDay()) + "/" + to_string(acceptDate.getYear())
			+ "\nStart Semester: " + startSemester.getSeason() + ", " + to_string(startSemester.getYear());
			+ "\nIntended Major: " + intendedMajor
			+ "\nIntended Minor: " + intendedMinor
			+ "\nStatus: " + status + "\n";
		all += getCourseList(courseList) + "\n\n";
		return all;
	}
	string Student::getCourseList(CourseNode* head_ptr) const {
		string temp = "";

		CourseNode* cursor = NULL;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
		{
			temp = temp + "\nCourse Number: " + cursor->data.getCourseNumber();
			temp = temp + "\nCourse Description: " + cursor->data.getCourseDescription();
			temp = temp + "\nSemester Taken (Season): " + cursor->data.getSemesterTaken().getSeason() + "\nYear: " + to_string(cursor->data.getSemesterTaken().getYear());
			temp = temp + "\nDelivery Method: " + cursor->data.getDeliveryMethod();
			temp = temp + "\nCurrent Status: " + cursor->data.getCurrentStatus();
			temp = temp + "\nGrade Earned: " + to_string(cursor->data.getGradeEarned()) + "\n\n";

		}

		return temp;
	}
	string Student::getSomeStudentData() const
	{
		string some;
		some += "\nName: " + firstName + " " + middleName + " " + lastName
			+ "\nStudent ID: " + to_string(studentID)
			+ "\nUser ID Number: " + userIDNum;
		some += getCourseListPartial(courseList) + "\n\n";
		return some;

	}
	string Student::getCourseListPartial(CourseNode* head_ptr) const {
		string temp = "";

		CourseNode* cursor = NULL;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
		{
			temp = temp + "\nCourse Number: " + cursor->data.getCourseNumber();
			temp = temp + "\nCourse Description: " + cursor->data.getCourseDescription();
			temp = temp + "\nSemester Taken: Season: " + cursor->data.getSemesterTaken().getSeason() + " Year: " + to_string(cursor->data.getSemesterTaken().getYear());
			temp = temp + "\nDelivery Method: " + cursor->data.getDeliveryMethod();
			temp = temp + "\nCurrent Status: " + cursor->data.getCurrentStatus();
			temp = temp + "\nGrade Earned: " + to_string(cursor->data.getGradeEarned()) + "\n\n";

		}

		return temp;
	}

	//Mutator Functions
	void Student::setName(string first, string middle, string last) {
		firstName = first;
		middleName = middle;
		lastName = last;
	}
	void Student::setFirstName(string first) {
		firstName = first;
	}
	void Student::setMiddleName(string middle) {
		middleName = middle;
	}
	void Student::setLastName(string last) {
		lastName = last;
	}
	void Student::setStuID(int s) {
		studentID = s;
	}
	void Student::setUserID(string u) {
		userIDNum = u;
	}
	void Student::setStuAddress(MailingAddress m) {
		stuAddress = m;
	}
	void Student::setBirthDate(int m, int d, int y) {
		birthDate.setMonth(m);
		birthDate.setDay(d);
		birthDate.setYear(y);
	}
	void Student::setAcceptanceDate(int m, int d, int y) {
		acceptDate.setMonth(m);
		acceptDate.setDay(d);
		acceptDate.setYear(y);
	}
	void Student::setStartSemester(Semester s) {
		startSemester = s;
	}
	void Student::setIntendedMajor(string iM) {
		intendedMajor = iM;
	}
	void Student::setIntendedMinor(string iM) {
		intendedMinor = iM;
	}
	void Student::setStatus(string s) {
		status = s;
	}
	//Accessor Functions
	string Student::getFirstName() const {
		return firstName;
	}
	string Student::getMiddleName() const {
		return middleName;
	}	
	string Student::getLastName() const {
		return lastName;
	}
	int Student::getStuID() const {
		return studentID;
	}
	string Student::getUserID() const {
		return userIDNum;
	}
	MailingAddress Student::getStuAddress() const {
		return stuAddress;
	}
	Date Student::getBirthDate() const {
		return birthDate;
	}
	Date Student::getAcceptanceDate() const {
		return acceptDate;
	}
	Semester Student::getStartSemester() const {
		return startSemester;
	}
	string Student::getIntendedMajor() const {
		return intendedMajor;
	}
	string Student::getIntendedMinor() const {
		return intendedMinor;
	}
	string Student::getStatus() const {
		return status;
	}
	//insert functions
	void Student::insertEmail(Email e) {
		emailArr.push_back(e);
	}
	void Student::insertPhoneNum(PhoneNumber p) {
		phoneArr.push_back(p);
	}
	//file.io
	void Student::writeFile(ofstream& outFile) {
		outFile << firstName << "\n" << middleName << "\n" << lastName << "\n";
		//UNFINISHED
	}
	void Student::readFile(ifstream& inFile)/*need to add course*/ {
		//name input
		getline(inFile, firstName);
		getline(inFile, middleName);
		getline(inFile, lastName);

		//id input
		inFile >> studentID;
		inFile.ignore();
		getline(inFile, userIDNum);

		//address input
		string input;
		getline(inFile, input);
		stuAddress.setStreet(input);
		getline(inFile, input);
		stuAddress.setCity(input);
		getline(inFile, input);
		stuAddress.setState(input);
		int num;
		inFile >> num;
		stuAddress.setZip(num);
		inFile.ignore();
		getline(inFile, input);
		stuAddress.setType(input);

		//birth date input
		int m, d, y;
		inFile >> m >> d >> y;
		setBirthDate(m, d, y);

		//acceptance date input
		inFile >> m >> d >> y;
		setAcceptanceDate(m, d, y);

		//start semester
		inFile >> input >> num;
		Semester startSemester(input, num);
		setStartSemester(startSemester);

		//intended major
		inFile.ignore();
		getline(inFile, input);
		setIntendedMajor(input);

		//intended minor
		getline(inFile, input);
		setIntendedMinor(input);

		//status
		getline(inFile, input);
		setStatus(input);

		//email address loop
		inFile >> num;
		for (int i = 0; i < num; i++) {
			string emailName, emailType;
			inFile >> emailName >> emailType;
			Email emailAdd(emailName, emailType);
			insertEmail(emailAdd);
		}

		//phone number loop
		inFile >> num;
		for (int i = 1; i <= num; i++) {
			string phoneNumber, phoneType;
			inFile >> phoneNumber >> phoneType;
			PhoneNumber phoneNum(phoneNumber, phoneType);
			insertPhoneNum(phoneNum);
		}
		inFile.ignore();
	}
}
