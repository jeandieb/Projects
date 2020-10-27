/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H

#include <iostream>
#include "Course.h"
#include "Semester.h"
#include "Date.h"
#include <string>

using std::string;

class CourseSchedule
{
	friend ostream& operator<<(ostream&, const CourseSchedule&);

	private:
		string studentName;
		Semester semester;
		Course* coursePtr;
		int maxSize;
		int numCourses;
		bool checkDates(Semester, Date, Date);

	public:
		CourseSchedule(const CourseSchedule&) = delete; // delete the copy constructor
		void operator=(const CourseSchedule&) = delete; // delete the assingnement operator
		CourseSchedule(string = "UNKNOW", Semester = Semester(), int = 1);// int represent maxSize;
		~CourseSchedule();
		string getStudentName() const;
		Semester getSemester() const;
		int getNumCourses() const;
		int getMaxSize() const;
		CourseSchedule& setStudentName(string);
		void addCourse(Course);
		void removeCourse(int);
};
#endif