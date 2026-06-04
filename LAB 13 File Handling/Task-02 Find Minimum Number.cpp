#include<iostream>
using namespace std;

template <typename T>

	T fMin(T a, T b){
		if (a < b){
			
			return a;
			
		}else{
			
			return b;
		}	
	}
int main(){
	int ans = fMin(12, 4);
	cout <<"Smallest Number is : " << ans << endl;
	return 0;
}
