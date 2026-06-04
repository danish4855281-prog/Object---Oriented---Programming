#include<iostream>
using namespace std;

class BankAccount{
	private:
		string accountHolderName;
		double balance;	
	public:
		static int totalAccounts;
	
	BankAccount(string n, double b){
		
		accountHolderName = n;
		balance = b;	
		totalAccounts++;	// increment for every object
	}
	
	void display(){
		
		cout << "Account Holder : " << accountHolderName << endl;
		cout << "Balance : " << balance << endl;
		cout << endl;
	}
//	static void displayTotalAccounts(){
//		
//		cout << "\tTotal Accounts : " << totalAccounts << endl;
//	}
};

	// definition outside of class
	int BankAccount :: totalAccounts = 0;

int main (){
	
	cout << "\n\t==== Account Holder Details ====\n" << endl;
	
	BankAccount acc1("Danish", 20000);
	BankAccount acc2("Shan", 12000);
	BankAccount acc3("Laila", 23000);
	
	acc1.display();
	acc2.display();
	acc3.display();
	
	cout << "Total Accounts : " << BankAccount :: totalAccounts << endl;
	
	return 0;
}	

