#include "Shopper.h"

using namespace std;


Shopper::Shopper(string userN, string passW, string name, string email) : User(userN, passW, name, email)
{

}


Shopper Shopper::CreatShopper()
{
	User temp;

	Shopper temp2;
	temp2 = temp.creatUser();// casting from User to Manager
	return temp2;
}

Shopper& Shopper::operator=(const User& right)
{
	this->setUserName(right.getUserName());
	this->setPassword(right.getPassword());
	this->setName(right.getName());
	this->setEmail(right.getEmail());
	return *this;
}


void Shopper::addItemtoCart(Product passed)
{
	cart.addProduct(passed);
}

void Shopper::printShoppingCart() const
{
	cart.printList();
}

double Shopper::returTotalPrice()
{
	double temp = cart.calcTotal();
	return temp;
}