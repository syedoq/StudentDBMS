#include<iostream>
#include "Caller.h"
using namespace std;

void Caller::call(string fullName, string cellNumb){
	
	this -> fullName = fullName;
	this -> cellNumb = cellNumb;

	cout << endl << "       Calling Student :  " << fullName ;
	cout << endl <<"       Cell Number :   " << cellNumb << endl;

}
