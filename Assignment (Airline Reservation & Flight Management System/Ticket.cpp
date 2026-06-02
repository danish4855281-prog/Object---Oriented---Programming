#include "Ticket.h"

// Constructor — creates a ticket and generates a unique ticket ID
Ticket::Ticket(string passengerID, string flightNumber,
               string seatNumber, double farePaid) {

    if (passengerID.empty() || flightNumber.empty()) {
        cout << "Warning: Passenger ID and Flight Number cannot be empty." << endl;
    }

    this->passengerID  = passengerID;
    this->flightNumber = flightNumber;
    this->seatNumber   = seatNumber;
    this->farePaid     = (farePaid >= 0) ? farePaid : 0;
    this->bookingStatus = "Active";

    // Generate ticket ID by combining passengerID and flightNumber
    // Example: P001 + SK101 = TKT-P001-SK101
    this->ticketID = "TKT-" + passengerID + "-" + flightNumber;
}

// Default constructor — used when reading tickets from file
Ticket::Ticket() {
    ticketID      = "";
    passengerID   = "";
    flightNumber  = "";
    seatNumber    = "";
    farePaid      = 0.0;
    bookingStatus = "Active";
}

Ticket::~Ticket() {}

// Getters
string Ticket::getTicketID()      const { return ticketID; }
string Ticket::getPassengerID()   const { return passengerID; }
string Ticket::getFlightNumber()  const { return flightNumber; }
string Ticket::getSeatNumber()    const { return seatNumber; }
double Ticket::getFarePaid()      const { return farePaid; }
string Ticket::getBookingStatus() const { return bookingStatus; }

// Marks the ticket as cancelled
void Ticket::cancelTicket() {
    bookingStatus = "Cancelled";
}

// Returns true if the ticket has not been cancelled
bool Ticket::isActive() const {
    return bookingStatus == "Active";
}

// Operator == — two tickets are equal if they have the same ticket ID
bool Ticket::operator==(const Ticket& other) const {
    return this->ticketID == other.ticketID;
}

// Operator << — prints full ticket details
// Declared as friend so it can access private members
ostream& operator<<(ostream& out, const Ticket& ticket) {
    out << "========================================" << endl;
    out << "             TICKET DETAILS             " << endl;
    out << "========================================" << endl;
    out << "Ticket ID : " << ticket.ticketID      << endl;
    out << "Passenger : " << ticket.passengerID   << endl;
    out << "Flight    : " << ticket.flightNumber  << endl;
    out << "Seat      : " << ticket.seatNumber    << endl;
    out << "Fare Paid : $" << ticket.farePaid     << endl;
    out << "Status    : " << ticket.bookingStatus << endl;
    out << "========================================" << endl;
    return out;
}
