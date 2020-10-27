/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

using std::string;

class Course
{
	friend ostream& operator<<(ostream&, const Course&);

	private:
		string courseNumber;
		string courseName;
		string courseMeetingDays;
		double numUnits;
		Date courseStartDate;
		Date courseEndDate;
		Time startTime;
		Time endTime;

	public:
		Course(string = "EMPTY", string = " ", string = " ", double = 0.0, Date = Date(), Date = Date(), Time = Time(), Time = Time()); // Default Constructor
		//~Course(); // Useless Destructor
		string getCourseNumber() const;
		string getCourseName() const;
		string getCourseMeetingDays() const;
		double getNumUnits() const;
		Date getCourseStartDate() const;
		Date getCourseEndDate() const;
		Time getStartTime() const;
		Time getEndTime() const;
		Course& setCourseNumber(string);
		Course& setCourseName(string);
		Course& setCourseMeetingDays(string);
		Course& setNumUnits(double);
		Course& setCourseStartDate(Date);
		Course& setCourseEndDate(Date);
		Course& setCoureStartTime(Time);
		Course& setCourseEndTime(Time);
		double calcDuration(const Time&, const Time&) const;
		Course operator=( Course); // copy constructor
		Course getCourse(Course&);// ask for Course details
};


#endif // !COURSE_H
