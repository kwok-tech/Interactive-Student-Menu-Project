#include <iostream>
#include <string>
#include "course.h"
using namespace std;
namespace team3Belashov
{

	Course::Course(string courseNum, Semester semesterTa, string desc,
		string metho, int grad, string stat)
	{
		courseNumber = courseNum;
		semesterTaken = semesterTa;
		description = desc;
		method = metho;
		grade = grad;
		status = stat;
	}

	Course::Course(const Course& s) {
		courseNumber = s.courseNumber;
		semesterTaken = s.semesterTaken;
		description = s.description;
		method = s.method;
		grade = s.grade;
		status = s.status;
	}

	//setters
	void Course::setCourseNumber(string courseNum)
	{
		courseNumber = courseNum;
	}
	void Course::setCourseDescription(string desc)
	{
		description = desc;

	}
	void Course::setSemesterTaken(Semester semesterTa)
	{
		semesterTaken = semesterTa;
	}
	void Course::setDeliveryMethod(string metho)
	{
		method = metho;
	}
	void Course::setCurrentStatus(string stat)
	{
		status = stat;
	}
	void Course::setGradeEarned(int grad)
	{
		grade = grad;

	}
	//getters
	string Course::getCourseNumber() const
	{
		return courseNumber;
	}
	string Course::getCourseDescription() const
	{
		return description;
	}
	Semester Course::getSemesterTaken() const
	{
		return semesterTaken;
	}
	string Course::getDeliveryMethod() const
	{
		return method;
	}
	string Course::getCurrentStatus() const
	{
		return status;
	}
	int Course::getGradeEarned() const
	{
		return grade;
	}
}