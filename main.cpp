#include <iostream>
#include <string>
using namespace std;

#define MAX_SEATS 50
#define MAX_NAME_LENGTH 50

struct Booking {
    string name;
    int age;
    string source;
    string destination;
    int seat_number;
    int is_booked;
};

Booking train[MAX_SEATS];

void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        train[i].is_booked = 0;
    }
}

void displayAvailableSeats() {
    cout << "Available seats:\n";
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!train[i].is_booked) {
            cout << "Seat " << i + 1 << "\n";
        }
    }
}

void bookSeat() {
    int seat_number;
    cout << "Enter seat number to book: ";
    cin >> seat_number;
    seat_number--;

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        cout << "Invalid seat number\n";
        return;
    }

    if (train[seat_number].is_booked) {
        cout << "Seat already booked\n";
    } else {
        train[seat_number].is_booked = 1;
        train[seat_number].seat_number = seat_number + 1;
        cout << "Enter passenger name: ";
        cin >> train[seat_number].name;
        cout << "Enter passenger age: ";
        cin >> train[seat_number].age;
        cout << "Enter source: ";
        cin >> train[seat_number].source;
        cout << "Enter destination: ";
        cin >> train[seat_number].destination;
        cout << "Seat booked successfully!\n";
    }
}

void cancelSeat() {
    int seat_number;
    cout << "Enter seat number to cancel booking: ";
    cin >> seat_number;
    seat_number--;

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        cout << "Invalid seat number\n";
        return;
    }

    if (train[seat_number].is_booked) {
        train[seat_number].is_booked = 0;
        cout << "Seat booking cancelled successfully\n";
    } else {
        cout << "Seat is not booked\n";
    }
}

void printTicket(int seat_number) {
    seat_number--;

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        cout << "Invalid seat number\n";
        return;
    }

    if (train[seat_number].is_booked) {
        cout << "Ticket Details:\n";
        cout << "Name: " << train[seat_number].name << "\n";
        cout << "Age: " << train[seat_number].age << "\n";
        cout << "Source: " << train[seat_number].source << "\n";
        cout << "Destination: " << train[seat_number].destination << "\n";
        cout << "Seat Number: " << train[seat_number].seat_number << "\n";
    } else {
        cout << "Seat is not booked\n";
    }
}

int main() {
    initializeSeats();
    int choice;
    do {
        cout << "\nTrain Booking System\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a seat booking\n";
        cout << "4. Print ticket\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4: {
                int seat_number;
                cout << "Enter seat number to print ticket: ";
                cin >> seat_number;
                printTicket(seat_number);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
