#include<iostream>
using namespace std;

class Person {
	
	public:
		string name;
		int age;
		
	void display_person(){
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		
	}
					
};

class Employee : public Person {
	
	public: 
		string employee_id;
		
	void display_employee(){
		cout << "ID : " << employee_id << endl;
		
	}
};

class Manager : public Employee {
	
	public:
		string department;
		
	void display_manager(){
		cout << "Department : " << department << endl;
		
	}
};

int main (){
	Manager m; 		// creating object of manager
	
	cout << "\n\t----- Enter Details ------\n" << endl;
	// taking inputs from user
	cout << "Enter Name : ";
	getline(cin, m.name);
	cout << "Enter Age : ";
	cin >> m.age;
	
	
	cout << "Enter ID : ";
	cin >> m.employee_id;
	cout << "Department : ";
	cin >> m.department;
	
	
	cout << "\n\t----- Display Details ------\n" << endl;
	// calling funtion's
	m.display_person();
	m.display_employee();
	m.display_manager();
	
	return 0;
	
}
