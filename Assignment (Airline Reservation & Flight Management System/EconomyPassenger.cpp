#include "EconomyPassenger.h"

EconomyPassenger::EconomyPassenger(string passengerID, string name,
                                   string contactNumber, string email)
    : Passenger(passengerID, name, contactNumber, email) {}

EconomyPassenger::~EconomyPassenger() {}

// Economy gets 20kg baggage allowance
int EconomyPassenger::getBaggageAllowance() const {
    return 20;
}

// Economy earns 1x loyalty points
double EconomyPassenger::getLoyaltyMultiplier() const {
    return 1.0;
}

// Economy gets 50% refund on cancellation
double EconomyPassenger::getRefundPercentage() const {
    return 50.0;
}

string EconomyPassenger::getPassengerClass() const {
    return "Economy";
}

void EconomyPassenger::displayDetails() const {
    cout << "========================================" << endl;
    cout << "         ECONOMY PASSENGER DETAILS      " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Class    : Economy" << endl;
    cout << "Baggage  : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund   : " << getRefundPercentage() << "%" << endl;
    cout << "Points X : " << getLoyaltyMultiplier() << "x" << endl;
    cout << "========================================" << endl;
}
