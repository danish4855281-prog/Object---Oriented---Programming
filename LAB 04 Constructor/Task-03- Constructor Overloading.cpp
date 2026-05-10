#include<iostream>
using namespace std;

class Rectangle {
private:
	float length;
	float width;

public :
	
	Rectangle(){
		length = 1.0;
		width = 1.0;
	}	
	
	Rectangle(float l, float w){
		length = l;
		width = w;
	}
	
	Rectangle (float s){
		length = s;
		width = s;
		
	}
	float area(){
		return length * width;
	}
	void display (){
		cout << "<--------- Area Of Rectangle ----------->\n"<< endl;
		
		cout << "Length : " << length << " , Width : "<< width << endl;
		cout << "Area of Rectangle is = " << area() << endl;
	}
	
		
};
int main (){
	
	// Default Constructor
	Rectangle R1;
		cout << "\n\t Default Constructor." << endl;
	R1.display();
	
	Rectangle R2(1.0, 1.0);
	cout << "\n\t Parameterized Constructor." << endl;
	R2.display();

	Rectangle R3(1.0);
	cout << "\n\t Single Parameterized Constructor." << endl;
	R3.display();
	
	return 0;
}

