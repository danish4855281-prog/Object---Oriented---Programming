#include "CharterFlight.h"

// Constructor — passes common data to Flight, stores charter-specific data
CharterFlight::CharterFlight(string flightNumber, string origin, string destination,
                             string departureDate, string departureTime,
                             int totalSeats, string contractHolder, double contractPrice)
    : Flight(flightNumber, origin, destination, departureDate, departureTime, totalSeats) {

    if (contractHolder.empty()) {
        cout << "Warning: Contract holder name cannot be empty. Setting to UNKNOWN." << endl;
        this->contractHolder = "UNKNOWN";
    } else {
        this->contractHolder = contractHolder;
    }

    if (contractPrice < 0) {
        cout << "Warning: Contract price cannot be negative. Setting to 0." << endl;
        this->contractPrice = 0;
    } else {
        this->contractPrice = contractPrice;
    }
}

CharterFlight::~CharterFlight() {}

// For charter flights, fare per seat = contractPrice / totalSeats
double CharterFlight::calculateBaseFare() const {
    if (totalSeats == 0) return 0;
    return contractPrice / totalSeats;
}

// Displays all details including charter-specific info
void CharterFlight::displayDetails() const {
    cout << "========================================" << endl;
    cout << "         CHARTER FLIGHT DETAILS         " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Type          : Charter" << endl;
    cout << "Contract Holder: " << contractHolder << endl;
    cout << "Contract Price : $" << contractPrice << endl;
    cout << "========================================" << endl;
}

string CharterFlight::getType() const {
    return "Charter";
}

string CharterFlight::getContractHolder() const { return contractHolder; }
double CharterFlight::getContractPrice() const { return contractPrice; }
