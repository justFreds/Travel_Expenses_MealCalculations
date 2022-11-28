#include <stdio.h>
#include "expenseSheet.h"

//fill out the struct for everything that does not need calculation
//note: meals will be filled out by another group member
void fillExpenses(Expenses *e){
    //get departure time
    printf("Please enter the departure time (0-23): ");
    scanf("%d", &e->departTime);
    //get arrival time
    printf("Please enter the arrival time (0-23): ");
    scanf("%d", &e->arriveTime);
    //get whole days
    printf("Please enter the number of whole days(not including departure and arrival days): ");
    scanf("%d", &e->wholeDays);
    //set total days
    e->totalDays = e->wholeDays + 2;//whole days + departure and arrival day
    //... please fill out the rest
}

//print everything in the struct filled out so far (for testing)
void printExpenses(Expenses *e){
    printf("Departure time: %d\n", e->departTime);
    printf("Arrival time (home): %d\n", e->arriveTime);
    
}