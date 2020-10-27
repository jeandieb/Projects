#ifndef SHOPPER_H
#define SHOPPER_H
#include "shoppingCart.h"
#include "User.h"

class Shopper : public User
{
	private:
		ShoppingCart cart;

	public:
		Shopper(string = "NoUserName", string = "0000", string = "noName", string = "noEmail");
		Shopper CreatShopper();
		Shopper& operator=(const User&);

		void addItemtoCart(Product);
		void printShoppingCart() const;
		double returTotalPrice();

};



#endif //	SHOPPER_H