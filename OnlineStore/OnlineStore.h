#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include <iostream>
#include <vector>
#include "Product.h"
#include "Manager.h"
#include "Shopper.h"

using std::vector;

class OnlineStore
{
	private:
		vector <Manager> managerList;
		vector <Shopper> shopperList;
		vector<Product> productList;

	public:
	    Manager addManager();	
		Shopper addShopper();
		void creatProductList(string);
		void showProductList();
		Product getProductFromList(int) const;
		bool deleteShopper(string);
		bool deleteManager(string);
		Manager& returnManager(string);
		Shopper& returnShopper(string);
		int getProductListSize() const;
		bool removeItemFromList(int);
		//void showManagers() const;
};


#endif //ONLINESTORE_H