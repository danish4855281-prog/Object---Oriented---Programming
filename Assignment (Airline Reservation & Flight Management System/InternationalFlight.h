#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"
using namespace std;

class InternationalFlight : public Flight {

private:
    double basePrice;
    double internationalSurcharge;  // Extra fee for international travel
    bool visaRequired;              // Whether passengers need a visa

public:
    InternationalFlight(string flightNumber, string origin, string destination,
                        string departureDate, string departureTime,
                        int totalSeats, double basePrice,
                        double internationalSurcharge, bool visaRequired);

    ~InternationalFlight();

    // Overriding pure virtual functions from Flight
    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getType() const override;

    // Getters
    double getBasePrice() const;
    double getInternationalSurcharge() const;
    bool getVisaRequired() const;
};

#endif
