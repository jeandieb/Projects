#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Product
{
	friend ostream& operator<<(ostream&, const Product&);

	private:
		string productName;
		double price;
		string category;
		string description;

	public:
		Product(string = "UNKNOWN PRODUCT", double = 1.0, string = "NONE", string = "NONE");
		static Product creatProduct();
		Product& setName(string);
		Product& setPrice(double);
		Product& setCategory(string);
		Product& setDescription(string);
		string getName() const;
		double getPrice() const;
		string getCategory() const;
		string getDescription() const;
};


#endif // PRODUCT_H