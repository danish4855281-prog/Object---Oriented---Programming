#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include "Flight.h"
using namespace std;

class DomesticFlight : public Flight {

private:
    double basePrice;       // Base ticket price before tax
    double taxPercentage;   // Tax applied on top of base price

public:
    DomesticFlight(string flightNumber, string origin, string destination,
                   string departureDate, string departureTime,
                   int totalSeats, double basePrice, double taxPercentage);

    ~DomesticFlight();

    // Overriding pure virtual functions from Flight
    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getType() const override;

    // Getters
    double getBasePrice() const;
    double getTaxPercentage() const;
};

#endif
