#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H

#include "Flight.h"
using namespace std;

class CharterFlight : public Flight {

private:
    string contractHolder;  // Name of the person/company that hired the charter
    double contractPrice;   // Fixed total price of the charter

public:
    CharterFlight(string flightNumber, string origin, string destination,
                  string departureDate, string departureTime,
                  int totalSeats, string contractHolder, double contractPrice);

    ~CharterFlight();

    // Overriding pure virtual functions from Flight
    double calculateBaseFare() const override;
    void displayDetails() const override;
    string getType() const override;

    // Getters
    string getContractHolder() const;
    double getContractPrice() const;
};

#endif
