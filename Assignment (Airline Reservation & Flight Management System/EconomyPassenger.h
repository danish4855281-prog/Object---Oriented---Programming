#ifndef ECONOMYPASSENGER_H
#define ECONOMYPASSENGER_H

#include "Passenger.h"
using namespace std;

class EconomyPassenger : public Passenger {

private:
    // Economy class has no extra private attributes
    // All rules are defined through overridden functions

public:
    EconomyPassenger(string passengerID, string name,
                     string contactNumber, string email);

    ~EconomyPassenger();

    // Overriding pure virtual functions
    int getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
    void displayDetails() const override;
    string getPassengerClass() const override;
};

#endif
