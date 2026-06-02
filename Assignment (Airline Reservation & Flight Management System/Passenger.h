#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

class Passenger {

protected:
    string passengerID;     // Unique ID for each passenger
    string name;
    string contactNumber;
    string email;
    int loyaltyPoints;      // Accumulated loyalty points

public:
    // Constructor
    Passenger(string passengerID, string name,
              string contactNumber, string email);

    // Virtual destructor
    virtual ~Passenger();

    // Pure virtual functions — each class defines its own rules
    virtual int getBaggageAllowance() const = 0;
    virtual double getLoyaltyMultiplier() const = 0;
    virtual double getRefundPercentage() const = 0;
    virtual void displayDetails() const = 0;
    virtual string getPassengerClass() const = 0;

    // Loyalty points management
    void addLoyaltyPoints(int points);
    void deductLoyaltyPoints(int points);

    // Getters
    string getPassengerID() const;
    string getName() const;
    string getContactNumber() const;
    string getEmail() const;
    int getLoyaltyPoints() const;

    // Setters with validation
    void setContactNumber(string contact);
    void setEmail(string email);

    // Friend operator for displaying passenger info
    friend ostream& operator<<(ostream& out, const Passenger& passenger);
};

#endif
