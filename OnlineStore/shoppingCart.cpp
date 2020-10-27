#include "shoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart()
{
	
}

bool ShoppingCart::addProduct(Product passed)
{
	
	productList.push_back(passed);
	return true;
}

bool ShoppingCart::removeProduct(int num)
{
	productList.erase(productList.begin() + (num));

	return true;
}

double ShoppingCart::calcTotal()
{
	double total = 0.0;
	for (int i = 0; i < productList.size(); i++)
	{
		total += productList[i].getPrice();
	}
	return total;
}


void ShoppingCart::printList() const
{
	for (int i = 0; i < productList.size(); i++)
	{
		cout << "#" << i << endl << productList[i] << endl;
	}
}