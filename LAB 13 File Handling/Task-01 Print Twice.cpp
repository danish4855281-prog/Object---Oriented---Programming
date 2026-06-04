#include<iostream>
using namespace std;

template <typename T>

void printTwice(T val){
	
	cout << val << endl;
	cout << val << endl;
}

int main (){
	
	printTwice(20);
	printTwice(2.1);
	printTwice("Danish");
	
	return 0;
	
}

