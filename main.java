import java.util.Scanner;

public class TrainBookingSystem {
    static final int MAX_SEATS = 50;
    static final int MAX_NAME_LENGTH = 50;

    static class Booking {
        String name;
        int age;
        String source;
        String destination;
        int seatNumber;
        boolean isBooked;
    }

    static Booking[] train = new Booking[MAX_SEATS];

    static void initializeSeats() {
        for (int i = 0; i < MAX_SEATS; i++) {
            train[i] = new Booking();
            train[i].isBooked = false;
        }
    }

    static void displayAvailableSeats() {
        System.out.println("Available seats:");
        for (int i = 0; i < MAX_SEATS; i++) {
            if (!train[i].isBooked) {
                System.out.println("Seat " + (i + 1));
            }
        }
    }

    static void bookSeat() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter seat number to book: ");
        int seatNumber = scanner.nextInt();
        seatNumber--; // Adjust index (seat number starts from 1)

        if (seatNumber < 0 || seatNumber >= MAX_SEATS) {
            System.out.println("Invalid seat number");
            return;
        }

        if (train[seatNumber].isBooked) {
            System.out.println("Seat already booked");
        } else {
            train[seatNumber].isBooked = true;
            train[seatNumber].seatNumber = seatNumber + 1; // Actual seat number
            System.out.print("Enter passenger name: ");
            scanner.nextLine(); // Consume newline
            train[seatNumber].name = scanner.nextLine();
            System.out.print("Enter passenger age: ");
            train[seatNumber].age = scanner.nextInt();
            System.out.print("Enter source: ");
            scanner.nextLine(); // Consume newline
            train[seatNumber].source = scanner.nextLine();
            System.out.print("Enter destination: ");
            train[seatNumber].destination = scanner.nextLine();
            System.out.println("Seat booked successfully!");
        }
    }

    static void cancelSeat() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter seat number to cancel booking: ");
        int seatNumber = scanner.nextInt();
        seatNumber--; // Adjust index

        if (seatNumber < 0 || seatNumber >= MAX_SEATS) {
            System.out.println("Invalid seat number");
            return;
        }

        if (train[seatNumber].isBooked) {
            train[seatNumber].isBooked = false;
            System.out.println("Seat booking cancelled successfully");
        } else {
            System.out.println("Seat is not booked");
        }
    }

    static void printTicket(int seatNumber) {
        seatNumber--; // Adjust index

        if (seatNumber < 0 || seatNumber >= MAX_SEATS) {
            System.out.println("Invalid seat number");
            return;
        }

        if (train[seatNumber].isBooked) {
            System.out.println("Ticket Details:");
            System.out.println("Name: " + train[seatNumber].name);
            System.out.println("Age: " + train[seatNumber].age);
            System.out.println("Source: " + train[seatNumber].source);
            System.out.println("Destination: " + train[seatNumber].destination);
            System.out.println("Seat Number: " + train[seatNumber].seatNumber);
        } else {
            System.out.println("Seat is not booked");
        }
    }

    public static void main(String[] args) {
        initializeSeats();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nTrain Booking System");
            System.out.println("1. Display available seats");
            System.out.println("2. Book a seat");
            System.out.println("3. Cancel a seat booking");
            System.out.println("4. Print ticket");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

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
                case 4:
                    System.out.print("Enter seat number to print ticket: ");
                    int seatNumber = scanner.nextInt();
                    printTicket(seatNumber);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 5);
    }
}
