#include<iostream>
using namespace std;

struct student{
	
	string first_name;
	string last_name;
	int roll_number;
	float marks;
	
	void displaystudentinfo(student S){
	
		cout << "<======== YOUR INFO ========>\n" << endl;
		cout << "Full Name : " << S.first_name << " " << S.last_name << endl;
		cout << "Roll Number : " << S.roll_number << endl;
		cout << "Marks : " << S.marks << endl;
	}
};
int main (){
	student S;
	S.first_name = "Danish";
	S.last_name = "Shaheen";
	S.roll_number = 2026;
	S.marks = 1050;
	S.displaystudentinfo(S);
	return 0;
}

