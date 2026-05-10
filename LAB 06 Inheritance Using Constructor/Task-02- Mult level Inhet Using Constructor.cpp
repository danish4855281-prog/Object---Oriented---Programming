//#include<iostream>
//using namespace std;
//
//class Vehical {
//	public:
//		string model;
//		
//	Vehical (string m){
//		
//		model = m;
//		cout << "Constructor of Vehical class is Calling" << endl;
//	}
//	void display_vehical(){
//		
//		cout << "Model : " << model << endl;
//	}
//				
//};
//
//class Car : public Vehical {
//	public:
//		string engine;
//		
//	Car (string m, string n) : Vehical (m){
//		
//		engine = n;
//		cout << "Constructor of Car Class is Calling" << endl;	
//	}
//	
//	void display_car(){
//		
//		display_vehical();
//		cout << "Engine : " << engine << endl;
//	}
//};
//
//class ElectricCar : public Car{
//	public:
//		string battery;
//		
//	ElectricCar	(string m, string n, string b) : Car (m, n){
//		
//		battery = b;
//		cout << "Constructor of Electric Car is Calling" << endl;
//	}
//	
//	void display_ElectricCar(){
//		
//		display_car();
//		cout << "Battery : " << battery <<  endl;
//		
//	}
//};
// int main(){
// 	ElectricCar EletCar("Toyota" , "1GR" , "50000KWH");
// 	
// 	cout << "\n\t <=+++++++ Display Electric Car Details +++++++=>\n" << endl;
// 	
// 	// function's calling
// 	EletCar.display_ElectricCar();
// 	
// 	return 0;
// 	
// 	
// }
#include <iostream>
using namespace std;

class Vehicle{
	private:
		string brand;
	public:
		Vehicle(string b){
			brand = b;
			cout<<"Constructor of Vehicle Class is Calling.."<<endl;
		}
		
		void display_Vehicle(){
			cout<<"Brand : "<<brand<<endl;
		}
				
};

class Car : public Vehicle{
	private:
		int lights;
	public:
		Car(string b, int l) : Vehicle(b){
			lights = l;
			cout<<"Constuctor of Car Class is Calling.."<<endl;
		}
		
		void display_Car(){
			display_Vehicle();
			cout<<"No. of Lights : "<<lights<<endl;
		}
		
};

class ElectricCar : public Car{
	private:
		int battery;
	public:
		ElectricCar(string b, int l, int batt) : Car(b,l){
			battery = batt;
			cout<<"Constructor of ElectricCar Class is Calling.."<<endl;
		}
		
		void display_ElectricCar(){
			display_Car();
			cout<<"Battery Power : "<<battery<<" KWH"<<endl;
		}
		
};

int main(){
	ElectricCar ec1("TOYOTA", 6 , 2000);
	
	cout<<endl;
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~Vehicle Details~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
	ec1.display_ElectricCar();
	
	return 0;
}
