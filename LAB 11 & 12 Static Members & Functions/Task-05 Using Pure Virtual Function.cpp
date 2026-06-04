#include<iostream>
using namespace std;

class HospitalStaff{
	protected:
		string staffName;
	public:
		HospitalStaff(string name){
			staffName = name;
		}
	virtual void performDuty() = 0;
};
class Doctor : public HospitalStaff {
	public:
		Doctor (string name) : HospitalStaff(name){}
			
		void performDuty(){
			cout << "\t--> Doctor " << staffName << " is examining patients.\n" << endl;
		}	
};
class Nurse : HospitalStaff{
	public:
		Nurse (string name) : HospitalStaff(name){}
		
	void performDuty(){
		cout << "\t--> Nurse " << staffName << " is taking care of patients.\n" << endl;
	}
};
class Receptionist : HospitalStaff {
	public:
		Receptionist (string name) : HospitalStaff(name){}
		
		void performDuty(){
			cout << "\t--> Receptionist " << staffName << " is managing appoinments." << endl;
		}
};
int main(){
	
	cout << "\n\t=== Show Hospital Staff Duty ===\n"<< endl;
	
	Doctor d("Suhaib");
	Nurse n("Taniya");
	Receptionist r("Laila");
	
	d.performDuty();
	n.performDuty();
	r.performDuty();
	
	return 0;
}
	

