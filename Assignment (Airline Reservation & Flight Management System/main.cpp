#include <iostream>
#include <string>
#include <limits>
#include "Airline.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "CharterFlight.h"
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"
#include "FirstClassPassenger.h"
#include "Exceptions.h"
using namespace std;

// ===================== INPUT HELPERS =====================

// Reads a non-empty string from the user
string getStringInput(string prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    while (value.empty()) {
        cout << "Input cannot be empty. " << prompt;
        getline(cin, value);
    }
    return value;
}

// Reads a valid integer from the user
int getIntInput(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// Reads a valid double from the user
double getDoubleInput(string prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value) || value < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// ===================== FLIGHT MENU =====================

void flightMenu(Airline& airline) {
    int choice = 0;
    do {
        cout << "\n===== FLIGHT MANAGEMENT =====" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Remove Flight" << endl;
        cout << "3. Search Flight" << endl;
        cout << "4. List All Flights" << endl;
        cout << "0. Back to Main Menu" << endl;
        choice = getIntInput("Enter choice: ");

        if (choice == 1) {
            cout << "\nFlight Type:" << endl;
            cout << "1. Domestic" << endl;
            cout << "2. International" << endl;
            cout << "3. Charter" << endl;
            int type = getIntInput("Enter type: ");

            string fNum  = getStringInput("Flight Number  : ");
            string orig  = getStringInput("Origin         : ");
            string dest  = getStringInput("Destination    : ");
            string date  = getStringInput("Departure Date (YYYY-MM-DD): ");
            string time  = getStringInput("Departure Time (HH:MM): ");
            int    seats = getIntInput("Total Seats    : ");

            if (type == 1) {
                double base = getDoubleInput("Base Price ($) : ");
                double tax  = getDoubleInput("Tax (%)        : ");
                airline.addFlight(new DomesticFlight(fNum, orig, dest,
                                                     date, time, seats,
                                                     base, tax));
            } else if (type == 2) {
                double base      = getDoubleInput("Base Price ($)    : ");
                double surcharge = getDoubleInput("Surcharge ($)     : ");
                int    visaInput = getIntInput("Visa Required (1=Yes, 0=No): ");
                bool   visa      = (visaInput == 1);
                airline.addFlight(new InternationalFlight(fNum, orig, dest,
                                                          date, time, seats,
                                                          base, surcharge, visa));
            } else if (type == 3) {
                string holder = getStringInput("Contract Holder: ");
                double price  = getDoubleInput("Contract Price : ");
                airline.addFlight(new CharterFlight(fNum, orig, dest,
                                                    date, time, seats,
                                                    holder, price));
            } else {
                cout << "Invalid flight type." << endl;
            }

        } else if (choice == 2) {
            string fNum = getStringInput("Enter Flight Number to remove: ");
            airline.removeFlight(fNum);

        } else if (choice == 3) {
            string fNum   = getStringInput("Enter Flight Number to search: ");
            Flight* found = airline.searchFlight(fNum);
            if (found != nullptr) {
                found->displayDetails();
            } else {
                cout << "Flight not found." << endl;
            }

        } else if (choice == 4) {
            airline.listAllFlights();

        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

// ===================== PASSENGER MENU =====================

void passengerMenu(Airline& airline) {
    int choice = 0;
    do {
        cout << "\n===== PASSENGER MANAGEMENT =====" << endl;
        cout << "1. Register Passenger" << endl;
        cout << "2. Remove Passenger" << endl;
        cout << "3. Search Passenger" << endl;
        cout << "4. View Booking History" << endl;
        cout << "0. Back to Main Menu" << endl;
        choice = getIntInput("Enter choice: ");

        if (choice == 1) {
            cout << "\nPassenger Class:" << endl;
            cout << "1. Economy" << endl;
            cout << "2. Business" << endl;
            cout << "3. First Class" << endl;
            int cls = getIntInput("Enter class: ");

            string pid     = getStringInput("Passenger ID   : ");
            string name    = getStringInput("Name           : ");
            string contact = getStringInput("Contact Number : ");
            string email   = getStringInput("Email          : ");

            if (cls == 1) {
                airline.registerPassenger(
                    new EconomyPassenger(pid, name, contact, email));
            } else if (cls == 2) {
                airline.registerPassenger(
                    new BusinessPassenger(pid, name, contact, email));
            } else if (cls == 3) {
                airline.registerPassenger(
                    new FirstClassPassenger(pid, name, contact, email));
            } else {
                cout << "Invalid class." << endl;
            }

        } else if (choice == 2) {
            string pid = getStringInput("Enter Passenger ID to remove: ");
            airline.removePassenger(pid);

        } else if (choice == 3) {
            string pid       = getStringInput("Enter Passenger ID: ");
            Passenger* found = airline.searchPassenger(pid);
            if (found != nullptr) {
                found->displayDetails();
            } else {
                cout << "Passenger not found." << endl;
            }

        } else if (choice == 4) {
            string pid = getStringInput("Enter Passenger ID: ");
            airline.viewPassengerHistory(pid);

        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

// ===================== BOOKING MENU =====================

void bookingMenu(Airline& airline) {
    int choice = 0;
    do {
        cout << "\n===== BOOKING MANAGEMENT =====" << endl;
        cout << "1. Book Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "0. Back to Main Menu" << endl;
        choice = getIntInput("Enter choice: ");

        if (choice == 1) {
            string pid  = getStringInput("Passenger ID  : ");
            string fNum = getStringInput("Flight Number : ");

            // Exception handling — catch FlightFullException
            try {
                airline.bookTicket(pid, fNum);
            } catch (FlightFullException& e) {
                cout << e.what() << endl;
            } catch (exception& e) {
                cout << "Booking error: " << e.what() << endl;
            }

        } else if (choice == 2) {
            string tid = getStringInput("Ticket ID: ");

            // Exception handling — catch InvalidCancellationException
            try {
                airline.cancelTicket(tid);
            } catch (InvalidCancellationException& e) {
                cout << e.what() << endl;
            } catch (exception& e) {
                cout << "Cancellation error: " << e.what() << endl;
            }

        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

// ===================== REPORTS MENU =====================

void reportsMenu(Airline& airline) {
    int choice = 0;
    do {
        cout << "\n===== REPORTS =====" << endl;
        cout << "1. Today's Departures" << endl;
        cout << "2. Flight Occupancy" << endl;
        cout << "3. Top 5 Revenue Flights" << endl;
        cout << "0. Back to Main Menu" << endl;
        choice = getIntInput("Enter choice: ");

        if (choice == 1) {
            string today = getStringInput("Enter today's date (YYYY-MM-DD): ");
            airline.reportTodayDepartures(today);
        } else if (choice == 2) {
            airline.reportOccupancy();
        } else if (choice == 3) {
            airline.reportTopRevenueFlights();
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

// ===================== MAIN =====================

int main() {

    Airline airline("SkyLink Airways");

    // Load saved data on startup
    airline.loadData();

    int choice = 0;

    do {
        cout << "\n========================================" << endl;
        cout << "     SKYLINK AIRWAYS — MAIN MENU        " << endl;
        cout << "========================================" << endl;
        cout << "1. Flight Management" << endl;
        cout << "2. Passenger Management" << endl;
        cout << "3. Booking Management" << endl;
        cout << "4. Reports" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;
        choice = getIntInput("Enter choice: ");

        if (choice == 1) {
            flightMenu(airline);
        } else if (choice == 2) {
            passengerMenu(airline);
        } else if (choice == 3) {
            bookingMenu(airline);
        } else if (choice == 4) {
            reportsMenu(airline);
        } else if (choice == 0) {
            // Save data before exiting
            airline.saveData();
            cout << "Thank you for using SkyLink Airways. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
