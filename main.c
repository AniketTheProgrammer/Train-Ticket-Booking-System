#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50
#define MAX_NAME_LENGTH 50

// Structure to store booking details
struct Booking {
    char name[MAX_NAME_LENGTH];
    int age;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    int seat_number;
    int is_booked;
};

struct Booking train[MAX_SEATS]; // Array to store booking details

// Initialize the train seats as available
void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        train[i].is_booked = 0; // 0 represents available seat
    }
}

// Function to display available seats
void displayAvailableSeats() {
    printf("Available seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!train[i].is_booked) {
            printf("Seat %d\n", i + 1);
        }
    }
}

// Function to book a seat
void bookSeat() {
    int seat_number;
    printf("Enter seat number to book: ");
    scanf("%d", &seat_number);
    seat_number--; // Adjust index (seat number starts from 1)

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        printf("Invalid seat number\n");
        return;
    }

    if (train[seat_number].is_booked) {
        printf("Seat already booked\n");
    } else {
        train[seat_number].is_booked = 1;
        train[seat_number].seat_number = seat_number + 1; // Actual seat number
        printf("Enter passenger name: ");
        scanf("%s", train[seat_number].name);
        printf("Enter passenger age: ");
        scanf("%d", &train[seat_number].age);
        printf("Enter source: ");
        scanf("%s", train[seat_number].source);
        printf("Enter destination: ");
        scanf("%s", train[seat_number].destination);
        printf("Seat booked successfully!\n");
    }
}

// Function to cancel a seat booking
void cancelSeat() {
    int seat_number;
    printf("Enter seat number to cancel booking: ");
    scanf("%d", &seat_number);
    seat_number--; // Adjust index

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        printf("Invalid seat number\n");
        return;
    }

    if (train[seat_number].is_booked) {
        train[seat_number].is_booked = 0;
        printf("Seat booking cancelled successfully\n");
    } else {
        printf("Seat is not booked\n");
    }
}

// Function to print ticket details
void printTicket(int seat_number) {
    seat_number--; // Adjust index

    if (seat_number < 0 || seat_number >= MAX_SEATS) {
        printf("Invalid seat number\n");
        return;
    }

    if (train[seat_number].is_booked) {
        printf("Ticket Details:\n");
        printf("Name: %s\n", train[seat_number].name);
        printf("Age: %d\n", train[seat_number].age);
        printf("Source: %s\n", train[seat_number].source);
        printf("Destination: %s\n", train[seat_number].destination);
        printf("Seat Number: %d\n", train[seat_number].seat_number);
    } else {
        printf("Seat is not booked\n");
    }
}

int main() {
    initializeSeats();
    int choice;
    do {
        printf("\nTrain Booking System\n");
        printf("1. Display available seats\n");
        printf("2. Book a seat\n");
        printf("3. Cancel a seat booking\n");
        printf("4. Print ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Enter seat number to print ticket: ");
                scanf("%d", &seat_number);
                printTicket(seat_number);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
