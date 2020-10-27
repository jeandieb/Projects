#ifndef USER_H
#define USER_H

#include <iostream>
using std::string;
class User
{
	private:
		string userName;
		string password;
		string status;
		string name;
		string emailAddress;
		


	public:
		User(string = "NoUserName", string = "0000", string = "noName", string = "noEmail");
	    User creatUser();
		string getUserName() const;
		string getStatus() const;
		string getName() const;
		string getPassword() const;
		string getEmail() const;
	    bool logIn(); 
		bool logOut(); 
		User& setUserName(string = "noUserName");
		User& setPassword(string = "0000");
		User& setName(string = "noName");
		User& setEmail(string = "noEmail");
		User& setStatus(string);
};

#endif //USER_H