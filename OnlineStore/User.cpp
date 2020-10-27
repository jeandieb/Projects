#include "User.h"
#include <string>
using namespace std;

User::User(string Uname, string pa, string na, string Email)
{
	
	userName = Uname;
	password = pa;
	name = na;
	emailAddress = Email;
	setStatus("Offline");
}

User User::creatUser()
{
	string Uname, pa, na, Email;
	cout << "Enter a userName for your new account" << endl;
	getline(cin, Uname);
	cout << "Enter a Password for your new account" << endl;
	getline(cin, pa);
	cout << "Enter your name please" << endl;
	getline(cin, na);
	cout << "Enter your email address please" << endl;
	getline(cin, Email);
	User Creat(Uname, pa, na, Email); 
	Creat.setStatus("Offline");

	return Creat;
}

User& User::setUserName(string na)
{
	userName = na;
	//cout << "username has been set to " << na << endl;

	return *this;
}

User& User::setPassword(string pa)
{
	password = pa;
	//cout << "Password has been set to " << pa << endl;

	return *this;
}

User& User::setStatus(string stat)
{
	status = stat;
	return *this;
}
string User::getUserName() const
{
	return userName;
}

string User::getPassword() const
{
	return password;
}


string User::getStatus() const
{
	return status;
}

User& User::setName(string na)
{
	name = na;
	return *this;
}

string User::getName() const
{
	return name;
}

User& User::setEmail(string Email)
{
	emailAddress = Email;
	return *this;
}

string User::getEmail() const
{
	return emailAddress;
}


bool User::logIn()
{
	string na, pa;
	do
	{
		cout << "Enter your username (case sensetive)" << endl;
		getline(cin, na);
		cout << "Enter your password (case sensetive)" << endl;
		getline(cin, pa);
		if (na == userName && pa == password)
		{
			cout << "you're logged in!" << endl;
			status = "Online";
			return true;
		}
		else
		{
			cout << "The username or password you entered are incorrect\nTry again" << endl;
		}
	} while (status == "Offline");

}

bool User::logOut()
{
	if (this->getStatus() == "Online")
	{
		this->status = "Offline";
		cout << "you're logged out" << endl;
	}
	else
		cout << "You're not logged in.\nLog in first, then try to log out" << endl;
	return true;
}