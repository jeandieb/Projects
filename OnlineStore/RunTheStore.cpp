#include "OnlineStore.h"
#include <string>

using namespace std;

int main()
{
	int choice,choice2, choice3, choice4;
	OnlineStore myStore;
	string Uname;

	do
	{
		cout << "ONLINE STORE\n-------------------" << endl
			<< "1) Creat an Account\n"
			<< "2) Log In\n"
			<< "3) Quit" << endl
		
			<< "\nMake a selection:" << endl;
			cin >> choice;
			cin.ignore();

			switch (choice)
			{
				case 1:
					do 
					{
						cout << "1) Shopper\n2) Manager\n3) Back\nMake a selection:" << endl;
						cin >> choice2;
						cin.ignore();
						if (choice2 == 1)
						{
							myStore.addShopper();//create shopper
							break;
						}
						else if (choice2 == 2)
						{
							myStore.addManager();//creat manager
							break;
						}
						else if (choice2 == 3)
						{
							cout << "Loading..." << endl;
						}
						else
						{
							cout << "Invalid selection" << endl;
						}
					} while (choice2 != 3);
					break;

				case 2:
					cout << "Are you 1) Shopper or 2) Manager?" << endl;
					cin >> choice2;
					cin.ignore();
					if (choice2 == 1)// LOG IN SHOPPER
					{
						cout << "Enter your username To search for your account (case sensetive): ";
						getline(cin, Uname);
						//cin.ignore();
						if (myStore.returnShopper(Uname).logIn() == true)
						{
							do
							{
								cout << "1) Add to Cart\n2) Show Shopping Cart\n3) Log Out\n4) Delete Account" << endl
									<< "Make a selection: ";
								cin >> choice4;
								cin.ignore();
								if (choice4 == 1)
								{
									cout << "Welcome to our inventory:" << endl;
									myStore.showProductList();
									do
									{
										cout << "Select the item you want to add to your shopping using the appropriate number" << endl;
										cin >> choice3;
										if (choice3 >= 0 && choice3 <= myStore.getProductListSize())
										{
											myStore.returnShopper(Uname).addItemtoCart(myStore.getProductFromList(choice3));
											cout << "type (-1) when you are done" << endl;
										}
										else if (choice3 == -1)
										{
											cout << "saving..." << endl;
										}
										else
										{
											cout << "Invalid! choose a number from the list please" << endl;
										}
									} while (choice3 != -1);
									cout << "Shopping cart is loading..." << endl;
									myStore.returnShopper(Uname).printShoppingCart();
									cout << "total price: " << myStore.returnShopper(Uname).returTotalPrice() << endl;
								}
								else if (choice4 == 2)
								{
									cout << "Shopping cart is loading..." << endl;
									myStore.returnShopper(Uname).printShoppingCart();
									cout << "total price: " << myStore.returnShopper(Uname).returTotalPrice() << endl;
								}
								else if (choice4 == 3)
								{
									cout << "Logging Out..." << endl;
									myStore.returnShopper(Uname).logOut();
								}
								else if (choice4 == 4)
								{
									myStore.deleteShopper(Uname);
									break;
								}
								else
									cout << "Invalid Selection" << endl;
							} while (choice4 != 3);
						}
					}
					else if (choice2 == 2)// LOG IN MANAGER
					{
						cout << "Enter your username To search for your account (case sensetive): ";
						getline(cin, Uname);
						//cin.ignore();
						
						if (myStore.returnManager(Uname).logIn() == true)
						{
							
							do
							{
								cout << "1) Add New Item\n2) Remove Item\n3) Delete Account\n4) Show Inventory\n0) Log Out" << endl;
								cin >> choice3;
								cin.ignore();
								if (choice3 == 1)
								{
									myStore.creatProductList(Uname);
								}
								else if (choice3 == 2)
								{
									int pick;
									myStore.showProductList();
									cout << "Enter the number of the item you wish to delete" << endl;
									cin >> pick;
									cin.ignore();
									myStore.removeItemFromList(pick);

								}
								else if (choice3 == 3)
								{
									myStore.deleteManager(Uname);
								}
								else if (choice3 == 4)
								{
									cout << "Showin the Inventory..." << endl;
									myStore.showProductList();
								}
								else if (choice3 == 0)
								{
									cout << "Logging Out" << endl;
									myStore.returnManager(Uname).logOut();
								}
								else
									cout << "invalid selection" << endl;
							} while (choice3 != 0);

						}
					}
					break;
				
				case 3:
					cout << "Thank you for using our servis.\nExiting..." << endl;
					break;
			}
	} while (choice != 3);

}