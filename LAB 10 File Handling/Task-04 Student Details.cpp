#include<iostream>
#include<fstream>
using namespace std;

int main (){
	
	// Write
	ofstream fout("student.txt");
	fout << "Name\tRoll No" << endl;
	fout << "Danish\t40" << endl;
	fout << "Ammar\t38" << endl;
	fout << " Arif\t42" << endl;
	
	fout.close();
	
	// Read
	ifstream fin("student.txt");
		string line;
		
		cout << "\n\t----- Student Data -----"<<endl;
		while(getline(fin, line)){
			
			fout << line << endl;
		}
		
		fin.close();
		cout << "\n\tFile is opened Successfully in Reading Mode." << endl;
	
	return 0;
}
