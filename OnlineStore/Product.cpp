#include "Product.h"
#include <string>

using namespace std;


ostream& operator<<(ostream& output, const Product& passed)
{
	output << "Product name: " << passed.getName() << endl << "Price $" << passed.getPrice() << endl
		<< "Category: " << passed.getCategory() << endl << "Describtion:" << endl << passed.getDescription() << endl;

	return output;
}

Product::Product(string pName, double pri, string categ, string descri)
{
	setName(pName);
	setPrice(pri);
	setCategory(categ);
	setDescription(descri);
}

Product Product::creatProduct()
{
	string temp;
	double pri;
	Product TEMP;
	
	cout << "Enter the product name" << endl;
	getline(cin, temp);
	TEMP.setName(temp);
	
	cout << "Enter the price" << endl; //ADD EXCEPTION HANDELING TO ALLOW ONLY DOUBLES!
	cin >> pri;
	TEMP.setPrice(pri);
	cin.ignore(); // to catch /n from price

	cout << "Enter the product's category" << endl;
	getline(cin, temp);
	TEMP.setCategory(temp);
	
	cout << "Enter a description" << endl;
	getline(cin, temp);
	TEMP.setDescription(temp);

	cout << TEMP.getName() << " has been added successfully" << endl;

	return TEMP;

}

Product& Product::setName(string pName)
{
	productName = pName;
	
	return *this;
}

Product& Product::setPrice(double pri)
{
	do
	{
		if (pri > 0)
			price = pri;
		else
		{
			cout << "price can't be less than 0\nEnter the product price " << endl;
			cin >> pri;
			price = pri;
		}
	} while (pri < 0);

	return *this;
}

Product& Product::setCategory(string categ)
{
	category = categ;

	return *this;
}

Product& Product::setDescription(string descri)
{
	description = descri;

	return *this;
}

string Product::getName() const
{
	return productName;
}

double Product::getPrice() const
{
	return price;
}

string Product::getCategory() const
{
	return category;
}

string Product::getDescription() const
{
	return description;
}