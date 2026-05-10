#include<iostream>
using namespace std;


// Person Class 
class Person {
	
	public:
		string name;
		int age;
		
	void display_person_info(){
		cout << "Name : " << name <<  endl;
		cout << "Age : " << age << endl;
	}
};

//	Student Class
class Student : public Person {		// Name and Age Inherited From Person's Class
	
	public:
		string student_id;
		
	void display_student_info(){
		cout << "Student ID : " << student_id << endl;
	}
};

int main (){
	Student s1;
	
	//	Taking Inputs From User
	cout << "Enter Name : ";
	getline (cin, s1.name);
	
	cout << "Enter Age : ";
	cin >> s1.age;
	
	cout << "Enter Student ID : ";
	cin >> s1.student_id;
	
	cout << "\n\t<----- Student Info ----->\n" << endl;
	
	// Function's Calling
	s1.display_person_info();
	s1.display_student_info();
	
	return 0;
	
}

