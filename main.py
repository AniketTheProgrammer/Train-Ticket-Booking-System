MAX_SEATS = 50
MAX_NAME_LENGTH = 50

# Class to store booking details
class Booking:
    def __init__(self):
        self.name = ""
        self.age = 0
        self.source = ""
        self.destination = ""
        self.seat_number = 0
        self.is_booked = False

train = [Booking() for _ in range(MAX_SEATS)]  # List to store booking details

# Initialize the train seats as available
def initializeSeats():
    for i in range(MAX_SEATS):
        train[i].is_booked = False  # False represents available seat

# Function to display available seats
def displayAvailableSeats():
    print("Available seats:")
    for i in range(MAX_SEATS):
        if not train[i].is_booked:
            print(f"Seat {i + 1}")

# Function to book a seat
def bookSeat():
    seat_number = int(input("Enter seat number to book: ")) - 1  # Adjust index

    if seat_number < 0 or seat_number >= MAX_SEATS:
        print("Invalid seat number")
        return

    if train[seat_number].is_booked:
        print("Seat already booked")
    else:
        train[seat_number].is_booked = True
        train[seat_number].seat_number = seat_number + 1  # Actual seat number
        train[seat_number].name = input("Enter passenger name: ")
        train[seat_number].age = int(input("Enter passenger age: "))
        train[seat_number].source = input("Enter source: ")
        train[seat_number].destination = input("Enter destination: ")
        print("Seat booked successfully!")

# Function to cancel a seat booking
def cancelSeat():
    seat_number = int(input("Enter seat number to cancel booking: ")) - 1  # Adjust index

    if seat_number < 0 or seat_number >= MAX_SEATS:
        print("Invalid seat number")
        return

    if train[seat_number].is_booked:
        train[seat_number].is_booked = False
        print("Seat booking cancelled successfully")
    else:
        print("Seat is not booked")

# Function to print ticket details
def printTicket(seat_number):
    seat_number -= 1  # Adjust index

    if seat_number < 0 or seat_number >= MAX_SEATS:
        print("Invalid seat number")
        return

    if train[seat_number].is_booked:
        print("Ticket Details:")
        print(f"Name: {train[seat_number].name}")
        print(f"Age: {train[seat_number].age}")
        print(f"Source: {train[seat_number].source}")
        print(f"Destination: {train[seat_number].destination}")
        print(f"Seat Number: {train[seat_number].seat_number}")
    else:
        print("Seat is not booked")

def main():
    initializeSeats()
    choice = 0
    while choice != 5:
        print("\nTrain Booking System")
        print("1. Display available seats")
        print("2. Book a seat")
        print("3. Cancel a seat booking")
        print("4. Print ticket")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            displayAvailableSeats()
        elif choice == 2:
            bookSeat()
        elif choice == 3:
            cancelSeat()
        elif choice == 4:
            seat_number = int(input("Enter seat number to print ticket: "))
            printTicket(seat_number)
        elif choice == 5:
            print("Exiting...")
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
