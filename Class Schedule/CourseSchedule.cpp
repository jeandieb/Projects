/*
CSIS 137
MIDTERM PROJECT 
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iostream>
#include "CourseSchedule.h"

using namespace std;

ostream& operator<<(ostream& input, const CourseSchedule& passed)
{
	input << "\n\nCLASS SCHEDULE\n-----------------------------" << endl
		<< "Name: " << passed.getStudentName() << endl
		<< "Semester: " << passed.getSemester() << endl
		<< "Number of Classes: " << passed.getNumCourses() << endl
		<< "-----------------------------------" << endl;
	for (int i = 0; i < passed.maxSize; i++)
	{
		input << "# " << i << ": " << endl << passed.coursePtr[i] << endl;
	}
	return input;
}

CourseSchedule::CourseSchedule(string na, Semester sem, int MAX)
{
	setStudentName(na);
	semester = sem;
	maxSize = MAX;
	numCourses = 0;
	coursePtr = new Course [MAX];
}

CourseSchedule::~CourseSchedule()
{
	delete[] coursePtr;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

Semester CourseSchedule::getSemester() const
{
	return semester;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}

int CourseSchedule::getMaxSize() const
{
	return maxSize;
}

CourseSchedule& CourseSchedule::setStudentName(string na)
{
	studentName = na;
	return *this;
}

void CourseSchedule::addCourse(Course added)
{
	
		if (this->checkDates(this->getSemester(), added.getCourseStartDate(), added.getCourseEndDate()) == true)
		{
			coursePtr[this->numCourses] = added;
			this->numCourses++;
			cout << "\ncourse has been added successfully" << endl;
		}
		else
			cout << "\ncan't addd this course. check the dates." << endl;

	
}

bool CourseSchedule::checkDates(Semester sem, Date s, Date e)
{
	if (sem.getSemesterStartDate() > s || sem.getSemesterEndDate() < e)
	{
		return false;
	}
	else
		return true;
}

void CourseSchedule::removeCourse(int deleted)
{
	for (int i = deleted; i < (this->maxSize) -1; i++)
	{
		coursePtr[i] = coursePtr[i + 1];
	}
	Course temp;
	coursePtr[(this->maxSize)-1] = temp;
	this->numCourses--;
	cout << "\nCourse has been successfully removed" << endl;
}

