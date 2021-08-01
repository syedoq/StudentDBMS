#ifndef DSUABMS_H
#define DSUABMS_H
#include "AddressBook.h"
#include "Caller.h"

using namespace std;

class DSUABMS{


	private :
		string userName;	
		string password;
		bool isLogin;
		AddressBook address;
		Caller* caller;
	public :
		DSUABMS();
		void setCaller(Caller* temp);
		void loginMenu();
		void aspexMenu();
		void searchMenuTitle();
		void searchMenu();
};



#endif