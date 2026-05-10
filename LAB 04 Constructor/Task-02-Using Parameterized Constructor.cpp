#include<iostream>
using namespace std;

class BankAccount {
	public:
	string accountNumber;
	string accountHolder;
	double balance;
	
	BankAccount (string accountNumber,string accountHolder, double balance){
		this->accountNumber = accountNumber;
		this->accountHolder = accountHolder;
		this->balance = balance;
	}
	
	void showAccountDetail(){ 
		
		cout << "====== Account Details ======"<< endl;
		
		
		
		cout << "\nAccount Number = " << accountNumber << endl;
		cout << "Account Holder = " << accountHolder << endl;
		cout << "Balance = " << balance << endl;
	}
	
};
int main (){
	BankAccount D ("PK0309800780100", "Muhammad Awais", 10000);
	D.showAccountDetail();
	return 0;
	
}
