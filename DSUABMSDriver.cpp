#include <iostream>
#include "DSUABMS.h"

using namespace std;
	
int main(){
	
	Caller call;
	DSUABMS system;
	system.setCaller(&call);
	
	system.loginMenu();
	
		
	
	return 0;
}