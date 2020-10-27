/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iostream>
#include "Course.h"
#include <string>

using namespace std;

ostream& operator<<(ostream& output,  const Course& passed)
{
	output << "Course Info:\t" << passed.getCourseNumber() << " -- " << passed.getCourseName() << endl
		<< "# of Units:\t" << passed.getNumUnits() << endl
		<< "Course Date:\t" << passed.getCourseStartDate() << " - " << passed.getCourseEndDate() << endl
		<< "Meeting Days:\t" << passed.getCourseMeetingDays() << endl
		<< "Meeting Times:\t"  << passed.getStartTime() << " - " << passed.getEndTime() << endl
	   << "Daily Duration:\t" << passed.calcDuration(passed.getEndTime(), passed.getStartTime()) << " hours" << endl;
	return output;

}


Course::Course(string cNumber, string cName, string cMeetingDays, double Units, Date dStart, Date dEnd, Time tStart, Time tEnd )
{
	setCourseNumber(cNumber);
	setCourseName(cName);
	setCourseMeetingDays(cMeetingDays);
	setNumUnits(Units);
	setCourseStartDate(dStart);
	setCourseEndDate(dEnd);
	setCoureStartTime(tStart);
	setCourseEndTime(tEnd);
}

//Course::~Course()
//{
//	cout << "Object has been destroyed" << endl;
	//system("pause");
//}

string Course::getCourseNumber() const
{
	return courseNumber;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getCourseMeetingDays() const
{
	return courseMeetingDays;
}

double Course::getNumUnits() const
{
	return numUnits;
}

Date Course::getCourseStartDate() const
{
	return courseStartDate;
}

Date Course::getCourseEndDate() const
{
	return courseEndDate;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}

Course& Course::setCourseNumber(string num)
{
	courseNumber = num;
	return *this;
}

Course& Course::setCourseName(string na)
{
	courseName = na;
	return *this;
}

Course& Course::setCourseMeetingDays(string mD)
{
	courseMeetingDays = mD;
	return* this;
}

Course& Course::setNumUnits(double numU)
{
	numUnits = numU;
	return *this;
}

Course& Course::setCourseStartDate(Date sDate)
{
	courseStartDate = sDate;
	return *this;
}
 
Course& Course::setCourseEndDate(Date eDate)
{
	courseEndDate = eDate;
	return *this;
}

Course& Course::setCoureStartTime(Time sTime)
{
	startTime = sTime;
	return *this;
}

Course& Course::setCourseEndTime(Time eTime)
{
	endTime = eTime;
	return *this;
}

double Course::calcDuration(const Time& left, const Time& right) const
{
	double difference;
	difference = left - right;
	return difference;
}

Course Course::operator=( Course right)
{
	this->courseNumber = right.courseNumber;
	this->courseName = right.courseName;
	this->courseMeetingDays = right.courseMeetingDays;
	this->numUnits = right.numUnits;
	this->courseStartDate = right.courseStartDate;
	this->courseEndDate = right.courseEndDate;
	this->startTime = right.startTime;
	this->endTime = right.endTime;

	return *this;
}

Course Course::getCourse(Course& passed)
{
	string name, number, days;
	double uni;
	Date Starting, Ending;
	Time Starting1, Ending1;
	cin.ignore();
	cout << "enter the number of the course" << endl;
	getline(cin, number);
	cout << "enter the name of the course" << endl;
	getline(cin, name);
	cout << "enter the meeting days (e.g: TTHF)" << endl;
	getline(cin, days);
	cout << "enter the number of units" << endl;
	cin >> uni;
	cout << "enter the starting date (mm/dd/yyyy)" << endl;
	cin >> Starting;
	cout << "enter the ending date (mm/dd/yyyy)" << endl;
	cin >> Ending;
	cout << "enter the starting time (00:00 AM||PM)" << endl;
	cin >> Starting1;
	cout << "enter the ending time (00:00 AM||PM)" << endl;
	cin >> Ending1;
	Course temp(number, name, days, uni, Starting, Ending, Starting1, Ending1);
	 passed = temp;
	 return passed;
}


