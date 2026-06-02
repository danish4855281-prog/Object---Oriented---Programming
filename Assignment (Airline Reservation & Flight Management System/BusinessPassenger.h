#ifndef BUSINESSPASSENGER_H
#define BUSINESSPASSENGER_H

#include "Passenger.h"
using namespace std;

class BusinessPassenger : public Passenger {

private:
    bool loungeAccess;   // Business passengers get lounge access

public:
    BusinessPassenger(string passengerID, string name,
                      string contactNumber, string email,
                      bool loungeAccess = true);

    ~BusinessPassenger();

    // Overriding pure virtual functions
    int getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
    void displayDetails() const override;
    string getPassengerClass() const override;

    // Getter
    bool getLoungeAccess() const;
};

#endif
