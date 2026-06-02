#include "DomesticFlight.h"

// Constructor — passes common data to Flight, stores domestic-specific data
DomesticFlight::DomesticFlight(string flightNumber, string origin, string destination,
                               string departureDate, string departureTime,
                               int totalSeats, double basePrice, double taxPercentage)
    : Flight(flightNumber, origin, destination, departureDate, departureTime, totalSeats) {

    if (basePrice < 0) {
        cout << "Warning: Base price cannot be negative. Setting to 0." << endl;
        this->basePrice = 0;
    } else {
        this->basePrice = basePrice;
    }

    if (taxPercentage < 0 || taxPercentage > 100) {
        cout << "Warning: Tax percentage must be between 0 and 100. Setting to 0." << endl;
        this->taxPercentage = 0;
    } else {
        this->taxPercentage = taxPercentage;
    }
}

DomesticFlight::~DomesticFlight() {}

// Fare = basePrice + (basePrice * taxPercentage / 100)
double DomesticFlight::calculateBaseFare() const {
    double tax = (basePrice * taxPercentage) / 100.0;
    return basePrice + tax;
}

// Displays all details including domestic-specific info
void DomesticFlight::displayDetails() const {
    cout << "========================================" << endl;
    cout << "         DOMESTIC FLIGHT DETAILS        " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Type     : Domestic" << endl;
    cout << "Base Price: $" << basePrice << endl;
    cout << "Tax      : " << taxPercentage << "%" << endl;
    cout << "========================================" << endl;
}

string DomesticFlight::getType() const {
    return "Domestic";
}

double DomesticFlight::getBasePrice() const { return basePrice; }
double DomesticFlight::getTaxPercentage() const { return taxPercentage; }
