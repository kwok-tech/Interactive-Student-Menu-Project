/*********************************************************
*  file name: StudentApplication.cpp
*  programmer names: Jack Kwok, Lukas Belashov, David Luo, and Nicky Distler
*  date created:2/14/2020
*  date of last revision:4/28/2020
*  details of the revision: adding more functions to the menu
*  short description: Menu driven application that records and writes student data
**********************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "course.h"
#include "MailingAddress.h"
#include "Email.h"
#include "PhoneNumber.h"
#include "Date.h"
#include "Semester.h"
#include "Student.h"
#include "StuLinkedList.h"

//namespace calls
using namespace std;
using namespace team3Kwok;

//function prototypes
void getStuInfoUser();
void getStuInfoFile();
void displayStu();
void editStu();
void deleteStu();
void sortStu();
void writeStuToFile();
void drivingMenu();

//linked list of students
Stu* stuHead = NULL;

//main function
int main() {
	//prgm desc
	cout << "This Program will populate, display, and writes student data" << endl;
	//menu
	drivingMenu();
	return 0;
}

//function definitions
//Getting student information from the user (added Courses)
void getStuInfoUser() {
	Stu* stuTail = stuHead;
	int numberOfStudents;
	Student addStu;
	cout << "Please enter the number of students you wish to add" << endl;
	cin >> numberOfStudents;
	for (int s = 1; s <= numberOfStudents; s++) {
		string first, middle, last, userId;
		int stuId;
		int numEmailAddress, numPhoneNumbers, numCourses;

		//name input
		cout << "Please enter the student's first name" << endl;
		cin >> first;
		addStu.setFirstName(first);
		cout << "Please enter the student's middle name" << endl;
		cin >> middle;
		addStu.setMiddleName(middle);
		cout << "Please enter the student's last name" << endl;
		cin >> last;
		addStu.setLastName(last);

		//id input
		cout << "Please enter the student's nine digit ID number" << endl;
		cin >> stuId;
		addStu.setStuID(stuId);
		cout << "Please enter the student's user ID" << endl;
		cin >> userId;
		addStu.setUserID(userId);

		//address input
		string streetName, cityName, stateName, addressType, major, minor, season, status;
		int zipCode, month, day, year, aMonth, aDay, aYear, sesYear;
		cout << "Please enter your street address (123 Tester Avenue)" << endl;
		cin.ignore();
		getline(cin, streetName);
		cout << "Please enter your city name (Springfield)" << endl;
		getline(cin, cityName);
		cout << "Please enter your state name (Pennsylvania)" << endl;
		cin >> stateName;
		cout << "Please enter your zip code (45678)" << endl;
		cin >> zipCode;
		cout << "Please enter your address type (permenant, apartment)" << endl;
		cin >> addressType;
		MailingAddress mailAdd(streetName, cityName, stateName, zipCode, addressType);
		addStu.setStuAddress(mailAdd);

		//birth date input
		cout << "Please enter your birth Month, Day, And Year\nMonth:" << endl;
		cin >> month;
		cout << "Day:" << endl;
		cin >> day;
		cout << "Year:" << endl;
		cin >> year;
		addStu.setBirthDate(month, day, year);

		//acceptance date input
		cout << "Please when your acceptance Month, Day, And Year\nMonth:" << endl;
		cin >> aMonth;
		cout << "Day:" << endl;
		cin >> aDay;
		cout << "Year:" << endl;
		cin >> aYear;
		addStu.setAcceptanceDate(aMonth, aDay, aYear);

		//start semester
		cout << "Please enter the starting semester \nseason: ";
		cin >> season;
		cout << "year: ";
		cin >> sesYear;
		Semester startSemester(season, sesYear);
		addStu.setStartSemester(startSemester);

		//intended major
		cout << "Please enter the intended major" << endl;
		cin.ignore();
		getline(cin, major);
		addStu.setIntendedMajor(major);

		//intended minor
		cout << "Please enter the intended minor" << endl;
		getline(cin, minor);
		addStu.setIntendedMinor(minor);

		//status
		cout << "Please enter the students status" << endl;
		cin >> status;
		addStu.setStatus(status);

		//email address loop
		cout << "Please enter the number of Email Adresses" << endl;
		cin >> numEmailAddress;
		for (int i = 1; i <= numEmailAddress; i++) {
			string emailName, emailType;
			cout << "Please enter your email address (johndoe@gmail.com)" << endl;
			cin >> emailName;
			cout << "Please enter your email type (university, personal)" << endl;
			cin >> emailType;
			Email emailAdd(emailName, emailType);
			addStu.insertEmail(emailAdd);
		}

		//phone number loop
		cout << "Please enter the number of Phone Numbers" << endl;
		cin >> numPhoneNumbers;
		for (int i = 1; i <= numPhoneNumbers; i++) {
			string phoneNumber, phoneType;
			cout << "Please enter your ten digit phone number" << endl;
			cin >> phoneNumber;
			cout << "Please enter your phone number type (university, personal)" << endl;
			cin >> phoneType;
			PhoneNumber phoneNum(phoneNumber, phoneType);
			addStu.insertPhoneNum(phoneNum);
		}
		//course loop
		CourseNode* courseTail = addStu.courseList;
		//ask number of courses
		cout << "Please enter the number of Courses" << endl;
		cin >> numCourses;
		for (int i = 0; i < numCourses; i++) {
			Course newCourse;
			int grade;
			string courseNumber, description, method, status;
			//add each of the member vars (int grade, Semester semesterTaken, string courseNumber, string description, string method, string status)
			cout << "Please enter the Course Number (ex. CMPSC121)" << endl;
			cin >> courseNumber;
			newCourse.setCourseNumber(courseNumber);
			cout << "Please type a description of the course" << endl;
			cin.ignore();
			getline(cin, description);
			newCourse.setCourseDescription(description);
			cout << "Please enter the semester taken \nseason: ";
			cin >> season;
			cout << "year: ";
			cin >> sesYear;
			Semester semesterTaken(season, sesYear);
			newCourse.setSemesterTaken(semesterTaken);
			cout << "Please enter the delivery method" << endl;
			cin >> method;
			newCourse.setDeliveryMethod(method);
			cout << "Please enter the current status" << endl;
			cin >> status;
			newCourse.setCurrentStatus(status);
			cout << "Please enter number grade" << endl;
			cin >> grade;
			newCourse.setGradeEarned(grade);
			//add to course list
			if (addStu.courseList != NULL) {
				cout << "Stuhead not null" << endl;
				list_insert(courseTail, newCourse);
				courseTail = courseTail->link;
			}
			else if (addStu.courseList == NULL) {
				cout << "Stuhead null" << endl;
				list_head_insert(addStu.courseList, newCourse);
				cout << "Stuhead added" << endl;
				courseTail = addStu.courseList;
			}
		}
		//add into list
		if (stuHead != NULL) {
			list_insert(stuTail, addStu);
			stuTail = stuTail->link;
		}
		else if (stuHead == NULL) {
			list_head_insert(stuHead, addStu);
			//inFile.ignore();
			stuTail = stuHead;
		}
	}
}
//Getting student information from a file (add Courses)(NEED TO TEST and debug)
void getStuInfoFile() {
	Stu* tail = stuHead;
	ifstream inFile;
	//open file
	string fileName;
	cout << "Enter the name of the file. \nFile Name: ";
	cin >> fileName;
	// open file for input
	inFile.open(fileName);
	if (inFile.fail())
	{
		cout << "Unable to open file for input\n";
		exit(2);
	}
	cout << "File opened.\n";
	//read in number of students and loop to add into linked list
	int numOfStu;
	inFile >> numOfStu;
	inFile.ignore();
	for (int s=0; s < numOfStu; s++){
		//creates new student
		Student student;
		//reading student
		student.readFile(inFile);
		//add into list
		if (stuHead != NULL) {
			list_insert(tail, student);
			tail = tail->link;
		}
		else if (stuHead == NULL) {
			list_head_insert(stuHead, student);
			//inFile.ignore();
			tail = stuHead;
		}
		cout << "Student added" << endl;
	}
	cout << "end of loop" << endl;
	inFile.close();
}
// displays the student's info (TESTED)
void displayStu() {
	int displayMenuChoice;
	//display submenu 
	cout << "Please select a menu option" << endl
		//Lukas:
		<< "1: Display all students and all their data" << endl
		<< "2: Display all students and some of their data" << endl
		//Jack:
		<< "3: Display individual student by last name" << endl
		<< "4: Display all students who have the specified major" << endl
		<< "5: Display all students who have the specified minor" << endl//DO LATER
		<< "6: Display all students who started in a certain semester" << endl
		<< "7: Display all student who have a specified status" << endl;
	cin >> displayMenuChoice;
	if (displayMenuChoice == 1) {
		Stu* temp = new Stu;
		temp = stuHead;
		while (temp != NULL) {
			cout << temp->data.getAllStudentData();
			temp = temp->link;
		}
	}
	else if (displayMenuChoice == 2) {
		Stu* temp = new Stu;
		temp = stuHead;
		while (temp != NULL) {
			cout << temp->data.getSomeStudentData();
			temp = temp->link;
		}
	}
	else if (displayMenuChoice == 3) {
		//user input section
		//Display menu of students, let them pick by last name
		string displayPick;
		Stu* temp = new Stu;
		temp = stuHead;
		cout << "Pick the student you want to display by last name: ";
		cin >> displayPick;
		while (list_search(stuHead, displayPick) == NULL) {
			cin >> displayPick;
		}
		cout << list_search(stuHead, displayPick)->data.getAllStudentData();
	}
	else if (displayMenuChoice == 4) {
		if (stuHead == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			string displayMajor, display ="";
			cout << "List students with major: ";
			cin.ignore();
			getline(cin, displayMajor);
			Stu* cursor = NULL;
			for (cursor = stuHead; cursor != NULL; cursor = cursor->link)
			{
				//looks by the student's major
				if (cursor->data.getIntendedMajor() == displayMajor)
				{
					display += cursor->data.getAllStudentData();
				}

			}
			cout << display;
		}
	}
	else if (displayMenuChoice == 5) {
		if (stuHead == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			string displayMajor, display = "";
			cout << "List students with major: ";
			cin.ignore();
			getline(cin, displayMajor);
			Stu* cursor = NULL;
			for (cursor = stuHead; cursor != NULL; cursor = cursor->link)
			{
				//looks by the student's major
				if (cursor->data.getIntendedMajor() == displayMajor)
				{
					display += cursor->data.getAllStudentData();
				}

			}
			cout << display;
		}
	}
	else if (displayMenuChoice == 6) {
		if (stuHead == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			string displaySeason, display = "";
			int displayYear;
			cout << "List students with season: ";
			cin >> displaySeason;
			cout << " and year: ";
			cin >> displayYear;
			Stu* cursor = NULL;
			for (cursor = stuHead; cursor != NULL; cursor = cursor->link)
			{
				//looks by the student's semester
				if (cursor->data.getStartSemester().getSeason() == displaySeason && cursor->data.getStartSemester().getYear() == displayYear)
				{
					display += cursor->data.getAllStudentData();
				}

			}
			cout << display;
		}
	}
	else if (displayMenuChoice == 7) {
		if (stuHead == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			string displayStat, display = "";
			cout << "List students with status: ";
			cin >> displayStat;
			Stu* cursor = NULL;
			for (cursor = stuHead; cursor != NULL; cursor = cursor->link)
			{
				//looks by the student's status
				if (cursor->data.getStatus() == displayStat)
				{
					display += cursor->data.getAllStudentData();
				}

			}
			cout << display;
		}
	}
	else {
		cout << "Invalid menu choice, please try again" << endl;
	}
	
}
// Edits a student of the user's choice (TESTED)
void editStu() {
	int editChoice;
	string searchName;
	cout << "Please enter the last name of the student you wish to edit: ";
	cin >> searchName;
	list_search(stuHead, searchName)->data.getAllStudentData();
	cout << "Please select which part of the student you would like to edit:" << endl;
	cout << "1:  Name" << endl;
	cout << "2:  ID Number" << endl;
	cout << "3:  User ID" << endl;
	cout << "4:  Mailing Address" << endl;
	cout << "5:  Email Address(es)" << endl;
	cout << "6:  Phone Number(s)" << endl;
	cout << "7:  Birth Date" << endl;
	cout << "8:  Acceptance Date" << endl;
	cout << "9:  Starting Semester" << endl;
	cout << "10: Intended Major" << endl;
	cout << "11: Intended Minor" << endl;
	cout << "12: Status" << endl;
	cout << "13: Courses" << endl;
	cin >> editChoice;
	if (editChoice == 1) {
		string newFirstName, newMiddleName, newLastName;
		cout << "Please enter the new full name (first, middle, last) of the student" << endl;
		cin >> newFirstName >> newMiddleName >> newLastName;
		list_search(stuHead, searchName)->data.setName(newFirstName, newMiddleName, newLastName);
	}
	else if (editChoice == 2) {
		int newID;
		cout << "Please enter the new ID number of the student" << endl;
		cin >> newID;
		list_search(stuHead, searchName)->data.setStuID(newID);
	}
	else if (editChoice == 3) {
		string newUserID;
		cout << "Please enter the new user ID of the student" << endl;
		cin >> newUserID;
		list_search(stuHead, searchName)->data.setUserID(newUserID);
	}
	else if (editChoice == 4) {
		MailingAddress newMailingAddress;
		string newStreetAddress, newCity, newState, newType;
		int newZip;
		cout << "Please enter the new mailing address of the student" << endl;
		cout << "Street Address" << endl;
		cin.ignore();
		getline(cin, newStreetAddress);
		cout << endl << "City" << endl;
		getline(cin, newCity);
		cout << endl << "State" << endl;
		cin >> newState;
		cout << endl << "Zip Code" << endl;
		cin >> newZip;
		cout << endl << "Type" << endl;
		cin >> newType;
		newMailingAddress = MailingAddress(newStreetAddress, newCity, newState, newZip, newType);
		list_search(stuHead, searchName)->data.setStuAddress(newMailingAddress);
	}
	else if (editChoice == 5) {
			string currentEmail, newEmail, newType;
			cout << "Please enter the email address you would like to edit" << endl;
			cin >> currentEmail;
			for (int i = 0; i < list_search(stuHead, searchName)->data.emailArr.size(); i++) {
				if (currentEmail == list_search(stuHead, searchName)->data.emailArr[i].getAddress()) {
					cout << "please enter the new email address" << endl;
					cin >> newEmail;
					list_search(stuHead, searchName)->data.emailArr[i].setAddress(newEmail);
					cout << "please enter the new email type" << endl;
					cin >> newType;
					list_search(stuHead, searchName)->data.emailArr[i].setType(newType);
					break;
				}
			}
		}
	else if (editChoice == 6) {
			string currentNum, newNum, newType;
			cout << "Please enter the phone number you would like to edit" << endl;
			cin >> currentNum;
			for (int i = 0; i < list_search(stuHead, searchName)->data.phoneArr.size(); i++) {
				if (currentNum == list_search(stuHead, searchName)->data.phoneArr[i].getNum()) {
					cout << "please enter the new phone number" << endl;
					cin >> newNum;
					list_search(stuHead, searchName)->data.phoneArr[i].setNum(newNum);
					cout << "please enter the new phone number type" << endl;
					cin >> newType;
					list_search(stuHead, searchName)->data.phoneArr[i].setType(newType);
					break;
				}
			}
		}
	else if (editChoice == 7) {
			Date newBirthDate;
			int newMonth, newDay, newYear;
			cout << "Please enter the new birth date of the student" << endl;
			cout << "Month" << endl;
			cin >> newMonth;
			cout << endl << "Day" << endl;
			cin >> newDay;
			cout << endl << "Year" << endl;
			cin >> newYear;
			list_search(stuHead, searchName)->data.setBirthDate(newMonth, newDay, newYear);
		}
	else if (editChoice == 8) {
			Date newAcceptanceDate;
			int newMonth, newDay, newYear;
			cout << "Please enter the new acceptance date of the student" << endl;
			cout << "Month" << endl;
			cin >> newMonth;
			cout << endl << "Day" << endl;
			cin >> newDay;
			cout << endl << "Year" << endl;
			cin >> newYear;
			list_search(stuHead, searchName)->data.setAcceptanceDate(newMonth, newDay, newYear);
		}
	else if (editChoice == 9) {
			Semester newStartSemester;
			string newStartSeason;
			int newStartYear;
			cout << "Please enter the new start semester of the student" << endl;
			cout << "Season" << endl;
			cin >> newStartSeason;
			cout << endl << "Year" << endl;
			cin >> newStartYear;
			newStartSemester = Semester(newStartSeason, newStartYear);
			list_search(stuHead, searchName)->data.setStartSemester(newStartSemester);
		}
	else if (editChoice == 10) {
			string newIntendedMajor;
			cout << "Please enter the new intended major of the student" << endl;
			cin.ignore();
			getline(cin, newIntendedMajor);
			list_search(stuHead, searchName)->data.setIntendedMajor(newIntendedMajor);
		}
	else if (editChoice == 11) {
		string newIntendedMinor;
		cout << "Please enter the new intended major of the student" << endl;
		cin.ignore();
		getline(cin, newIntendedMinor);
		list_search(stuHead, searchName)->data.setIntendedMinor(newIntendedMinor);
		}
	else if (editChoice == 12) {
			string newStatus;
			cout << "Please enter the new user ID of the student" << endl;
			cin >> newStatus;
			list_search(stuHead, searchName)->data.setStatus(newStatus);
		}
	else if (editChoice == 13) {
			string currentCourseNumber, newCourseNumber, newDescription, newMethod, newStatus, newTakenSeason;
			Semester newTakenSemester;
			int newTakenYear, newGrade, courseEditChoice;

			cout << "Please enter the course number you would like to edit" << endl;
			cin >> currentCourseNumber;
			do {
				cout << "Please select which part of the course you would like to edit: " << endl;
				cout << "1: Edit Course Number" << endl;
				cout << "2: Edit Semeater Taken" << endl;
				cout << "3: Edit Course Description" << endl;
				cout << "4: Edit Delivery Method" << endl;
				cout << "5: Edit Numerical Grade" << endl;
				cout << "6: Edit Course Status" << endl;
				cout << "7: Exit" << endl;
				cin >> courseEditChoice;
				if (courseEditChoice == 1) {
					cout << "please enter the new Course Number" << endl;
					cin >> newCourseNumber;
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setCourseNumber(newCourseNumber);
				}
				else if (courseEditChoice == 2) {
					cout << "Please enter the new Semester Taken" << endl;
					cout << "Season" << endl;
					cin >> newTakenSeason;
					cout << endl << "Year" << endl;
					cin >> newTakenYear;
					newTakenSemester = Semester(newTakenSeason, newTakenYear);
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setSemesterTaken(newTakenSemester);
				}
				else if (courseEditChoice == 3) {
					cout << "please enter the new Description" << endl;
					cin.ignore();
					getline(cin, newDescription);
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setCourseDescription(newDescription);
					}
				else if (courseEditChoice == 4) {
					cout << "please enter the new Method" << endl;
					cin >> newMethod;
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setDeliveryMethod(newMethod);
				}
				else if (courseEditChoice == 5) {
					cout << "please enter the new numerical Grade" << endl;
					cin >> newGrade;
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setGradeEarned(newGrade);
				}
				else if (courseEditChoice == 6) {
					cout << "please enter the new Status" << endl;
					cin >> newStatus;
					list_search(list_search(stuHead, searchName)->data.courseList, currentCourseNumber)->data.setCurrentStatus(newStatus);
				}
				else {
					cout << "Invalid menu choice, please try again." << endl;
				}
			} while (courseEditChoice != 7);
			if (courseEditChoice == 7) {
				cout << "Thank you";
			}
		}
	else {
			cout << "Invalid menu choice, please try again.";
		}
}
//deletes a student from the list (TESTED)
void deleteStu() {
	string lastNameInput;
	cout << "Type the last name of the student you want to delete: ";
	cin >> lastNameInput;
	if (stuHead->data.getLastName() == lastNameInput) {
		list_head_remove(stuHead);
	}
	else if (stuHead != NULL) {
		list_remove(stuHead, lastNameInput);
	}
	else {
		cout << "This Student is not in the list" << endl;
	}
}
//sorts the list based on user preference (TESTED)
void sortStu() {
	cout << "What do you want to sort by?\n1: Last Name\n2: Student ID\n3: Major\n4: Current Status\n";
	int sortSel;
	cin >> sortSel;
	list_sort(stuHead, sortSel);
}
//Write the students to a file
void writeStuToFile() {
	//open file
	ofstream outFile;
	string fileNameO;
	cout << "Enter the name of the file. \nFile Name: ";
	cin >> fileNameO;
	outFile.open(fileNameO);
	if (outFile.fail()) {
		cout << "Unable to open file for output\n";
		exit(2);
	}
	cout << "File opened.\n";
	//writeFile(outFile);

	outFile.close();

}
//Driving Menu
void drivingMenu() {
	int mainMenuChoice, inputMenuChoice;

	do {
		cout << "Please select a menu option" << endl
			<< "1: Add students" << endl
			<< "2: Display Students" << endl
			<< "3. Edit a Student" << endl
			<< "4. Delete a Student" << endl
			<< "5. Sort Students" << endl
			<< "6. Write Students to a file" << endl
			<< "7: Exit" << endl;
		cin >> mainMenuChoice;
		if (mainMenuChoice == 1) {
			//input submenu
			cout << "Please select a menu option" << endl
				<< "1: Populate from file input" << endl
				<< "2: Populate from user input" << endl;
			cin >> inputMenuChoice;
			if (inputMenuChoice == 1) {
				//file input section
				getStuInfoFile();
			}
			else if (inputMenuChoice == 2) {
				//user input section
				getStuInfoUser();

			}
			else {
				cout << "Invalid menu choice, please try again" << endl;
			}
		}
		else if (mainMenuChoice == 2) {
			displayStu();
		}
		else if (mainMenuChoice == 3) {
			editStu();
		}
		else if (mainMenuChoice == 4) {
			deleteStu();
		}
		else if (mainMenuChoice == 5) {
			sortStu();
		}
		else if (mainMenuChoice == 6) {
			writeStuToFile();
		}
		else {
			cout << "Invalid menu choice, please try again";
		}
	} while (mainMenuChoice != 7);

}