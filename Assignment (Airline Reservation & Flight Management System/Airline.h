#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Exceptions.h"
using namespace std;

class Airline {

private:
    string airlineName;
    vector<Flight*>    flights;      // All flights
    vector<Passenger*> passengers;   // All registered passengers
    vector<Ticket>     tickets;      // All tickets (active + cancelled)
    map<string, double> revenueMap;  // flightNumber -> total revenue earned

    // Helper: generate next available seat number
    string generateSeatNumber(Flight* flight);

    // Helper: check if passenger already has active ticket on flight
    bool hasActiveTicket(string passengerID, string flightNumber);

public:
    Airline(string airlineName);
    ~Airline();

    // Flight management
    void addFlight(Flight* flight);
    void removeFlight(string flightNumber);
    Flight* searchFlight(string flightNumber);
    void listAllFlights() const;

    // Passenger management
    void registerPassenger(Passenger* passenger);
    void removePassenger(string passengerID);
    Passenger* searchPassenger(string passengerID);
    void viewPassengerHistory(string passengerID) const;

    // Booking operations
    void bookTicket(string passengerID, string flightNumber);
    void cancelTicket(string ticketID);

    // Reports
    void reportTodayDepartures(string today) const;
    void reportOccupancy() const;
    void reportTopRevenueFlights() const;

    // File handling
    void saveData() const;
    void loadData();

    // Getter
    string getAirlineName() const;
};

#endif
