#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "Semester.h"
using namespace std;
using namespace team3Distler;
namespace team3Belashov
{
	class Course
	{
	private:
		int grade;
		Semester semesterTaken;
		string courseNumber, description, method, status;
	public:
		Course(string courseNumber = "unknown", Semester semesterTaken = Semester(), string description = "unknown",
			string method = "unknown", int grade = 100, string status = "unknown");
		Course(const Course& s);

		void setCourseNumber(string courseNumber);
		void setCourseDescription(string description);
		void setSemesterTaken(Semester semesterTaken);
		void setDeliveryMethod(string method);
		void setCurrentStatus(string status);
		void setGradeEarned(int grade);

		string getCourseNumber() const;
		string getCourseDescription() const;
		Semester getSemesterTaken() const;
		string getDeliveryMethod() const;
		string getCurrentStatus() const;
		int getGradeEarned() const;
	};
}


#endif 

