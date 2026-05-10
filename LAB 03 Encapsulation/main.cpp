#include<iostream>
#include"product.h"
int main (){
	Product p;
	p.setName(" ");	
	p.setPrice(-50);
	p.setQuantity(-2);
	
	p.setName("Laptop");
	p.setPrice(100);
	p.setQuantity(2);
	
	cout << "Price : $" << p.getPrice() << endl;
	cout << "Product : " << p.getName() << endl;
	cout << "Quantity : " << p.getQuantity() << endl;
	return 0;
}
