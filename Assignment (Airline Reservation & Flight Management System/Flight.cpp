#include "Flight.h"

// Constructor — initializes all common flight attributes
Flight::Flight(string flightNumber, string origin, string destination,
               string departureDate, string departureTime,
               int totalSeats) {

    // Basic validation
    if (flightNumber.empty()) {
        cout << "Warning: Flight number cannot be empty." << endl;
        this->flightNumber = "UNKNOWN";
    } else {
        this->flightNumber = flightNumber;
    }

    if (origin.empty()) {
        cout << "Warning: Origin cannot be empty." << endl;
        this->origin = "UNKNOWN";
    } else {
        this->origin = origin;
    }

    if (destination.empty()) {
        cout << "Warning: Destination cannot be empty." << endl;
        this->destination = "UNKNOWN";
    } else {
        this->destination = destination;
    }

    if (totalSeats <= 0) {
        cout << "Warning: Total seats must be positive. Setting to 1." << endl;
        this->totalSeats = 1;
    } else {
        this->totalSeats = totalSeats;
    }

    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->availableSeats = this->totalSeats;
}

// Virtual destructor — no dynamic memory here, but good practice
Flight::~Flight() {}

// Returns true if no seats are left
bool Flight::isFull() const {
    return availableSeats <= 0;
}

// Reduces available seats by 1 when a seat is booked
void Flight::bookSeat() {
    if (availableSeats > 0) {
        availableSeats--;
    }
}

// Increases available seats by 1 when a booking is cancelled
void Flight::cancelSeat() {
    if (availableSeats < totalSeats) {
        availableSeats++;
    }
}

// Getters
string Flight::getFlightNumber() const { return flightNumber; }
string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
string Flight::getDepartureDate() const { return departureDate; }
string Flight::getDepartureTime() const { return departureTime; }
int Flight::getTotalSeats() const { return totalSeats; }
int Flight::getAvailableSeats() const { return availableSeats; }

// Setter with basic format reminder
void Flight::setDepartureDate(string date) {
    if (date.empty()) {
        cout << "Invalid date." << endl;
        return;
    }
    departureDate = date;
}

void Flight::setDepartureTime(string time) {
    if (time.empty()) {
        cout << "Invalid time." << endl;
        return;
    }
    departureTime = time;
}

// Operator << overloading — prints basic flight info
// Declared as friend in Flight.h so it can access protected members
ostream& operator<<(ostream& out, const Flight& flight) {
    out << "Flight   : " << flight.flightNumber << endl;
    out << "Route    : " << flight.origin << " --> " << flight.destination << endl;
    out << "Date     : " << flight.departureDate << endl;
    out << "Time     : " << flight.departureTime << endl;
    out << "Seats    : " << flight.availableSeats << " / " << flight.totalSeats << " available" << endl;
    out << "Fare     : $" << flight.calculateBaseFare() << endl;
    return out;
}
