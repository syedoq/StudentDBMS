#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(){
	fullName = "XYZ";
	roll = "XYZ";
	address = "XYZ";
	cellNumb = "XYZ";
	isDeleted = false;
	
}

void Student::setFullName(string temp){	
	fullName = temp;
}
void Student::setRollNumb(string temp){
	roll = temp;
}
void Student::setAddress(string temp){
	address = temp;
}
void Student::setCellNumb(string temp){
	cellNumb = temp;
}
void Student::setDeleted(){
	isDeleted = true;
}
string Student::getFullName()const{
	return fullName;
}
string Student::getRollNumb()const{
	return roll;
}
string Student::getAddress()const{
	return address;
}
string Student::getCellNumb()const{
	return cellNumb;
}
bool Student::getDeleted()const{
	return isDeleted;
}