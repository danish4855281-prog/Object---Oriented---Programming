#ifndef FIRSTCLASSPASSENGER_H
#define FIRSTCLASSPASSENGER_H

#include "Passenger.h"
using namespace std;

class FirstClassPassenger : public Passenger {

private:
    bool dedicatedConcierge;   // First class gets personal concierge

public:
    FirstClassPassenger(string passengerID, string name,
                        string contactNumber, string email,
                        bool dedicatedConcierge = true);

    ~FirstClassPassenger();

    // Overriding pure virtual functions
    int getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
    void displayDetails() const override;
    string getPassengerClass() const override;

    // Getter
    bool getDedicatedConcierge() const;
};

#endif
