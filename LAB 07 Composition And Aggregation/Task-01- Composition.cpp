#include<iostream>
using namespace std;

class Display {
	private:
		double lastValue;
	public:
		Display(){
			lastValue = 0.0;
		}
		
		void show(double value){
			lastValue = value;
			cout << "Result : " << lastValue << endl;
		}
		
		double getLastValue()const {
			
			return lastValue;
		}	
};

class Calculator {
	private:
		Display screen;
	public:
		Calculator(){}
		
		void add(double a, double b){
			double result = a + b;
			screen.show(result);
		}
		
		void multiply(double a, double b){
			double result = a * b;
			screen.show(result);
		}
		
		void showPreviousResult() const {
		
			cout << "Previous result : " << screen.getLastValue() << endl;		
		}
};

int main (){
	Calculator cal;
	
	cal.add(12, 8);
	cal.multiply(4, 8);
	cal.showPreviousResult();
	
	return 0;
}










