#include<iostream>
#include<string>
using namespace std;

template<typename T>

class Pair{
	private:
		T first, second;
	public:
		Pair (T first, T second){
			
			this->first = first;
			this->second = second;
		}
	T getFirst() {return first;}
	T getSecond() {return second;}
	
	
	T display(){
		
		cout << "First = " << first << " : " << "Second = " << second << endl;
	}
};
int main (){
	Pair <int> p1(13, 15);
	Pair <double> p2(2.5, 3.14);
	Pair <string> p3("Danish", "Shamsher");
		
	p1.display();
	p2.display();
	p3.display();
	
	return 0;
	
	
}
