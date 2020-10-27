/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iostream>
#include "Semester.h"
#include <string>

using namespace std;

ostream& operator<<(ostream& output, const Semester& passed)
{
	output << "Semester: " << passed.getSemesterName() << "  " << passed.getSemesterStartDate() << " - " << passed.getSemesterEndDate() << endl;
	return output;
}

istream& operator>>(istream& input, Semester& passed)// (name 00/00/0000-00/00/0000)
{
	cout << "Enter the name of the semester then press enter" << endl;
	getline(cin, passed.semesterName);
	//cin.ignore();
	cout << "enter the semester dates (00/00/0000-00/00/0000" << endl;
	cin >> passed.semesterStartDate;
	cin.ignore();
	cin >> passed.semesterEndDate;

	return input;
}

Semester::Semester(string name, Date sStart, Date sEnd)
{
	setSemesterName(name);
	setSemesterStartDate(sStart);
	setSemesterEndDate(sEnd);
}

Semester& Semester::setSemesterName(string name)
{
	semesterName = name;
	return *this;
}

Semester& Semester::setSemesterStartDate(Date sStart)
{
	semesterStartDate = sStart;
	return *this;
}

Semester& Semester::setSemesterEndDate(Date sEnd)
{
	semesterEndDate = sEnd;
	return *this;
}

string Semester::getSemesterName() const
{
	return semesterName;
}

Date Semester::getSemesterStartDate() const
{
	return semesterStartDate;
}

Date Semester::getSemesterEndDate() const
{
	return semesterEndDate;
}