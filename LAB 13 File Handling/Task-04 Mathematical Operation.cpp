#include<iostream>
#include<string>
using namespace std;

template <typename T>

class Calculate{
	private:
		T a, b;
	public:
		Calculate(T x, T y){
			a = x;
			b = y;
		}
	T add(){
		
		return a + b;
	}
	T subt(){
		
		return a - b;
	}
	T mult(){
		
		return a * b;
	}
}; 
int main(){
	
	cout << "\n\t<---- Integer Values Calculation ---->\n" << endl;
	Calculate <int> intcal(12, 5);
	
	cout << "Addition : " << intcal.add() << endl;
	cout << "Subtraction : " << intcal.subt() << endl;
	cout << "Multiplication : " << intcal.mult() << endl;
	
	cout << endl;
	
	
	cout << "\n\t<---- Double Values Calculation ---->\n" << endl;
	Calculate <double> doublecal(12.5, 5.15);
	
	cout << "Addition : " << doublecal.add() << endl;
	cout << "Subtraction : " << doublecal.subt() << endl;
	cout << "Multiplication : " << doublecal.mult() << endl;
	
	return 0;
	
}








