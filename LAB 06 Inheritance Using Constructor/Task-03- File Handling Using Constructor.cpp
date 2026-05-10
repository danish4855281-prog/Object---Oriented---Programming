#include<iostream>
using namespace std;

class File {
	
	public:
		File(){
			
			cout << "File is opened!" << endl;
		}		
		
		~File(){
			
			cout << "File is Closed!" << endl;
		}
};

class TextFile : public File {
	public:
		TextFile(){
			
			cout << "Text File is loading!" << endl;
		}
		
		~TextFile(){
			
			cout << "TextFile is Loaded!" << endl;
		}
};

int main (){
	{
	// Create object of Derived Class
	TextFile tf;
	
	cout << "\n Object is in Scope." << endl;
	}
	
	cout << "\n Object is Destroyed." << endl;
	 return 0;
}



