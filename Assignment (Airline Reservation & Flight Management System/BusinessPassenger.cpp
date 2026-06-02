#include "BusinessPassenger.h"

BusinessPassenger::BusinessPassenger(string passengerID, string name,
                                     string contactNumber, string email,
                                     bool loungeAccess)
    : Passenger(passengerID, name, contactNumber, email) {
    this->loungeAccess = loungeAccess;
}

BusinessPassenger::~BusinessPassenger() {}

// Business gets 40kg baggage allowance
int BusinessPassenger::getBaggageAllowance() const {
    return 40;
}

// Business earns 2x loyalty points
double BusinessPassenger::getLoyaltyMultiplier() const {
    return 2.0;
}

// Business gets 75% refund on cancellation
double BusinessPassenger::getRefundPercentage() const {
    return 75.0;
}

string BusinessPassenger::getPassengerClass() const {
    return "Business";
}

bool BusinessPassenger::getLoungeAccess() const {
    return loungeAccess;
}

void BusinessPassenger::displayDetails() const {
    cout << "========================================" << endl;
    cout << "        BUSINESS PASSENGER DETAILS      " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Class    : Business" << endl;
    cout << "Baggage  : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund   : " << getRefundPercentage() << "%" << endl;
    cout << "Points X : " << getLoyaltyMultiplier() << "x" << endl;
    cout << "Lounge   : " << (loungeAccess ? "Yes" : "No") << endl;
    cout << "========================================" << endl;
}
