#include "expenseSheet.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10000

bool parse_float(char *str, double *floatNumber);
bool parse_integer(char *str, int *integerNumber);

//fill out the struct for everything that does not need calculation
//note: meals will be filled out by another group member
void fillExpenses(Expenses *e){
    bool parsed_correct = true;
    char buffer[BUFFER_SIZE];
    fflush(stdin);
    //get departure time
    do{
        printf("Please enter the departure time (0-23.59): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->departTime);
        if(!parsed_correct || e->departTime >= 24 || (e->departTime - (int)e->departTime) >= .6) {
            printf("\nError please enter a valid time!\n");
        }
    } while(!parsed_correct || e->departTime >= 24 || (e->departTime - (int)e->departTime) >= .6);
    //get arrival time
    do{
        printf("Please enter the arrival time (0-23.59): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->arriveTime);
        if(!parsed_correct || e->arriveTime >= 24 || (e->arriveTime - (int)e->arriveTime) >= .6) {
            printf("\nError please enter a valid time!\n");
        }
    } while(!parsed_correct || e->arriveTime >= 24 || (e->arriveTime - (int)e->arriveTime) >= .6);

    //get whole days
    do{
        printf("Please enter the number of whole days(not including departure and arrival days): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_integer(buffer, &e->wholeDays);
        if(!parsed_correct) {
            printf("\nError please enter a valid whole days!\n");
        }
    } while(!parsed_correct);
    //set total days
    e->totalDays = e->wholeDays + 2;//whole days + departure and arrival day

    //get airfare 
    do{
        printf("Please enter the total amount paid for airline travel to your destination: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->airfare);
        if(!parsed_correct) {
            printf("\nError please enter a valid price for airline travel!\n");
        }
    } while(!parsed_correct);
    //get carRentals
    do{
        printf("Please enter the amount spent in total for car rentals: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->carRentals);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount spent for car rentals!\n");
        }
    } while(!parsed_correct);
    //get milesDriven
    do{
        printf("Please enter all miles driven with the use of a private vehicle: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_integer(buffer, &e->milesDriven);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount of miles driven!\n");
        }
    } while(!parsed_correct);
    //get parkingFees
    do{
        printf("Please add up and include any and all applicable parking fees incurred while traveling to and from the destination: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->parkingFees);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount of miles driven!\n");
        }
    } while(!parsed_correct);
    //get taxiFees
    do{
        printf("Please calculate the total amount spent on taxi fare while traveling on this business related excursion: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->taxiFees);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount of miles driven!\n");
        }
    } while(!parsed_correct);
    //get registration fees
    do{
        printf("Please include any incurred registration fees on this line: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->registrationFees);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount of miles driven!\n");
        }
    } while(!parsed_correct); 
    //get hotel expenses
    do{
        printf("On a separate sheet, please calculate out all hotel related expenses (including room, board, and other necessities) and enter the total here: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_float(buffer, &e->hotelExpenses);
        if(!parsed_correct) {
            printf("\nError please enter a valid amount of miles driven!\n");
        }
    } while(!parsed_correct); 

}

//print everything in the struct filled out so far (for testing)
void printExpenses(Expenses *e){
    printf("Departure time: %d\n", e->departTime);
    printf("Arrival time (home): %d\n", e->arriveTime);
    printf("Whole days(not including departure and arrival days): %d\n", e->wholeDays); 
    printf("Total days: %d\n", e->totalDays); 
    printf("Total Airfare incurred: %lf\n", e->airfare); 
    printf("Total expended through use of car rentals: %lf\n", e->carRentals); 
    printf("Total mileage accrued during travel: %d\n", e->milesDriven); 
    printf("Total of all applicable parking fees: %lf\n", e->parkingFees); 
    printf("Total debt accumulated through taxi services rendered: %lf\n", e->taxiFees);
    printf("Total fees amassed for hotel related expenses: %lf\n", e->hotelExpenses);    
}
bool parse_float(char *str, double *floatNumber) {
    int i = 0;
    while(isspace(str[i])) i++;
    //check if i reached end of string
    int length = strlen(str);
    if(length == i) return false;

    char float_buffer[BUFFER_SIZE];
    int float_chars = 0;
                //  store negative
                // if(str[i] == '-') {
                //     float_buffer[float_chars];
                //     float_chars++;
                //     i++;

                //     if(!isdigit(str[i])) return false;
                // }
    while(i<length && !isspace(str[i])) {
        //store dot but return false if for more than 1
        int periodLength = 0;
        if(str[i] == '.') {
            float_buffer[float_chars] = str[i];
            float_chars++;
            i++;
            periodLength++;
            if(periodLength > 1) return false;
        }
        //check if number after dot is digit
        if(!isdigit(str[i])) return false;
        //store the numbers in the buffer
        float_buffer[float_chars] = str[i];
        float_chars++;
        i++;
    }
    //end the array
    float_buffer[float_chars] = '\0';
    //ignore rest of whitespace
    while(isspace(str[i])) i++;
    //if string doesn't end with \0 complain
    if(str[i] != '\0') return false;
    //convert string into float and assign the to number passed thru
    *floatNumber = atof(float_buffer);

    return true;
}
bool parse_integer(char *str, int *integerNumber) {
    int i = 0;
    while(isspace(str[i])) i++;
    //check if i reached end of string
    int length = strlen(str);
    if(length == i) return false;

    char int_buffer[BUFFER_SIZE];
    int int_chars = 0;
                //  store negative
                // if(str[i] == '-') {
                //     float_buffer[float_chars];
                //     float_chars++;
                //     i++;

                //     if(!isdigit(str[i])) return false;
                // }
    while(i<length && !isspace(str[i])) {
        //store dot but return false if for more than 1
        // int periodLength = 0;
        // if(str[i] == '.') {
        //     float_buffer[float_chars] = str[i];
        //     float_chars++;
        //     i++;
        //     periodLength++;
        //     if(periodLength > 1) return false;
        // }
        //check if number after dot is digit
        if(!isdigit(str[i])) return false;
        //store the numbers in the buffer
        int_buffer[int_chars] = str[i];
        int_chars++;
        i++;
    }
    //end the array
    int_buffer[int_chars] = '\0';
    //ignore rest of whitespace
    while(isspace(str[i])) i++;
    //if string doesn't end with \0 complain
    if(str[i] != '\0') return false;
    //convert string into float and assign the to number passed thru
    *integerNumber = atoi(int_buffer);

    return true;
}