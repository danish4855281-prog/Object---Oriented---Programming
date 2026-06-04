#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main (){
	
	// Create and Write
	ofstream fout("notes.txt");
	fout << "\nWelcom to C++ File Handling " << endl;
	fout << "I am a Software Engineering Student" << endl;
	fout << "This is Object Oriented Programming" << endl;
	
	fout.close();
	
	
	// Open and Read
	ifstream fin("notes.txt");
	
	string line;
		cout << "\nFile Contents \n" << endl; 
	
	while(getline(fin, line)){
		
		cout << line << endl;
	}
	
	fin.close();
	
	
	// Append Name and Roll No
	
	ofstream appfile("notes.txt, ios::app");
	
	appfile << "\nName : Danish Iqbal" << endl;
	appfile << "Roll No : 2025-SE-40" << endl;
	
	appfile.close();
	
	cout <<"\nName and Roll No Appended Successfully." << endl;
	
	return 0;
	
}
