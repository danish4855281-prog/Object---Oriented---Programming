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
int main (){
	
	int n;
	cout << "How many student you want to enter : ";
	cin >> n;
	
	student s[n];

	for (int i = 0; i < n; i++){
		
		cout << "Enter details of student " << i + 1 <<" : " << endl;
		cout << "Enter First Name : ";
		cin >> s[i].first_name;
		cout << "Enter Last Name : ";
		cin >> s[i].last_name;
		cout << "Enter Roll Number : ";
		cin >> s[i].roll_number;
		cout << "Enter Marks : ";
		cin >> s[i].marks;
}
	cout << "\n---Display Student Info---" << endl;
	for (int i = 0; i < n; i++){
		s[i].displaystudentinfo();
	}

	return 0;
}
