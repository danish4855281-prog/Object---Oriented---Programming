#include<iostream>
using namespace std;

class Box{
	private:
		int length;
	public:
		Box (int l) : length(l){}
			
		
	// declaration of friend function
	friend void displayLength (Box b);
	
};
 	// definition of friend function
	void displayLength (Box b){
		
		cout << "Length : " << b.length << endl;
	}	
int main (){
	Box b(12);
	displayLength (b);	// Access private member
	
	return 0;
}
