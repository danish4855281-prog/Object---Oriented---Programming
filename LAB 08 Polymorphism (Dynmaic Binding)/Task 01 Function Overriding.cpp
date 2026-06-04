#include<iostream>
using namespace std;

class Shape {
	public:
		
		virtual double area(){}
};

class Rectangle : public Shape {
	private:
		double length, width;
		
	public:
		Rectangle (double l, double w){
			
			length = l;
			width = w;
		}
		
	double area() override  {
		
		return length * width;	
	}	
};

class Circle : public Shape {
	private:
		double radius;
		
	public:
		Circle (double r){
			
			radius = r;
		}	
	double area() override {
			
			return 3.14 * radius * radius;
	}	
};

int main () {
	Shape *s;
	
	Rectangle r (0.25, 2.5);
	Circle c (3.5);
	
	s = &r;
	cout << "\n\t Area Of Rectangle Is : " << s->area() << endl;
	
	s = &c;
	cout << "\n\t Area Of Circle Is : " << s->area() << endl;
	
	return 0;
}





