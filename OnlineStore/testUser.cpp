#include "User.h"

using namespace std;

int main()
{
	User NEW;
	NEW = User::creatUser();
	cout << NEW.getStatus() << endl;
	NEW.logIn();
	cout << NEW.getStatus() << endl;
	NEW.logOut();
	cout << NEW.getStatus() << endl;
	system("pause");



}