#include "OnlineStore.h"

using namespace std;

Manager OnlineStore::addManager()
{
	Manager one;
	one = one.CreatManager();
	managerList.push_back(one);
	return one;
}

Shopper OnlineStore::addShopper()
{
	Shopper one;
	one = one.CreatShopper();
	shopperList.push_back(one);
	return one;
}


void OnlineStore::creatProductList(string na)
{
	char choice = ' ';
	do
	{
		Product one;
		one = returnManager(na).addProduct();
		productList.push_back(one);
		cout << "To add another product press 'y'. Press 'q' to quit" << endl;
		cin >> choice;
		cin.ignore();
	} while (choice != 'q');
}

void OnlineStore::showProductList()
{
	for (int i = 0; i < productList.size(); i++)
	{
		cout << "#" << i << endl << productList[i] << endl;
	}
}


Product OnlineStore::getProductFromList(int num) const
{
	Product temp;
	temp = productList[num];
	return temp;
}

bool OnlineStore::deleteShopper(string na)
{
	bool exist = false;
	char choice;
	for (int i = 0; i < shopperList.size(); i++)
	{
		if (shopperList[i].getUserName() == na)
		{
			exist = true;
			cout << "account was found" << endl
				<< "to delete your account, confirm log in" << endl;
			if (shopperList[i].logIn() == true)
			{
				cout << "Are you sure you want to delete your account? \nAll information and orders will be permanently lost (Y or N)" << endl;
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					cout << "account for " << shopperList[i].getUserName() << " has been deleted" << endl;
					shopperList.erase(shopperList.begin() + i);
					return true;
				}
				else if (choice == 'N' || choice == 'n')
				{
					cout << "Deletion was cancelled" << endl;
					return false;
				}
				else
				{
					cout << "invalid selection" << endl;
					cout << "Deletion was cancelled" << endl;
					return false;
				}
			}
		}
		
	}
	if (exist == false)
	{
		cout << "Shopper accout for " << na << " does not exist" << endl;
	}
}

bool OnlineStore::deleteManager(string na) 
{
	bool exist = false;
	char choice;
	for (int i = 0; i < managerList.size(); i++)
	{
		if (managerList[i].getUserName() == na)
		{
			exist = true;
			cout << "account was found" << endl
				<< "to delete your account, confirm log in" << endl;

			if (managerList[i].logIn() == true)
			{
				cout << "Are you sure you want to delete your account? \nAll information will be permanently lost (Y or N)" << endl;
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					cout << "account for " << managerList[i].getUserName() << " has been deleted" << endl;
					managerList.erase(managerList.begin() + i);
					return true;
				}
				else if (choice == 'N' || choice == 'n')
				{
					cout << "Deletion was cancelled" << endl;
					return false;
				}
				else
				{
					cout << "invalid selection" << endl;
					cout << "Deletion was cancelled" << endl;
					return false;
				}
			}
		}

	}
	if (exist == false)
	{
		cout << "Manager accout for " << na << " does not exist" << endl;
	}


}

Manager& OnlineStore::returnManager(string na) 
{
	bool found = false;
	for (int i = 0; i < managerList.size(); i++)
	{
		if (managerList[i].getUserName() == na)
		{
			found = true;
			return managerList[i];
		}
	}
	if (found == false)
	{
		cout << "Mangager account for " << na << " does not exist" << endl;
	}
}

Shopper& OnlineStore::returnShopper(string na)
{
	bool found = false;
	for (int i = 0; i < shopperList.size(); i++)
	{
		if (shopperList[i].getUserName() == na)
		{
			found = true;
			return shopperList[i];
		}
	}
	if (found == false)
	{
		cout << "Shopper account for " << na << " does not exist" << endl;
	}
}


//void OnlineStore::showManagers() const
//{
//	for (int i = 0; i < managerList.size(); i++)
//	{
//		cout <<"the username::  " << managerList[i].getUserName() << "  password:  " << managerList[i].getPassword() << endl;
//	}
//	cout << "ITS WORKING!" << endl;
//}

int OnlineStore::getProductListSize() const
{
	return productList.size();
}

bool OnlineStore::removeItemFromList(int n)
{
	cout << "Item " << productList[n].getName() << " was deleted" << endl;
	productList.erase(productList.begin() + n);
	return true;

	
}