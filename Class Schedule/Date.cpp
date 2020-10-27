/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iomanip>
#include "Date.h"

using std::ostream;
using std::istream;
using std::setfill;
using std::setw;
using std::fixed;

ostream& operator<<(ostream& output, const Date& passed)
{
	output << setw(2) << setfill('0') << passed.month << "/" << setw(2) << setfill('0') << passed.day << "/" << setw(4) << setfill('0') << passed.year;
	return output;
}

istream& operator>>(istream& input, Date& passed) // (mm/dd/yyyy)
{
	input >> passed.month;
	input.ignore();
	input >> passed.day;
	input.ignore();
	input >> passed.year;

	return input;
}
	

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
 setDate(mn, dy, yr);
};

void Date::setDate(int mn, int dy, int yr)
{
 if(mn > 0 && mn <= 12)
 {
    month  = mn;
 }
 
 else
 {
     month = 1;
     cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
 }
 
 year = yr;  //could also validate year
 
 day = checkDay(dy);  //to validate the day
 
}


//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
     return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
      return testDay;
    }
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

Date& Date::setMonth(int mn)
{
	if (mn > 0 && mn <= 12) // Better make a function but this is faster.
	{
		month = mn;
	}

	else
	{
		month = 1;
		cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
	}

	return *this;
}

Date& Date::setDay(int dy)
{
	day = checkDay(dy);
	return *this;
}

Date& Date::setYear(int y)
{
	year = y;
	return *this;

}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear()const
{
	return year;
}

bool Date::operator>(const Date& right) const
{
	if (this->year > right.year)
		return true;
	else if (this->year == right.year && this->month > right.month)
		return true;
	else if (this->year == right.year && this->month == right.month && this->day > right.day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& right)const
{
	if ((*this) > right == false)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& right)const
{
	if (this->month == right.month && this->day == right.day && this->year == right.year)
		return true;
	else
		return false;
}

bool Date::operator!=(const Date& right)const
{
	if ((*this) == right == false)
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& right)const
{
	if ((*this) > right || (*this) == right)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& right)const
{
	if ((*this) < right || (*this) == right)
		return true;
	else
		return false;
}