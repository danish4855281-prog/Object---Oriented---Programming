#ifndef HEADER1_H
#define HEADER1_H
#include <iostream>
using namespace std;

class Student {
	public:
	string name;
	int rollNumber;
	float marks;
	
	void getData(){
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter Roll Number : ";
		cin >> rollNumber;
		cout << "Marks : ";
		cin >> marks;
	}
	void displayData(){
		cout << "\n---Your Data----\n";
		cout << "Name : " << name << endl;
		cout << "Roll Number : " << rollNumber << endl;
		cout << "Marks : " << marks << endl;
		
		
	}
};
#endif
