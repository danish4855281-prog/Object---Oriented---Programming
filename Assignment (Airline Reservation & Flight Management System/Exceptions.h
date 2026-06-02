#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

// Exception thrown when a flight has no available seats
class FlightFullException : public exception {

private:
    string message;

public:
    FlightFullException(string flightNumber) {
        message = "ERROR: Flight " + flightNumber + " is full. No seats available.";
    }

    // override what() to return our custom message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Exception thrown when a cancellation request is invalid
class InvalidCancellationException : public exception {

private:
    string message;

public:
    InvalidCancellationException(string reason) {
        message = "ERROR: Invalid cancellation — " + reason;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
