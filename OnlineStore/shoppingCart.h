#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "Product.h"
#include <vector>

using std::vector;
 
class ShoppingCart
{
	private:
		vector <Product> productList;

	public:
		ShoppingCart();
		bool addProduct(Product);
		bool removeProduct(int);
		double calcTotal();
		void printList() const;
};



#endif // SHOPPINGCART_H