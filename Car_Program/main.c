#include <stdio.h>
#include <string.h>
//This program takes in data from a file and writes a clean and clear version to an output file.


//Struct for the month, day, and year the vehicle was manufactured and purchased
typedef struct{
    int month, day, year;
} date_t;

//Struct for the maximum size of the gasoline tank and the current amount of fuel in the tank.
typedef struct{
    double tank_size, current_amount;
} tank_t;

//Struct that defines the make, model, the amount of miles on the car, and it includes the structs of the dates and tank.
typedef struct {
    char make[25];
    char model[25];
    int odometer;
    date_t manufacture_date;
    date_t purchase_date;
    tank_t tank;
} auto_t;

//Function Prototypes
int scan_date(date_t *date);
int scan_tank(tank_t *tank);
int scan_auto(auto_t *vehicle);
void print_date(date_t pdate);
void print_tank(tank_t ptank);
void print_auto(auto_t pauto);

int main()
{
    auto_t vehicle;
    int i = 1;

    FILE *vehicle_info;                         //Opens the file, if the file name is incorrectly inserted, an error message will pop up and the program will terminate
    vehicle_info = fopen("Cars.txt", "r");
    if(vehicle_info == NULL){
        printf("ERROR: File could not be opened.");
        getch();
        exit(1);
    }                                           //Calls for all functions below
    else
        while(i > 0)
        {
           i = fscanf(vehicle_info, "%s %s %d %d %d %d %d %d %d %lf %lf", vehicle.make, vehicle.model, &vehicle.odometer,
                                                                      &vehicle.manufacture_date.month, &vehicle.manufacture_date.day,
                                                                      &vehicle.manufacture_date.year, &vehicle.purchase_date.month,
                                                                      &vehicle.purchase_date.day, &vehicle.purchase_date.year,
                                                                      &vehicle.tank.tank_size, &vehicle.tank.current_amount);

        if(i == 11)
        {
            print_auto(vehicle);
            printf("Date Manufactured: ");
            print_date(vehicle.manufacture_date);
            printf("\nPurchased Date: ");
            print_date(vehicle.purchase_date);
            printf("\nTank Capacity: ");
            print_tank(vehicle.tank);
        }
       }

    fclose(vehicle_info);
    return 0;
}

//Functions to scan the dates, the car info and the gas tank size and current fuel level from a file.

int scan_date(date_t *date)
{
    int line;
    line=scanf("%d %d %d", &date->month, &date->day, &date->year);
    if(line == 3)
        line = 1;
    else if(line != EOF)
        line = 0;
    return line;
}

int scan_tank(tank_t *tank)
{
    int line;
    line = scanf("%lf %lf", &tank->tank_size, &tank->current_amount);
    if(line == 2)
        line = 1;
    else if(line != EOF)
        line = 0;
    return line;
}

int scan_auto(auto_t *vehicle)
{
    int line;
    line = scanf("%s %s %d %d %d %d %d %d %d %lf %lf", vehicle->make, vehicle->model, &vehicle->odometer,
                                                       &vehicle->manufacture_date.month, &vehicle->manufacture_date.day,
                                                       &vehicle->manufacture_date.year, &vehicle->purchase_date.month,
                                                       &vehicle->purchase_date.day, &vehicle->purchase_date.year,
                                                       &vehicle->tank.tank_size, &vehicle->tank.current_amount);
    if(line == 11)
        line = 1;
    else if(line != EOF)
        line = 0;
    return line;
}

//Functions to print the date that the vehicle was both purchased and manufactured, give info about the car, and the gas tank max and current fuel level.
void print_date(date_t pdate)
{
    printf("\n%d-%d-%d", pdate.month, pdate.day, pdate.year);
}

void print_tank(tank_t ptank)
{
    printf("\n%.2lf", ptank.tank_size);
    printf("\nCurrent Fuel Amount: \n%.2lf\n\n", ptank.current_amount);
}

void print_auto(auto_t pauto)
{
    printf("Vehicle: \n%s %s %d %d %d %d %d %d %d %.2lf %.2lf\n", pauto.make, pauto.model, pauto.odometer, pauto.manufacture_date.month,
                                                                 pauto.manufacture_date.day, pauto.manufacture_date.year, pauto.purchase_date.month,
                                                                 pauto.purchase_date.day, pauto.purchase_date.year, pauto.tank.tank_size, pauto.tank.current_amount);

}
