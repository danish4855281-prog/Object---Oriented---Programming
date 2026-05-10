#include<iostream>
using namespace std;

class Calculator {
	public :
		double add(double a, double b){
			return a + b;
		}
		
		double multiply(double a, double b){
			return a * b;
		}
		
};

class Student {
	Calculator* cal;
	public:
		Student(Calculator* c){
			cal = c;
		}
		
		void solvedAddition(double a, double b){
			if (cal){
				cout << "Addition Result : " << cal->add(a, b) << endl;
			}
		}
		
		void solvedMultiply(double a, double b){
			if (cal){
				cout << "Multiplication result : " << cal->multiply(a,b) << endl;
			}
		}
};

int main (){
	Calculator myCalculator;
	
	Student s1(&myCalculator);
	Student s2(&myCalculator);
	
	cout << "---- Student 1 ----\n" << endl;
	s1.solvedAddition(7, 2);
	s1.solvedMultiply(3, 5);
	
	cout << "\n----- Student 2 -----\n" << endl;
	s2.solvedAddition(10, 8);
	s2.solvedMultiply(6, 5);
	
	return 0;
	
}
