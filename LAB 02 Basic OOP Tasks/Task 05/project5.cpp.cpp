#include<iostream>
#include "header5.h"
using namespace std;

int main (){
	Calculator cal;
	char choice;
	cout << "Enter First Number : ";
	cin >> cal.num1;
	cout << "Enter Second Number : ";
	cin >> cal.num2;
	
	cout << "\n\t <------- Choose An Operation -------->\n"<< endl;
	cout << "(+) For Addition.\n(-) For Subtraction.\n(*) For Multiplication.\n(/) For Division.";
	cout << "\nEnter Your Choice : ";
	cin >> choice;
	
	cout << "\n\t<------- Result -------->\n"<< endl;
	switch (choice){
		case '+':
			cout << cal.add();
			break;
		case '-':
			cout << cal.subtract();
			break;
		 case '*':
 			cout << cal.multiply();
			break;
		case '/':
			cout << cal.divide();
			break;
		default :
			cout << "Invalid Choice!";
			break;
	}
	cout << endl;
	
	return 0;
}	
