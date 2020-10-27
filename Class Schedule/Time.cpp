/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Time.h"

ostream& operator<<(ostream& output, const Time& passed)// print the standard time
{
	output << ((passed.getHour() == 0 || passed.getMinute() == 12) ? 12 : passed.getHour() % 12) << ":"
		<< setfill('0') << setw(2) << passed.getMinute() << (passed.getHour() < 12 ? " AM" : " PM");
	return output;
}

istream& operator>>(istream& input, Time& passed)//(HH:MM PM||AM)
{
	input >> passed.hour;
	input.ignore();
	input >> passed.minute;
	input.ignore();
	string period;
	input >> period;
	passed.standardToUniversal(period);
	return input;
}

double operator-(const Time& left, const Time& right)
{
	double returned;
		double h, m;
		h = left.getHour() - right.getHour();
		m = left.getMinute() - right.getMinute();
	
		if (h < 0)  // get the absuloute value
		{
			h = (h* -1);
		}
		if (m < 0) // get the absuloute value
		{
			m = (m * -1);
		}
		if (right.getMinute() > left.getMinute())
		{
			m = (left.getMinute() +60 ) - right.getMinute();
			h--;

		}
		returned = h + (m / 60);
		returned = ceil(returned * 100)/100;
		return returned;
}


//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
 setTime(hour, minute);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
 setHour(hour);
 setMinute(minute);

 return *this; 
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
  return *this;
}  

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
  minute = (m >= 0 && m < 24) ? m : 0;  //validates minute, if valid set to m, else set to 0
  return *this;
} 


/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}


/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
     cout << setfill('0') << setw(2) << hour << ":" 
          << setw(2) << minute << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" 
          << setfill ('0') << setw(2) << minute <<  (hour < 12 ? "AM" : "PM" ) << endl;
}

void Time::standardToUniversal(string PERIOD)
{
	if (PERIOD == "PM" || PERIOD == "pm")
	{
		this->hour += 12;
	}
}

//double Time::operator-(const Time& right)
//{
//	double returned;
//	double h, m;
//	h = this->getHour() - right.getHour();
//	m = this->getMinute() - right.getMinute();
//
//	if (h < 0)  // get the absuloute value
//	{
//		h = (h* -1);
//	}
//	if (m < 0) // get the absuloute value
//	{
//		m = (m * -1);
//	}
//	returned = h + (m / 60);
//	returned = ceil(returned * 100)/100;
//	return returned;
//}



