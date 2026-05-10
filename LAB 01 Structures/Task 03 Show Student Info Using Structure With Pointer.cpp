#include<iostream>
using namespace std;

struct student{

	string first_name;
	string last_name;
	int roll_number;
	float marks;
	
	void displaystudentinfo(){
	
		cout << "\n<======== YOUR INFO ========>\n" << endl;
		cout << "Full Name : " << first_name << " " << last_name << endl;
		cout << "Roll Number : " << roll_number << endl;
		cout << "Marks : " << marks << endl;
	}
};

int main(){
	
	student s1;
	student *ptr = &s1;
	
		cout << "Enter First Name : ";
		cin >> ptr->first_name;
		cout << "Enter Last Name : ";
		cin >> ptr->last_name;
		cout << "Enter Roll Number : ";
		cin >> ptr->roll_number;
		cout << "Enter Marks : ";
		cin >>ptr->marks;
		ptr->displaystudentinfo();

		return 0;
		
}	
	

