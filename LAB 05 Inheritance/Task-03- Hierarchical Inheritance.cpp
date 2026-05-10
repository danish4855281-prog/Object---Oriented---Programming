#include<iostream>
using namespace std;

class Employee {
	
	public:
		string name;
		double salary;
		
		Employee(string n, double s){
			name = n;
			salary = s;
		}	
		
	void display_employee(){
		
		cout << "Name : " << name << endl;
		cout << "Salary : " << salary << endl;	 
	}
};

class Developer : public Employee {
	public: 
		string programming_language;
		
		Developer(string n, double s, string pl) : Employee(n,s){
		programming_language = pl;	
	}
		
	void display_developer(){
		
		display_employee();
		cout << "Programming Language : " << programming_language << endl;	
	}
};

class Designer : public Employee {
	public: 
		string design_tool;
		
		Designer(string n, double s, string dt) : Employee(n,s){
			design_tool = dt;
		}	
		
	void display_designer(){
		
		display_employee();
		cout << "Design Tool : " << design_tool << endl;
		
	}
};

int main(){
	
	// Create Developer Object
	Developer d ("Danish", 60000, "C++");
	cout << "\n\t ====== Developer Info ======\n" << endl;
	d.display_developer();
	
	
	// Create Designer Object
	Designer g ("Danish", 60000, "Photoshop");
	cout << "\n\t ====== Designer Info ======\n" << endl;
	g.display_designer();
	
	return 0;
		
}


