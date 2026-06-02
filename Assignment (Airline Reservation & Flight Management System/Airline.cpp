#include "Airline.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "CharterFlight.h"
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"
#include "FirstClassPassenger.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

Airline::Airline(string airlineName) {
    this->airlineName = airlineName;
}

// Destructor — free all dynamically allocated flights and passengers
Airline::~Airline() {
    for (int i = 0; i < (int)flights.size(); i++) {
        delete flights[i];
    }
    for (int i = 0; i < (int)passengers.size(); i++) {
        delete passengers[i];
    }
}

string Airline::getAirlineName() const {
    return airlineName;
}

// ===================== HELPERS =====================

// Generates seat number based on booked seats count
string Airline::generateSeatNumber(Flight* flight) {
    int booked = flight->getTotalSeats() - flight->getAvailableSeats();
    int row    = (booked / 6) + 1;
    char col   = 'A' + (booked % 6);
    return to_string(row) + col;
}

// Returns true if passenger already has an active ticket on that flight
bool Airline::hasActiveTicket(string passengerID, string flightNumber) {
    for (int i = 0; i < (int)tickets.size(); i++) {
        if (tickets[i].getPassengerID()  == passengerID &&
            tickets[i].getFlightNumber() == flightNumber &&
            tickets[i].isActive()) {
            return true;
        }
    }
    return false;
}

// ===================== FLIGHT MANAGEMENT =====================

void Airline::addFlight(Flight* flight) {
    if (flight == nullptr) {
        cout << "Cannot add null flight." << endl;
        return;
    }
    // Check for duplicate flight number
    for (int i = 0; i < (int)flights.size(); i++) {
        if (flights[i]->getFlightNumber() == flight->getFlightNumber()) {
            cout << "Flight " << flight->getFlightNumber() << " already exists." << endl;
            return;
        }
    }
    flights.push_back(flight);
    revenueMap[flight->getFlightNumber()] = 0.0;
    cout << "Flight " << flight->getFlightNumber() << " added successfully." << endl;
}

void Airline::removeFlight(string flightNumber) {
    for (int i = 0; i < (int)flights.size(); i++) {
        if (flights[i]->getFlightNumber() == flightNumber) {
            delete flights[i];
            flights.erase(flights.begin() + i);
            revenueMap.erase(flightNumber);
            cout << "Flight " << flightNumber << " removed successfully." << endl;
            return;
        }
    }
    cout << "Flight " << flightNumber << " not found." << endl;
}

Flight* Airline::searchFlight(string flightNumber) {
    for (int i = 0; i < (int)flights.size(); i++) {
        if (flights[i]->getFlightNumber() == flightNumber) {
            return flights[i];
        }
    }
    return nullptr;
}

void Airline::listAllFlights() const {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    cout << "\n===== ALL FLIGHTS =====" << endl;
    for (int i = 0; i < (int)flights.size(); i++) {
        flights[i]->displayDetails();
        cout << endl;
    }
}

// ===================== PASSENGER MANAGEMENT =====================

void Airline::registerPassenger(Passenger* passenger) {
    if (passenger == nullptr) {
        cout << "Cannot register null passenger." << endl;
        return;
    }
    // Check for duplicate passenger ID
    for (int i = 0; i < (int)passengers.size(); i++) {
        if (passengers[i]->getPassengerID() == passenger->getPassengerID()) {
            cout << "Passenger " << passenger->getPassengerID() << " already registered." << endl;
            return;
        }
    }
    passengers.push_back(passenger);
    cout << "Passenger " << passenger->getName() << " registered successfully." << endl;
}

void Airline::removePassenger(string passengerID) {
    for (int i = 0; i < (int)passengers.size(); i++) {
        if (passengers[i]->getPassengerID() == passengerID) {
            delete passengers[i];
            passengers.erase(passengers.begin() + i);
            cout << "Passenger " << passengerID << " removed successfully." << endl;
            return;
        }
    }
    cout << "Passenger " << passengerID << " not found." << endl;
}

Passenger* Airline::searchPassenger(string passengerID) {
    for (int i = 0; i < (int)passengers.size(); i++) {
        if (passengers[i]->getPassengerID() == passengerID) {
            return passengers[i];
        }
    }
    return nullptr;
}

void Airline::viewPassengerHistory(string passengerID) const {
    Passenger* found = nullptr;
    for (int i = 0; i < (int)passengers.size(); i++) {
        if (passengers[i]->getPassengerID() == passengerID) {
            found = passengers[i];
            break;
        }
    }
    if (found == nullptr) {
        cout << "Passenger not found." << endl;
        return;
    }

    cout << "\n===== BOOKING HISTORY FOR: " << found->getName() << " =====" << endl;
    bool anyFound = false;
    for (int i = 0; i < (int)tickets.size(); i++) {
        if (tickets[i].getPassengerID() == passengerID) {
            cout << tickets[i];
            anyFound = true;
        }
    }
    if (!anyFound) {
        cout << "No booking history found." << endl;
    }
}

// ===================== BOOKING =====================

void Airline::bookTicket(string passengerID, string flightNumber) {

    // Find passenger
    Passenger* passenger = searchPassenger(passengerID);
    if (passenger == nullptr) {
        cout << "Passenger " << passengerID << " not found." << endl;
        return;
    }

    // Find flight
    Flight* flight = searchFlight(flightNumber);
    if (flight == nullptr) {
        cout << "Flight " << flightNumber << " not found." << endl;
        return;
    }

    // Check if flight is full — throw custom exception
    if (flight->isFull()) {
        throw FlightFullException(flightNumber);
    }

    // Check if passenger already has active ticket on this flight
    if (hasActiveTicket(passengerID, flightNumber)) {
        cout << "Passenger already has an active ticket on flight " << flightNumber << "." << endl;
        return;
    }

    // Generate seat and calculate fare
    string seatNumber = generateSeatNumber(flight);
    double fare       = flight->calculateBaseFare();

    // Create ticket
    Ticket newTicket(passengerID, flightNumber, seatNumber, fare);
    tickets.push_back(newTicket);

    // Book the seat on the flight
    flight->bookSeat();

    // Add to revenue map
    revenueMap[flightNumber] += fare;

    // Award loyalty points based on passenger class multiplier
    int points = (int)(fare * passenger->getLoyaltyMultiplier() / 100.0);
    passenger->addLoyaltyPoints(points);

    cout << "Ticket booked successfully!" << endl;
    cout << newTicket;
}

// ===================== CANCELLATION =====================

void Airline::cancelTicket(string ticketID) {

    // Find the ticket
    int ticketIndex = -1;
    for (int i = 0; i < (int)tickets.size(); i++) {
        if (tickets[i].getTicketID() == ticketID) {
            ticketIndex = i;
            break;
        }
    }

    if (ticketIndex == -1) {
        cout << "Ticket " << ticketID << " not found." << endl;
        return;
    }

    // Check if already cancelled — throw custom exception
    if (!tickets[ticketIndex].isActive()) {
        throw InvalidCancellationException("Ticket " + ticketID + " is already cancelled.");
    }

    // Find the passenger for refund calculation
    Passenger* passenger = searchPassenger(tickets[ticketIndex].getPassengerID());
    Flight*    flight    = searchFlight(tickets[ticketIndex].getFlightNumber());

    double farePaid       = tickets[ticketIndex].getFarePaid();
    double refundPercent  = 50.0; // default

    if (passenger != nullptr) {
        refundPercent = passenger->getRefundPercentage();
    }

    double refundAmount = (farePaid * refundPercent) / 100.0;

    // Cancel the ticket
    tickets[ticketIndex].cancelTicket();

    // Free the seat on the flight
    if (flight != nullptr) {
        flight->cancelSeat();
        revenueMap[flight->getFlightNumber()] -= farePaid;
    }

    cout << "Ticket " << ticketID << " cancelled successfully." << endl;
    cout << "Refund Amount: $" << refundAmount
         << " (" << refundPercent << "% of $" << farePaid << ")" << endl;
}

// ===================== REPORTS =====================

void Airline::reportTodayDepartures(string today) const {
    cout << "\n===== TODAY'S DEPARTURES (" << today << ") =====" << endl;
    bool found = false;
    for (int i = 0; i < (int)flights.size(); i++) {
        if (flights[i]->getDepartureDate() == today) {
            cout << *flights[i];
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No departures today." << endl;
    }
}

void Airline::reportOccupancy() const {
    cout << "\n===== FLIGHT OCCUPANCY =====" << endl;
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    for (int i = 0; i < (int)flights.size(); i++) {
        int total    = flights[i]->getTotalSeats();
        int booked   = total - flights[i]->getAvailableSeats();
        double pct   = (total > 0) ? (booked * 100.0 / total) : 0.0;
        cout << "Flight: " << flights[i]->getFlightNumber()
             << " | Booked: " << booked << "/" << total
             << " | Occupancy: " << fixed << setprecision(1) << pct << "%" << endl;
    }
}

// Uses sort algorithm to find top 5 revenue flights
void Airline::reportTopRevenueFlights() const {
    cout << "\n===== TOP 5 REVENUE FLIGHTS =====" << endl;

    if (revenueMap.empty()) {
        cout << "No revenue data available." << endl;
        return;
    }

    // Copy map into a vector of pairs so we can sort it
    vector<pair<string, double>> revenueList;
    for (map<string,double>::const_iterator it = revenueMap.begin();
         it != revenueMap.end(); ++it) {
        revenueList.push_back(*it);
    }

    // Sort by revenue descending using sort + a helper comparison
    // We use a simple loop-based sort to keep it beginner-friendly
    for (int i = 0; i < (int)revenueList.size(); i++) {
        for (int j = i + 1; j < (int)revenueList.size(); j++) {
            if (revenueList[j].second > revenueList[i].second) {
                pair<string,double> temp = revenueList[i];
                revenueList[i] = revenueList[j];
                revenueList[j] = temp;
            }
        }
    }

    int limit = min((int)revenueList.size(), 5);
    for (int i = 0; i < limit; i++) {
        cout << (i + 1) << ". Flight: " << revenueList[i].first
             << " | Revenue: $" << fixed << setprecision(2)
             << revenueList[i].second << endl;
    }
}

// ===================== FILE HANDLING =====================

void Airline::saveData() const {

    // Save flights
    ofstream flightFile("data/flights.txt");
    if (flightFile.is_open()) {
        for (int i = 0; i < (int)flights.size(); i++) {
            Flight* f = flights[i];
            flightFile << f->getType()          << "|"
                       << f->getFlightNumber()  << "|"
                       << f->getOrigin()        << "|"
                       << f->getDestination()   << "|"
                       << f->getDepartureDate() << "|"
                       << f->getDepartureTime() << "|"
                       << f->getTotalSeats()    << "|"
                       << f->getAvailableSeats()<< "|";

            if (f->getType() == "Domestic") {
                DomesticFlight* df = (DomesticFlight*)f;
                flightFile << df->getBasePrice()      << "|"
                           << df->getTaxPercentage()  << "|";
            } else if (f->getType() == "International") {
                InternationalFlight* inf = (InternationalFlight*)f;
                flightFile << inf->getBasePrice()              << "|"
                           << inf->getInternationalSurcharge() << "|"
                           << inf->getVisaRequired()           << "|";
            } else if (f->getType() == "Charter") {
                CharterFlight* cf = (CharterFlight*)f;
                flightFile << cf->getContractHolder() << "|"
                           << cf->getContractPrice()  << "|";
            }
            flightFile << "\n";
        }
        flightFile.close();
    } else {
        cout << "Warning: Could not open data/flights.txt for saving." << endl;
    }

    // Save passengers
    ofstream passengerFile("data/passengers.txt");
    if (passengerFile.is_open()) {
        for (int i = 0; i < (int)passengers.size(); i++) {
            Passenger* p = passengers[i];
            passengerFile << p->getPassengerClass()  << "|"
                          << p->getPassengerID()     << "|"
                          << p->getName()            << "|"
                          << p->getContactNumber()   << "|"
                          << p->getEmail()           << "|"
                          << p->getLoyaltyPoints()   << "|"
                          << "\n";
        }
        passengerFile.close();
    } else {
        cout << "Warning: Could not open data/passengers.txt for saving." << endl;
    }

    // Save tickets
    ofstream ticketFile("data/tickets.txt");
    if (ticketFile.is_open()) {
        for (int i = 0; i < (int)tickets.size(); i++) {
            ticketFile << tickets[i].getTicketID()      << "|"
                       << tickets[i].getPassengerID()   << "|"
                       << tickets[i].getFlightNumber()  << "|"
                       << tickets[i].getSeatNumber()    << "|"
                       << tickets[i].getFarePaid()      << "|"
                       << tickets[i].getBookingStatus() << "|"
                       << "\n";
        }
        ticketFile.close();
    } else {
        cout << "Warning: Could not open data/tickets.txt for saving." << endl;
    }

    cout << "Data saved successfully." << endl;
}

void Airline::loadData() {

    // Load flights
    ifstream flightFile("data/flights.txt");
    if (flightFile.is_open()) {
        string line;
        while (getline(flightFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string token;
            vector<string> fields;

            while (getline(ss, token, '|')) {
                fields.push_back(token);
            }

            if (fields.size() < 8) continue;

            string type          = fields[0];
            string flightNumber  = fields[1];
            string origin        = fields[2];
            string destination   = fields[3];
            string depDate       = fields[4];
            string depTime       = fields[5];
            int    totalSeats    = stoi(fields[6]);
            int    availSeats    = stoi(fields[7]);

            Flight* f = nullptr;

            if (type == "Domestic" && fields.size() >= 10) {
                double basePrice     = stod(fields[8]);
                double taxPct        = stod(fields[9]);
                f = new DomesticFlight(flightNumber, origin, destination,
                                       depDate, depTime, totalSeats,
                                       basePrice, taxPct);
            } else if (type == "International" && fields.size() >= 11) {
                double basePrice  = stod(fields[8]);
                double surcharge  = stod(fields[9]);
                bool   visaReq    = (fields[10] == "1");
                f = new InternationalFlight(flightNumber, origin, destination,
                                            depDate, depTime, totalSeats,
                                            basePrice, surcharge, visaReq);
            } else if (type == "Charter" && fields.size() >= 10) {
                string contractHolder = fields[8];
                double contractPrice  = stod(fields[9]);
                f = new CharterFlight(flightNumber, origin, destination,
                                      depDate, depTime, totalSeats,
                                      contractHolder, contractPrice);
            }

            if (f != nullptr) {
                // Restore available seats
                int bookedSeats = totalSeats - availSeats;
                for (int i = 0; i < bookedSeats; i++) {
                    f->bookSeat();
                }
                flights.push_back(f);
                revenueMap[f->getFlightNumber()] = 0.0;
            }
        }
        flightFile.close();
    }

    // Load passengers
    ifstream passengerFile("data/passengers.txt");
    if (passengerFile.is_open()) {
        string line;
        while (getline(passengerFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string token;
            vector<string> fields;

            while (getline(ss, token, '|')) {
                fields.push_back(token);
            }

            if (fields.size() < 6) continue;

            string pClass   = fields[0];
            string pID      = fields[1];
            string name     = fields[2];
            string contact  = fields[3];
            string email    = fields[4];
            int    points   = stoi(fields[5]);

            Passenger* p = nullptr;

            if (pClass == "Economy") {
                p = new EconomyPassenger(pID, name, contact, email);
            } else if (pClass == "Business") {
                p = new BusinessPassenger(pID, name, contact, email);
            } else if (pClass == "FirstClass") {
                p = new FirstClassPassenger(pID, name, contact, email);
            }

            if (p != nullptr) {
                p->addLoyaltyPoints(points);
                passengers.push_back(p);
            }
        }
        passengerFile.close();
    }

    // Load tickets
    ifstream ticketFile("data/tickets.txt");
    if (ticketFile.is_open()) {
        string line;
        while (getline(ticketFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string token;
            vector<string> fields;

            while (getline(ss, token, '|')) {
                fields.push_back(token);
            }

            if (fields.size() < 6) continue;

            Ticket t;
            // We reconstruct using available fields manually
            string pID     = fields[1];
            string fNum    = fields[2];
            string seat    = fields[3];
            double fare    = stod(fields[4]);
            string status  = fields[5];

            t = Ticket(pID, fNum, seat, fare);
            if (status == "Cancelled") {
                t.cancelTicket();
            }

            tickets.push_back(t);

            // Restore revenue map
            if (status == "Active") {
                revenueMap[fNum] += fare;
            }
        }
        ticketFile.close();
    }

    cout << "Data loaded successfully." << endl;
}
