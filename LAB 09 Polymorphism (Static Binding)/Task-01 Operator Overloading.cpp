#include<iostream>
using namespace std;

class Distance {
	private:
		int feet;
		int inches;
		
	public:
		Distance (int feet, int inches){
			this->feet = feet;
			this->inches = inches;
		}	
		
	bool operator == (Distance d){
		if (this->feet == d.feet && this->inches == d.inches){
			
			return true;
			
		}else{
			
			return false;
		}
		
	}
};

int main () {
	Distance d1 (3, 5);
	Distance d2 (3, 5);
	
	if (d1 == d2){
		
		cout << "\n\t Distance D1 and D2 are Equal" << endl;
	}
	else {
		
		cout << "\n\t Distance D1 and D2 are Not Eqaul" << endl;
	}
	
	return 0;
	
}
