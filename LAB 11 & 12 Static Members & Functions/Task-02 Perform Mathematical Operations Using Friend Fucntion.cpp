#include<iostream>
using namespace std;

class Distance{
	private:
		int feet, inches;
	public:
		Distance (int f, int i){
			
			feet = f;
			inches = i;
		}
		
		// Declaration of friend function	
	friend void addDistance(Distance d1, Distance d2);
};

	void addDistance (Distance d1, Distance d2){
		
		int totalFeet = d1.feet + d2.feet;
		int totalInches = d1.inches + d2.inches;
		
		cout << "\n\tTotal Disance = " << totalFeet <<" Feet " 
			<< totalInches << " Inches " << endl;
	}
int main (){
	Distance d1(8, 4);
	Distance d2(2, 8);
	
	// calling friend function
	addDistance(d1, d2);
	
	return 0;
}

