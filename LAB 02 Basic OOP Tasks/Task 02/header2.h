#ifndef HEADER2_H
#define HEADER2_H
#include <iostream>
using namespace std;

class Rectangle {
	public:
		int length;
		int width;
		void setDimensions();
		void area();
		void perimeter();
		
};
	void Rectangle :: setDimensions(){
		cout << "Enter length of Rectangle : ";
		cin >> length;
		cout << "Enter width of Rectangle : ";
		cin >> width;
	}
	void Rectangle :: area(){
	float area = length * width;
		cout << "Area of Rectangle is : "<< area << endl;
	}
	void Rectangle::perimeter(){
	float perimeter = 2*(length + width);
		cout << "Perimeter of Rectangle is : "<< perimeter;
	} 
	#endif
