#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;

class Flight {

protected:
    string flightNumber;
    string origin;
    string destination;
    string departureDate;   // Format: YYYY-MM-DD
    string departureTime;   // Format: HH:MM
    int totalSeats;
    int availableSeats;

public:
    // Constructor
    Flight(string flightNumber, string origin, string destination,
           string departureDate, string departureTime,
           int totalSeats);

    // Virtual destructor — important when deleting via base pointer
    virtual ~Flight();

    // Pure virtual functions — must be overridden by derived classes
    virtual double calculateBaseFare() const = 0;
    virtual void displayDetails() const = 0;
    virtual string getType() const = 0;

    // Getters
    string getFlightNumber() const;
    string getOrigin() const;
    string getDestination() const;
    string getDepartureDate() const;
    string getDepartureTime() const;
    int getTotalSeats() const;
    int getAvailableSeats() const;

    // Seat management
    bool isFull() const;
    void bookSeat();
    void cancelSeat();

    // Setter with validation
    void setDepartureDate(string date);
    void setDepartureTime(string time);

    // Operator overloading — friend so it can access protected members
    friend ostream& operator<<(ostream& out, const Flight& flight);
};

#endif
