#include<iostream>
using namespace std;

class Product {
//	private: 
		string name;
		float price;
	
	public:	
		Product (string n, float p){
		
		name = n;
		price = p;
	}
	
	void display_product(){
		cout << "\tProduct Name : " << name << endl;
		cout << "\tPrice : $" << price << endl;
	}
	
//	string getname(){return name;}
//	float getprice(){return price;}
//		
};

class Electronics : public Product {
	private:
	
		int  warantyYears;
	
	public:	
	Electronics (string n, float p, int y) : Product (n, p){
		
		warantyYears = y;
	}
	
	void display_electronis(){
		
		
		display_product();
		cout << "\tWaranty Years : " << warantyYears << endl;
	}
	
//	int getyears(){return warantyYears;}
};

int main (){
	
	Electronics e("Laptop", 40000, 4);
	cout << "\n\t<-------- Display Electronic Details ---------> \n" <<endl;
	
	e.display_electronis();		
	return 0;
}
