#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

class Ticket {

private:
    string ticketID;        // Unique ID: passengerID + flightNumber
    string passengerID;     // ID of the passenger who booked
    string flightNumber;    // Flight this ticket is for
    string seatNumber;      // Assigned seat (e.g. "12A")
    double farePaid;        // Actual amount paid at time of booking
    string bookingStatus;   // "Active" or "Cancelled"

public:
    // Constructor
    Ticket(string passengerID, string flightNumber,
           string seatNumber, double farePaid);

    // Default constructor — needed when loading from file
    Ticket();

    // Destructor
    ~Ticket();

    // Getters
    string getTicketID() const;
    string getPassengerID() const;
    string getFlightNumber() const;
    string getSeatNumber() const;
    double getFarePaid() const;
    string getBookingStatus() const;

    // Status management
    void cancelTicket();
    bool isActive() const;

    // Operator overloading
    // Compares two tickets by their ticket ID
    bool operator==(const Ticket& other) const;

    // Friend operator for displaying ticket info
    friend ostream& operator<<(ostream& out, const Ticket& ticket);
};

#endif
