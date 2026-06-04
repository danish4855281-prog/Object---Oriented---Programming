#include<iostream>
using namespace std;

class Employee {
	public:
		
		virtual double calculateSalary(){
			cout << "\tBase Employee salary calculation called" << endl;
			return 0;	
		}
		
		virtual ~Employee(){}
};

class PermanentEmployee : public Employee {
	private:
		double basicSalary;
		int bonus;
		
	public:
		PermanentEmployee (double basicSalary, int bonus){
			
			this->basicSalary = basicSalary;
			this->bonus = bonus;
		}
		
	double calculateSalary() override {
		
		return basicSalary + bonus;
	}	
};

class ContractEmployee : public Employee {
	private:
		int hourlyRate, hoursWorked;
		
	public:
		ContractEmployee(int hourlyRate, int hoursWorked){
				
				this->hourlyRate = hourlyRate;
				this->hoursWorked = hoursWorked;
		}
		
	double calculateSalary () override {
	
		return hourlyRate * hoursWorked;
	}	
};

int main (){

	Employee *e;
	
	PermanentEmployee pe (20000.01, 2000);
	ContractEmployee ce (1500, 23);
	
	e = &pe;
	cout << "\n\tPermanent Employee Salary is: " << e->calculateSalary() << endl;
	
	e = &ce;
	cout << "\n\tContract Employee Salary is: " << e->calculateSalary() << endl;
	
	return 0;
}
