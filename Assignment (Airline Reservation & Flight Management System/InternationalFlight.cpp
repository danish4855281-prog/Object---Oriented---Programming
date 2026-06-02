#include "InternationalFlight.h"

// Constructor — passes common data to Flight, stores international-specific data
InternationalFlight::InternationalFlight(string flightNumber, string origin, string destination,
                                         string departureDate, string departureTime,
                                         int totalSeats, double basePrice,
                                         double internationalSurcharge, bool visaRequired)
    : Flight(flightNumber, origin, destination, departureDate, departureTime, totalSeats) {

    if (basePrice < 0) {
        cout << "Warning: Base price cannot be negative. Setting to 0." << endl;
        this->basePrice = 0;
    } else {
        this->basePrice = basePrice;
    }

    if (internationalSurcharge < 0) {
        cout << "Warning: Surcharge cannot be negative. Setting to 0." << endl;
        this->internationalSurcharge = 0;
    } else {
        this->internationalSurcharge = internationalSurcharge;
    }

    this->visaRequired = visaRequired;
}

InternationalFlight::~InternationalFlight() {}

// Fare = basePrice + internationalSurcharge
double InternationalFlight::calculateBaseFare() const {
    return basePrice + internationalSurcharge;
}

// Displays all details including international-specific info
void InternationalFlight::displayDetails() const {
    cout << "========================================" << endl;
    cout << "      INTERNATIONAL FLIGHT DETAILS      " << endl;
    cout << "========================================" << endl;
    cout << *this;
    cout << "Type     : International" << endl;
    cout << "Base Price: $" << basePrice << endl;
    cout << "Surcharge: $" << internationalSurcharge << endl;
    cout << "Visa Req : " << (visaRequired ? "Yes" : "No") << endl;
    cout << "========================================" << endl;
}

string InternationalFlight::getType() const {
    return "International";
}

double InternationalFlight::getBasePrice() const { return basePrice; }
double InternationalFlight::getInternationalSurcharge() const { return internationalSurcharge; }
bool InternationalFlight::getVisaRequired() const { return visaRequired; }
