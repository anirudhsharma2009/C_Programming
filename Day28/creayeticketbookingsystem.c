#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEAT_COUNT 10
#define FILE_NAME "tickets.dat"

typedef struct {
    int seatNumber;
    int booked;
    char customerName[50];
} Seat;

void initializeSeats(Seat seats[]) {
    for (int i = 0; i < SEAT_COUNT; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].booked = 0;
        seats[i].customerName[0] = '\0';
    }
}

void loadSeats(Seat seats[]) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        initializeSeats(seats);
        return;
    }
    size_t read = fread(seats, sizeof(Seat), SEAT_COUNT, file);
    if (read != SEAT_COUNT) {
        initializeSeats(seats);
    }
    fclose(file);
}

void saveSeats(Seat seats[]) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error: Unable to save booking data.\n");
        return;
    }
    fwrite(seats, sizeof(Seat), SEAT_COUNT, file);
    fclose(file);
}

void showSeats(Seat seats[]) {
    printf("\nSeat status:\n");
    for (int i = 0; i < SEAT_COUNT; i++) {
        printf("Seat %2d: %s", seats[i].seatNumber,
               seats[i].booked ? "Booked" : "Available");
        if (seats[i].booked) {
            printf(" by %s", seats[i].customerName);
        }
        printf("\n");
    }
}

void bookTicket(Seat seats[]) {
    int seatNo;
    char name[50];
    showSeats(seats);
    printf("\nEnter seat number to book (1-%d): ", SEAT_COUNT);
    if (scanf("%d", &seatNo) != 1) {
        while (getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }
    if (seatNo < 1 || seatNo > SEAT_COUNT) {
        printf("Seat number must be between 1 and %d.\n", SEAT_COUNT);
        return;
    }
    if (seats[seatNo - 1].booked) {
        printf("Seat %d is already booked.\n", seatNo);
        return;
    }
    printf("Enter customer name: ");
    while (getchar() != '\n');
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Failed to read name.\n");
        return;
    }
    name[strcspn(name, "\n")] = '\0';
    if (strlen(name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }
    seats[seatNo - 1].booked = 1;
    strncpy(seats[seatNo - 1].customerName, name, sizeof(seats[seatNo - 1].customerName) - 1);
    seats[seatNo - 1].customerName[sizeof(seats[seatNo - 1].customerName) - 1] = '\0';
    printf("Seat %d successfully booked for %s.\n", seatNo, seats[seatNo - 1].customerName);
}

void cancelTicket(Seat seats[]) {
    int seatNo;
    showSeats(seats);
    printf("\nEnter seat number to cancel (1-%d): ", SEAT_COUNT);
    if (scanf("%d", &seatNo) != 1) {
        while (getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }
    if (seatNo < 1 || seatNo > SEAT_COUNT) {
        printf("Seat number must be between 1 and %d.\n", SEAT_COUNT);
        return;
    }
    if (!seats[seatNo - 1].booked) {
        printf("Seat %d is not booked.\n", seatNo);
        return;
    }
    seats[seatNo - 1].booked = 0;
    seats[seatNo - 1].customerName[0] = '\0';
    printf("Booking for seat %d has been cancelled.\n", seatNo);
}

void showBookedTickets(Seat seats[]) {
    int any = 0;
    printf("\nBooked tickets:\n");
    for (int i = 0; i < SEAT_COUNT; i++) {
        if (seats[i].booked) {
            any = 1;
            printf("Seat %2d: %s\n", seats[i].seatNumber, seats[i].customerName);
        }
    }
    if (!any) {
        printf("No tickets booked yet.\n");
    }
}

int main(void) {
    Seat seats[SEAT_COUNT];
    int choice;

    loadSeats(seats);

    do {
        printf("\nTicket Booking System\n");
        printf("1. Show seats\n");
        printf("2. Book ticket\n");
        printf("3. Cancel ticket\n");
        printf("4. Show booked tickets\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                showSeats(seats);
                break;
            case 2:
                bookTicket(seats);
                saveSeats(seats);
                break;
            case 3:
                cancelTicket(seats);
                saveSeats(seats);
                break;
            case 4:
                showBookedTickets(seats);
                break;
            case 5:
                saveSeats(seats);
                printf("Exiting the system.\n");
                break;
            default:
                printf("Please choose a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
