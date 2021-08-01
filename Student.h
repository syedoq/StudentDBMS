#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student{
       
	private:
		string fullName;
		string roll;
		string address;
		string cellNumb;
		bool isDeleted;
	
	public:
		Student();
		void setFullName(string temp);
		void setRollNumb(string temp);
		void setAddress(string temp);
		void setCellNumb(string temp);
		void setDeleted();
        string getFullName()const;
        string getRollNumb()const;
        string getAddress()const;
		string getCellNumb()const;  
		bool getDeleted()const;		
};

#endif