#include "AddressBook.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

AddressBook::AddressBook(){
	
	size = 10;			//DEFAULT SIZE

	ifstream read;
	read.open("Database.txt");
	
	read >> count;
	
	if(count>0 && count<100){			//IF COUNT IS NOT A GARBAGE VALUE
		student = new Student[count+size];
	}
	else{
		count = 0;
		student = new Student[size];
	}
	read.close();	
}
AddressBook::~AddressBook(){

	delete[] student;
	student = NULL;
}
void AddressBook::copyFileSavedStudents(){		//READING STUDENT SAVED IN FILE
	
	ifstream read;
	ofstream write;
	string temp;
	read.open("Database.txt");
	
	getline(read,temp);

	for(int i=0;i<count;i++){
		
		getline(read,temp);
		student[i].setFullName(temp);
		
		getline(read,temp);
		student[i].setRollNumb(temp);
		
		getline(read,temp);
		student[i].setAddress(temp);
		
		getline(read,temp);
		student[i].setCellNumb(temp);
	}	
	read.close();
	write.open("Database.txt");
	write.close();

}
void AddressBook::addStudent(){
									//ADD A NEW STUDENT
	string temp;
	static int i = 0;
	
	if(count < (count+size)-i){
		
		getchar();
		cout << endl << "Enter Full Name of Student :  ";
		getline(cin,temp);
		student[count].setFullName(temp);	

		cout << endl << "Enter Roll Number of Student :  ";
		getline(cin,temp);
		student[count].setRollNumb(temp);

		cout << endl << "Enter Address of Student :  ";
		getline(cin,temp);
		student[count].setAddress(temp);

		cout << endl << "Enter Cell Number of Student :  ";
		getline(cin,temp);
		student[count].setCellNumb(temp);
		count++;
		i++;
		cout << endl;
	}
	else{
		size *= 3;						//IF THERE IS NO SPACE LEFT IN ARRAY RECREATE
		recreateDynamicArray();
		addStudent();
	}
}
void AddressBook::recreateDynamicArray(){
	
	Student* tempArr = new Student[count];
	
	for(int i=0;i<count;i++){
		tempArr[i] = student[i];			//SHALLOW COPY OF STUDENT OBJECT TO TEMP OBJECT
	}
	delete[] student;
	
	student = new Student[size+count];		//RECREATING NEW DYNAMIC ARRAY
	
	for(int i=0;i<count;i++){
		student[i] = tempArr[i];			//SHALLOW COPY OF TEMP TO ORIGINAL ARRAY
	}
	
	delete[] tempArr;
}
void AddressBook::print(){	//PRINTING IN CONSOLE
	int check = 0;
	
	cout << endl << endl << "---------------Printing All Students Data-------------------" << endl;
	for(int i=0;i<count;i++){
		if(student[i].getDeleted() == false){			//FALSE = IF STUDENT IS NOT DELETED
			cout << endl << endl;

			cout << endl << "Full Name    =  ";
			cout << student[i].getFullName();

			cout << endl << "Roll Number  =  ";
			cout << student[i].getRollNumb();

			cout << endl << "Address      =  ";
			cout << student[i].getAddress();

			cout << endl << "Cell Phone   =  ";
			cout << student[i].getCellNumb();
			check = 1;
		}
		
	}
	if(!check){
	
		cout << endl << endl << endl << "No Record Found  !!!!";
		cout << endl << endl;
	}
}
int AddressBook::searchStudent(string search){
	
	int i = 0;
	for(i=0;i<count;i++){
		if(student[i].getDeleted() == false){	
			if(student[i].getRollNumb() == search){
				return i;
			}
		}	
	}		
	
	return -1;
	
}
void AddressBook::printSingleStudent(int x){		//PRINTING IN CONSOLE

	cout << endl;
	cout << endl << "          * Full Name   =  " << student[x].getFullName();
	cout << endl << "          * RollNumber  =  " << student[x].getRollNumb();
	cout << endl << "          * Address     =  " << student[x].getAddress();
	cout << endl << "          * Cell Number =  " << student[x].getCellNumb();
	
	cout << endl;

}
void AddressBook::updateStudent(int count){			//UPDATE STUDENT ADDRESS AND CELL NUMBER
	
	string temp;
	cout << endl << "Enter New Address (Leave field empty for no update) :  ";
	getchar();
	getline(cin,temp);
	
	if(temp == ""){
	
	}
	else if(temp == " "){
	
	}
	else{
		student[count].setAddress(temp);
		cout << endl << "Address Updated Successfully...";
		getchar();
	}
	
	cout << endl << "Enter New Cell Number (Leave field empty for no update) :  ";
	getline(cin,temp);
	if(temp == ""){
	
	}
	else if(temp == " "){
	
	}
	else{
		student[count].setCellNumb(temp);
		cout << endl << "Cell Number Updated Successfull...";
		getchar();
	}

}
void AddressBook::setDeleteStatus(int count){			 //SET DELETE TO TRUE
	student[count].setDeleted();
}
void AddressBook::getDeleteStatus(int count)const{
	student[count].getDeleted();
}
void AddressBook::printInFile(){		//WHEN PRESSED SAVE AND EXIT
	
	ofstream write;
	int k = 0;
	write.open("Database.txt");
	
	for(int i =0;i<count;i++){					//COUNTING TOTAL NUMBER OF STUDENT 
		if(student[i].getDeleted()==false){		//ECLUDING DELETED STUDENT
			k++;
		}
	}
		
	write << k;
			
	for(int i=0;i<count;i++){
		if(student[i].getDeleted() == false){	
		
			write << endl << student[i].getFullName();

			write << endl;
			write << student[i].getRollNumb();

			write << endl ;
			write << student[i].getAddress();

			write << endl;
			
			write << student[i].getCellNumb();
		}
		
	}
	write.close();	

}
string AddressBook::getStudentName(int x)const{

	return student[x].getFullName();
}
string AddressBook::getStudentCellNumb(int x)const{

	return student[x].getCellNumb();
}




