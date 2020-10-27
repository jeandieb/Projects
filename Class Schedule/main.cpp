/*
CSIS 137
MIDTERM PROJECT
Jean Dieb, Christopher Bedrosian, Tommy Ibrahimi
*/

#include <iostream>
#include "CourseSchedule.h"
#include <string>
#include <Windows.h>
#include <cwchar>
using namespace std;


int main()
{
	//increase font size in console
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.Y = 25;                  // Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	string stuName, semName;
	Date semStart, semEnd;
	int numberOfClasses;
	char choice;
	Course required;
	cout << "Enter you name please:" << endl;
	getline(cin, stuName);
	cout << "Enter the semester you're entering a schedule for:" << endl;
	getline(cin, semName);
	cout << "Enter the day the semester starts: (mm/dd/yyyy) " << endl;
	cin >> semStart;
	cout << "Enter the day the semester ends: (mm/dd/yyyy)" << endl;
	cin >> semEnd;
	cout << "Enter the number of classes you would like to enroll in:" << endl;
	cin >> numberOfClasses;

	Semester mySem(semName, semStart, semEnd);
	CourseSchedule mySchedule(stuName, mySem, numberOfClasses);

	do
	{


		cout << "\n\nCOURSE ENTERY MENU FOR " << mySem << endl
			<< "--------------------------------------------------------------------------" << endl
			<< "A) Enter a New Course" << endl
			<< "B) Remove a Course" << endl
			<< "C) Print a Semester Schedule" << endl
			<< "Q) Quit the Program" << endl;

		cin >> choice;

		switch (choice)
		{
		case 'A':
		case 'a':
			if (mySchedule.getNumCourses() < mySchedule.getMaxSize())
			{
				required = required.getCourse(required);
				mySchedule.addCourse(required);
			}
			else 
				cout << "\nthe number of added classes exceeded the maximum.\nDelete one of the classes then try again" << endl;

			break;

		case 'B':
		case 'b':
			if (mySchedule.getNumCourses() != 0)
			{
				int remove;
				cout << "enter the number representing the course you wish to remove:" << endl;
				cin >> remove;
				mySchedule.removeCourse(remove);
			}
			else
				cout << "you don't have any courses to remove" << endl;
			break;

		case 'C':
		case 'c':

			cout << mySchedule;
			break;

		case 'Q':
		case 'q':
			cout << "you have chosen to quit the program" << endl;
			break;
		default:
			cout << "\aInvalid Selection!" << endl;
			break;
		}
	} while (choice != 'Q' && choice != 'q');

	system("pause");
	return 0;
}