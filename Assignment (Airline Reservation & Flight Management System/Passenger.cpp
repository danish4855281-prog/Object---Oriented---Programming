#include "Passenger.h"

// Constructor — initializes common passenger data with validation
Passenger::Passenger(string passengerID, string name,
                     string contactNumber, string email) {

    if (passengerID.empty()) {
        cout << "Warning: Passenger ID cannot be empty. Setting to UNKNOWN." << endl;
        this->passengerID = "UNKNOWN";
    } else {
        this->passengerID = passengerID;
    }

    if (name.empty()) {
        cout << "Warning: Passenger name cannot be empty. Setting to UNKNOWN." << endl;
        this->name = "UNKNOWN";
    } else {
        this->name = name;
    }

    if (contactNumber.empty()) {
        cout << "Warning: Contact number cannot be empty." << endl;
        this->contactNumber = "N/A";
    } else {
        this->contactNumber = contactNumber;
    }

    if (email.empty()) {
        cout << "Warning: Email cannot be empty." << endl;
        this->email = "N/A";
    } else {
        this->email = email;
    }

    this->loyaltyPoints = 0;
}

Passenger::~Passenger() {}

// Adds loyalty points after a booking
void Passenger::addLoyaltyPoints(int points) {
    if (points > 0) {
        loyaltyPoints += points;
    }
}

// Deducts loyalty points (e.g. when redeeming)
void Passenger::deductLoyaltyPoints(int points) {
    if (points > 0 && points <= loyaltyPoints) {
        loyaltyPoints -= points;
    } else {
        cout << "Not enough loyalty points to deduct." << endl;
    }
}

// Getters
string Passenger::getPassengerID() const { return passengerID; }
string Passenger::getName() const { return name; }
string Passenger::getContactNumber() const { return contactNumber; }
string Passenger::getEmail() const { return email; }
int Passenger::getLoyaltyPoints() const { return loyaltyPoints; }

// Setters
void Passenger::setContactNumber(string contact) {
    if (contact.empty()) {
        cout << "Invalid contact number." << endl;
        return;
    }
    contactNumber = contact;
}

void Passenger::setEmail(string newEmail) {
    if (newEmail.empty()) {
        cout << "Invalid email." << endl;
        return;
    }
    email = newEmail;
}

// Operator << — prints basic passenger info
// Friend function so it can access protected members
ostream& operator<<(ostream& out, const Passenger& passenger) {
    out << "ID       : " << passenger.passengerID << endl;
    out << "Name     : " << passenger.name << endl;
    out << "Contact  : " << passenger.contactNumber << endl;
    out << "Email    : " << passenger.email << endl;
    out << "Points   : " << passenger.loyaltyPoints << endl;
    return out;
}
