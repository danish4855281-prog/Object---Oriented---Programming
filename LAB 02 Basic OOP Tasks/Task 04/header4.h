#ifndef HEADER4_H
#define HEADER4_H
#include <iostream>
using namespace std;

class Temperature{
	public:
		double celcius;
	
	double covertTofahrenheit(){
		
	 	return (celcius * 9.0 / 5.0) + 32.0;
	}
	double displayResult(){
	double fahrenheit = covertTofahrenheit();
		cout << celcius << " degrees celcius is equal to " << fahrenheit << " degrees fahrenheit." << endl;
	}	
};
#endif
