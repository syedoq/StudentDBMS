#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include "DSUABMS.h"
#include "AddressBook.h"
#include "Caller.h"


using namespace std;

DSUABMS::DSUABMS(){
		userName = "";
		password = "";
		isLogin = false;

}

void DSUABMS::setCaller(Caller *temp){
	caller = temp;
}
void DSUABMS::loginMenu(){
	
	ifstream read;
	string fname, fpwd;
	
	read.open("user.txt",ios::app);			
	read >> fname;							//LOGIN ID AND PASSWORD
	read >> fpwd;
	read.close();
	
	system("cls||clear");
	cout << endl << endl;
		
	cout << "      -----------------------------------------------------------------------       " << endl;
	cout << "      Welcome to DHA SUFFA UNIVERSITY ADDRESS BOOK MANAGEMENT SYSTEM (CS@DSU)       " << endl;
	cout << "      -----------------------------------------------------------------------       " ;
	cout << endl << endl <<"                                Username : ";
	cin >> userName;
	cout << endl << "                                Password : ";
	cin >> password;
	cout << endl << endl;
	
	if(fname == userName){			//IF SUCCESSFUL LOGIN COPY STUDENT WHICH ARE SAVED IN FILE
		if(fpwd == password){
			isLogin = true;
			address.copyFileSavedStudents();
			aspexMenu();						//MAIN MENU WILL BE DISPLAYED
		}
	}
	if(!isLogin){
		cout << endl << "   Invalid userName or Password combination. System is exiting... Have a nice day... " << endl << endl << endl;
	}
	
}
void DSUABMS::searchMenuTitle(){
	
	if(isLogin){
		system("cls||clear");
		cout << endl << endl << endl;
		cout << endl << "           -----------------------------------------------------------";
		cout << endl <<"           DHA SUFFA UNIVERSITY ADDRESS BOOK MANAGEMENT SYSTEM (CS@DSU)";
		cout << endl << "           -----------------------------------------------------------";
		cout << "                                           Welcome Mr." << userName ;
		cout << endl << "                                  Search Menu"  << endl;
	}
}
void DSUABMS::searchMenu(){
	
	if(isLogin){
		
		cout << endl << endl;
		cout << "                  - Update Student (press 'U')" << endl;
		cout << "                  - Delete Student (press 'D')" << endl;
		cout << "                  - Call Student (press 'C')" << endl;
		cout << "                  - Back (press 'B')" << endl;

		cout << endl << endl;
	}
}
void DSUABMS::aspexMenu(){
	
	if(isLogin){
		
		int loop = 0, found = -1;
		char choice;
		string search;

		while(1){
			loop = 0;						//<--USED FOR SEARCH MENU LOOP SENTINEL VALUE
			system("cls||clear");
			if(userName[0] >=97 && userName[0] <= 123){		//CHANGE THE FIRST WORD OF USERNAME
				userName[0] -= 32; 							//TO UPPER CASE
			}

			cout << endl << endl << endl;
			cout << endl << "           -----------------------------------------------------------";
			cout << endl <<"           DHA SUFFA UNIVERSITY ADDRESS BOOK MANAGEMENT SYSTEM (CS@DSU)";
			cout << endl << "           -----------------------------------------------------------";
			cout << "                                           Welcome Mr." << userName ;
			cout << endl << endl;

			cout << "              - Add Student (press 'A')" << endl;
			cout << "              - Search Student (press 'S')" << endl;
			cout << "              - Print All Student (press 'P')" << endl;
			cout << "              - Save & Exit (press 'E')" << endl;
			cout << "              - Exit w/o saving (press 'X')" << endl;

			cout << endl << endl;
			cout << "Input Choice :  ";
			cin >> choice;

			if(choice == 'A'){
				address.addStudent();
				cout << endl << "Student Added Successfully......";
				getchar();
			}
			else if(choice == 'S'){

				cout << endl << "Input Roll Number to search student :  ";
				getchar();
				getline(cin,search);
				//getchar();
				while(loop != 1){

					searchMenuTitle();
					found = address.searchStudent(search);
					if(found==0 || found>0){
						address.printSingleStudent(found);

						searchMenu();

						cout << "Input Choice :  ";
						cin >> choice;
					}
					else{
						cout << endl << "No such record found...";
						getchar();
						loop = 1;
					}
					if(choice == 'B'){
						loop = 1;
					}
					if(choice == 'U'){
						address.updateStudent(found);
					}
					if(choice == 'D'){
						cout << endl << "Are You Sure You Want to Delete [Y/n] :";
						cin >> choice;
						if(choice == 'Y'){
							address.setDeleteStatus(found);
							getchar();	
							cout << endl << "Deleted Successfully.... ";
							getchar();	
							loop = 1;
						}
					}
					if(choice == 'C'){
						caller->call(address.getStudentName(found),address.getStudentCellNumb(found));
						cout << endl << "    Student Called..";
						getchar();
						getchar();
						
					}

				}	
			}
			else if(choice == 'P'){
				system("cls||clear");
				address.print();
				getchar();
				cout << endl << endl  << "Successfully Printed......";
				getchar();
			}
			else if(choice == 'E'){
				address.printInFile();
				cout << endl << "Session Saved....Thank You for using our program." << endl ;
				cout << endl << "System Exiting....";
				break;
			}
			else if(choice == 'X'){
				cout << endl << endl;
				cout << "Are you sure you want to exit..Previous changes will not be saved..[Y/n] :  ";
				cin >> choice;
				if(choice == 'Y'){
					break;
				}
			}

			cout << endl;
		}
	}	
}
