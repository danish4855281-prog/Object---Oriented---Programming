#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
using namespace std;

class Product{
	private:
		string name;
		double price;
		int quantity;
	public:
		void setName(string a){
			name = a;
			if (!a.empty()){
				cout << "Error! Name can't be empty." << endl;
			}else{
				cout <<"Name = " << a << endl;
			}
		}
		void setPrice(double b){
			price = b;
			if (b <= 0){
				cout << "Error! Price can't be less than 0." << endl;
			}else{			}

				cout << "Price = " << b << endl;
		}
			void setQuantity(int c){
			quantity = c;
			if (c < 0){
				cout << "Error! Quantity can't be less than 0." << endl;
			}else{
				cout << "Quantity = " << c << endl;
			}
		}
		
		string getName(){return name;}
		double getPrice(){return price;}
		int getQuantity(){return quantity;}
		
};
#endif

	

