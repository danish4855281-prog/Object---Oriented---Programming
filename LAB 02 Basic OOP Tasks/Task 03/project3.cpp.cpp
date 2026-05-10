#include<iostream>
#include "header3.h"
using namespace std;


int main (){
	Voter v1;
	cout << "Enter Voter Name : ";
	getline(cin, v1.name);
	cout << "Enter Voter Age : ";
	cin >> v1.age;
	if (v1.age >= 18){
		cout <<"\n\t"<< v1.name << " is Eligible for Vote!";
	}else{
		cout << "\n\t"<<v1.name << " is Not Eligible for Vote!";
	}
	v1.isEligible();
	return 0;
}
