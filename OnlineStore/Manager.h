#ifndef MANAGER_H
#define MANAGER_H
#include "User.h"
#include "Product.h"

class Manager : public User
{
	private:
		string managerName;
		string managerEmailAddress;

	public:
		Manager(string = "NoUserName", string = "0000", string = "noName", string = "noEmail");
	    Manager CreatManager();
		Product addProduct();
		//bool removeProduct(int);
		//bool editProductName();
		//bool edtiProductPrice();
		//bool editProductCategory();
		//bool editDescription();

		Manager& operator=(const User&);
};

#endif // MANAGER_H