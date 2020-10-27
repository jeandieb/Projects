/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include "Date.h"

using std::string;

class Semester
{
	friend ostream& operator<<(ostream&, const Semester&);
	friend istream& operator>>(istream&, Semester&);

	private:
		string semesterName;
		Date semesterStartDate;
		Date semesterEndDate;

	public:
		Semester(string = "VACATION", Date = Date(), Date = Date());// default constructor
		Semester& setSemesterName(string);
		Semester& setSemesterStartDate(Date);
		Semester& setSemesterEndDate(Date);
		string getSemesterName() const;
		Date getSemesterStartDate() const;
		Date getSemesterEndDate() const;
};




#endif