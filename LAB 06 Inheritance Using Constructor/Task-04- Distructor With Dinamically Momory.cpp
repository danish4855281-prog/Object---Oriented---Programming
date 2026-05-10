#include<iostream>
using namespace std;

class Device {
	public:
		string *deviceName;
		string *deviceID;
		
	Device (string name, string id ){
		
		deviceName = new string(name);
		deviceID = new string (id);	
		
		cout << "Base Class Constructor Call. " << endl;
	}	
	
	virtual ~Device (){
		
		delete deviceName;
		delete deviceID;
		
		cout << "Base Class Distructor Call" << endl;
	}		
};

class Sensor : public Device {
	public:
		string *sensor_type;
		float *sensor_value;
		
	Sensor (string name, string id, string type, float value) : Device (name, id){
		
		sensor_type = new string (type);
		sensor_value = new float (value);
		
		cout << "Derived Class Constructor Call." << endl;
	} 	
	
	virtual ~Sensor (){
		
		delete sensor_type;
		delete sensor_value;
		
		cout << "\nDerived Class Distructor Call." << endl;
	}
	
	void display_data(){
		
		cout << "\n\t ----- Display Device Details -----\n" << endl;
		
		cout << "Device Name : " << *deviceName << endl;
		cout << "Device ID : " << *deviceID << endl;
		cout << "Sensor Type : " << *sensor_type << endl;
		cout << "Sensor Value : " << *sensor_value << endl;
	}	
};

int main (){
	Sensor *s1 = new Sensor ("IoT-Gateway", "G-101", "Temperature", 22.5);
	
	s1->display_data();
	
	delete s1;
	return 0;
}

