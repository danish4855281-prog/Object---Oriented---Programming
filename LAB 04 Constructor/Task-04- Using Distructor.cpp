#include<iostream>
using namespace std;

class Locker{
public:
	Locker(){
		cout << "Locker allocated to customer (Construtor Call)" << endl;	// Constructor Called
	}
	~Locker(){
		cout << "Locker returned by customer (Distructor Call)"<< endl;	// Distructor Called
	}
	
};
int main (){
	cout << "\n\t=== Object Without Using Pointer ===\n"<< endl;
	{
		Locker L1;
	}
	
	cout << endl;
	
	cout << "\n\t--- Object Using Pointer ---\n" << endl;
	Locker* ptr = new Locker();
	delete ptr;
	
	return 0;
}
		




