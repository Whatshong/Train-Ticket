#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_TRAINS = 100;
char trainName[50];
char departureTime[10];
char arrivalTime[10];
char source[50];
char destination[50];
int trains;
int passenger;
int numTrains = 0;
int UserInput;
int i = 0;

char trainList[4][50] = {"Tegal Bahari", "Argo Cheribon", "Tawang Jaya Premium", "Ciremai"};

void Menu();
void Schedule();
void Price();
void Quit();

int main() {
    Menu();
    return 0;
}
void Schedule() {
    char quitInt;
   while (numTrains < MAX_TRAINS){
        printf("\n \n \t \t Enter train details: \n");
        printf("\t \t What train do you want : \n \t \t 1. Tegal Bahari \n \t \t 2. Argo Ceribon \n \t \t 3. Tawang Jaya Premium \n \t \t 4. Chiremai \n");
        scanf("%d", &trains);
        printf("\t \t Departure time (HH:MM) : ");
        scanf("%s",departureTime);
        printf("\t \t Arrival time (HH:MM) : ");
        scanf("%s",arrivalTime);
        printf("\t \t Depart source : ");
        scanf("%s",source);
        printf("\t \t Arrived destination : ");
        scanf("%s",destination);
        printf("\t \t How many passenger : ");
        scanf("%d",&passenger);
        numTrains++;
        printf("\n \t \t You're entered train schedules: \n");
        printf("\t \t Train Name: %s\n", trainList[trains -1]);
        printf("\t \t Departure Time: %s\n",departureTime);
        printf("\t \t Arrival Time: %s\n", arrivalTime);
        printf("\t \t Source: %s\n", source);
        printf("\t \t Destination: %s\n", destination);
        printf("\t \t Passengers :  %d \n", passenger);
       while ((quitInt = getchar()) != 'n') {
           printf("\t \t Are you sure : \n");
           scanf("%c", &quitInt);

           if (quitInt == 'y' || quitInt == 'Y') {
               Price();
               break;
           } else if (quitInt == 'n' || quitInt == 'N') {
               Schedule();
               break;
           } else {
               printf("Invalid input. Please enter 'y' or 'n'.\n");
           }
       }
       break;

    }


}

void Price() {
    int price[] = {300000.00,200000.00,100000.00};

    int choice;
    do {
        printf ("====================================================================================\n");
        printf("\n \t \t Welcome to the Train Ticket Pricing System (if you want to quit type 0)\n");
        printf("\t \t Please select a train:\n");
        printf("\t \t 1. Express : Rp300.000\n");
        printf("\t \t 2. Rapid : Rp200.000\n");
        printf("\t \t 3. Local : 100.000\n");

        scanf("%d", &choice);
        if (choice == 1) {
            int total_price = price[0] * passenger;
            printf("\t \t Total price: %d\n", total_price);
        }else if (choice == 2) {
            int total_price = price[1] * passenger;
            printf("\t \t Total price: %d\n", total_price);
        }else if (choice == 3) {
            int total_price = price[2] * passenger;
            printf("\t \t Total price: %d\n", total_price);
        }else {
            printf("Wrong choice\n");
        }

    }while (choice >= 4);
}

void Menu() {
    int choice;
    while (i<5) {
        printf (" ======================================================================================================================\n ");
        printf("\t \t Welcome to Train Reservation System \n \t \t What do you want to do? \n \t \t 1. Schedule \t \t \n \t \t 2. Price \n \t \t 3. Quit \n");
        scanf("%d",&choice);
        switch (choice)
            {
            case 1: {
                Schedule();
                break;
            }
            case 2: {
                Price();
            }
            case 3: {
                Quit();
            }
            default: {
                printf("Wrong choice\n");
            }
        }
    }
}

void Quit() {
    char quitInput;

    printf("Do you want to quit? (y/n): ");
    scanf(" %c", &quitInput);

    if (quitInput == 'y' || quitInput == 'Y') {
        printf("Exiting the program.\n");
        exit(0);
    } else if (quitInput == 'n' || quitInput == 'N') {
        printf("Continuing the loop.\n");
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
        Quit();
    }
}