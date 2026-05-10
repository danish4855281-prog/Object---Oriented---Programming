#include<iostream>
#include "header4.h"
using namespace std;

int main (){
	Temperature Converter;
	cout << "Enter value in Celcius : ";
	cin >> Converter.celcius;
	Converter.covertTofahrenheit();
	Converter.displayResult();
	return 0;
}
