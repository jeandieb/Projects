#include "OnlineStore.h"

using namespace std;

int main()
{
//	Manager johnny;
	//Shopper sara;
	OnlineStore myStore;	
	myStore.addManager();
	//myStore.addManager();

	string nameee;
	cout << "enter the user name for your account:";
	cin >> nameee;
	cin.ignore();
	myStore.returnManager(nameee).logIn();

	//johnny = myStore.addManager();
	//sara = myStore.addShopper();
//	myStore.showManagers();
//	myStore.deleteManager("jeandib");
//	myStore.showManagers();
	myStore.creatProductList(0);
	myStore.showProductList();


	//Shopper Sara("sara", "1234", "asd", "adf");
	myStore.addShopper();
	int number;
	cout << "which number to add to shoppig card?" << endl;
	cin >> number;
	myStore.returnShopper("sara").addItemtoCart(myStore.getProductFromList(number));
	//Sara.addItemtoCart(myStore.getProductFromList(number));
	myStore.returnShopper("sara").re

	cout << "SHOPPING CART HAS: " << endl;
	myStore.returnShopper("sara").printShoppingCart();
	//Sara.printShoppingCart();

}