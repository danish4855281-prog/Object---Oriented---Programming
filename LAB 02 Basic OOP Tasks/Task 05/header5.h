#ifndef HEADER5_H
#define HEADER5_H
#include <iostream>
using namespace std;

class Calculator {
public:
	float num1;
	float num2;	
	
	
	float add(){
		return num1 + num2;
	}
	float subtract(){
		return num1 - num2;	
	}
	float multiply(){
		return num1 * num2;
	}
	float divide(){
		if (num2 == 0){
			cout << "Division by zero is Undefined!";
		}
		return num1 / num2;
	}
};
#endif
