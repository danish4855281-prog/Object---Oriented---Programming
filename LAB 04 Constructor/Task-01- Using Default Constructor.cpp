#include<iostream>
using namespace std;
class Employee{
	private:
		int ID;
		string name;
		float salary;
		
	public:
		Employee(){
			ID = 0;
			name = "Not Assign";
			salary = 0.01;
		}
		
	void displayDetail(){
		cout << "Name = " << name << endl;
		cout << "ID = " << ID << endl;
		cout << "Salary = " << salary << endl;
	}
	
};
int main (){
	Employee E;
	E.displayDetail();
	return 0;
}
