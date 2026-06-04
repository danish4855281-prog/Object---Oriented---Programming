#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream fin("notes.txt");
	ofstream fout("copy.txt");
	
	string line;
	while(getline(fin,line)){
		
		fout << line << endl;
	}
	
	fin.close();
	fout.close();
	
	cout << "File Copied Successfully."<< endl;
	
	return 0;
}
