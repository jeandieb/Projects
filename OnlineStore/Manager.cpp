#include "Manager.h"
#include <string>

using namespace std;

Manager::Manager(string userN, string passW, string name, string email) : User(userN, passW, name, email)
{

}


Product Manager::addProduct()
{
	Product pro;
	pro = pro.creatProduct();
	return pro;
}

Manager Manager::CreatManager()
{	
	User temp;
	   
	Manager temp2;
	temp2 = temp.creatUser();// casting from User to Manager (converting)
	return temp2;
}

Manager& Manager::operator=(const User& right)
{
	this->setUserName(right.getUserName());
	this->setPassword(right.getPassword());
	this->setName(right.getName());
	this->setEmail(right.getEmail());
	return *this;
}

//bool Manager::editProductName()
//{
//	string temp;
//	cout << "Enter a new name for the product";
//	getline(cin, temp);
//	
//
//}
