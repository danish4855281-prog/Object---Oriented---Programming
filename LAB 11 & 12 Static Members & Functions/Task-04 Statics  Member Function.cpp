#include<iostream>
using namespace std;

class Employee {
	private:
		string employeeName;
		string employeeID;
	public:
		static string companyName;
	
	Employee (string employeeName, string employeeID){
		
		this->employeeName = employeeName;
		this->employeeID = employeeID;
	}
	
	~Employee(){}
	
	void displayData(){
		
		cout << "\tEmployee Name : " << employeeName << endl;
		cout << "\tEmployee ID : " << employeeID << endl;
//		cout << "Company Name : " << companyName << endl;
		cout << endl;
	}
	static void displayCompanyInfo(){
		
		cout << "\nCompany Name : " << companyName << endl;
	}
};

	// define static member outside class
	string Employee :: companyName = "Awais Rathore Tech";
int main (){
	
	cout << "\n\t==== Employee Details =====\n" << endl;
	
	Employee emp1("Danish", "D101");
	Employee emp2("Arif", "A102");
	
	// Access static function using class Name
	Employee :: displayCompanyInfo();
		
	emp1.displayData();
	emp2.displayData();
	
	
	
	return 0;		
}
