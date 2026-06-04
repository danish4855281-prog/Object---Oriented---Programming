#include<iostream>
#include<fstream>

using namespace std;

int main(){
	
	ifstream fin("notes.txt");
	
	string line;
	int linecount = 0;
	while(getline(fin, line)){
	
	
		linecount++;
	}
	
	fin.close();
	cout << "Total Lines : " << linecount << endl;
	
	return 0;
	
}
