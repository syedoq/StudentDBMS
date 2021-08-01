#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Student.h"

using namespace std;
class AddressBook{

	private :
		Student* student;
		int count;
		int size;
	
	public :
		AddressBook();	
		~AddressBook();	
		void copyFileSavedStudents();
		void recreateDynamicArray();
		void addStudent();
		void print();				//PRINTING ALL STUDENT IN CONSOLE
		void printSingleStudent(int x);
		int searchStudent(string search);
		void searchMenu();
		void updateStudent(int count);
		void setDeleteStatus(int count);
		void getDeleteStatus(int count)const;
		void printInFile();
		string getStudentName(int x)const;
		string getStudentCellNumb(int x)const;
};

#endif