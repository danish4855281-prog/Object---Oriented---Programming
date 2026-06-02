#include "FirstClassPassenger.h"

FirstClassPassenger::FirstClassPassenger(string passengerID, string name,
                                         string contactNumber, string email,
                                         bool dedicatedConcierge)
    : Passenger(passengerID, name, contactNumber, email) {
    this->dedicatedConcierge = dedicatedConcierge;
}

FirstClassPassenger::~FirstClassPassenger() {}

// First class gets 60kg baggage allowance
int FirstClassPassenger::getBaggageAllowance() const {
    return 60;
}

// First class earns 3x loyalty points
double FirstClassPassenger::getLoyaltyMultiplier() const {
    return 3.0;
}

// First class gets 90% refund on cancellation
double FirstClassPassenger::getRefundPercentage() const {
    return 90.0;
}

string FirstClassPassenger::getPassengerClass() const {
    return "FirstClass";
}

bool FirstClassPassenger::getDedicatedConcierge() const {
    return dedicatedConcierge;
}

void FirstClassPassenger::displayDetails() const {
    cout << "========================================" << endl;
    cout << "       FIRST CLASS PASSENGER DETAILS    " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Class    : First Class" << endl;
    cout << "Baggage  : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund   : " << getRefundPercentage() << "%" << endl;
    cout << "Points X : " << getLoyaltyMultiplier() << "x" << endl;
    cout << "Concierge: " << (dedicatedConcierge ? "Yes" : "No") << endl;
    cout << "========================================" << endl;
}
