#include "expenseSheet.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10000

bool parse_float(char *str, double *floatNumber);

void printMeals(Expenses *e);

//fill out the meals array based on user input
//will depend on the hour parameters of depart/arrival days
//as well as number of whole days
void getMeals(Expenses *e){
    //reset all meals to 0
    e->total_meals = 0;
    e->total_allowable_meals = 0;

    for (int i = 0; i <= 30; i++)
        for (int j = 0; j < 3; j++)
            e->meals[i][j] = 0;
    
    //fill out the array (price of each meal) based on user input
    //rows are days (0 is day 1)
    //cols are meals (0 = breakfast, 1 = lunch, 2 = dinner)
    //ex: e->meals[0][1] refers to lunch on the 1st (departure) day
    char *mealType[] = {"breakfast", "lunch", "dinner"};
    const double COMPED_BREAKFAST = 9.00,
                 COMPED_LUNCH     = 12.00,
                 COMPED_DINNER    = 16.00;

    double mealCost;
    int day = 1;
    bool parsed_correct = true;

    fflush(stdin);
/*
    ****FIRST DAY OF TRIP****
        CALCULATING COMPED MEALS BASED ON DEPARTURE TIME
*/
    if(e->departTime < 7) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay %d meals: \n", day);
        for(int i = 0; i < 3; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
    }


                                // printf("\nDay 1 meals: \n");
                                // //ask for meal costs
                                // for(int i = 0; i < 3; i++){
                                //     printf("How much was %s: ", mealType[i]);
                                //     scanf("%lf", &mealCost);
                                //     e->meals[0][i] = mealCost;
                                //     e->total_meals += mealCost;
                                // }
    }
    else if(e->departTime >= 7 && e->departTime < 12) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay %d meals: \n", day);
        for(int i = 1; i < 3; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }      
    }
    else if(e->departTime >= 12 && e->departTime < 18) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay %d meals: \n", day);
        for(int i = 2; i < 3; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    day++;
/*
    ****BETWEEN FIRST AND LAST DAYS OF TRIP****
        TALLYING UP TOTAL MEAL COST/ TOTAL ALLOWED MEALS
*/
    for(int i = 1; i <= e->wholeDays; i++) {
        //tally allowed meals
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay %d meals: \n", day);
        for(int j = 0; j < 3; j++){
            do {
                printf("How much was %s: ", mealType[j]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);
            e->meals[i][j] = mealCost;
            e->total_meals += mealCost;
        }
        day++;
    }

/*
    ****LAST DAY OF TRIP****
        CALCULATING COMPED MEALS BASED ON ARRIVAL TIME
*/
    if(e->arriveTime > 19) {
        //tally allowed meals
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;
        printf("\nDay %d meals: \n", (day));         
        for(int i = 0; i < 3; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;   
        }        

    }
    else if(e->arriveTime > 13 && e->arriveTime <= 19) {
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        printf("\nDay %d meals: \n", (day));
        for(int i = 0; i < 2; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;               
        }
    }
    else if(e->arriveTime > 8 && e->arriveTime <= 13) {
        e->total_allowable_meals += COMPED_BREAKFAST;
        printf("\nDay %d meals: \n", (day));        
        for(int i = 0; i < 1; i++){
            do {
                printf("How much was %s: ", mealType[i]);
                char buffer[BUFFER_SIZE];
                fgets(buffer, BUFFER_SIZE, stdin);

                parsed_correct = parse_float(buffer, &mealCost);
                if(!parsed_correct) {
                    printf("Error: Please input valid price!\n");
                }
            } while(!parsed_correct);

            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost; 
        }
    }
    printMeals(e);        
}

//print the array for testing
void printMeals(Expenses *e){
    for (int i = 0; i < e->totalDays; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", e->meals[i][j]);
        }
        printf("\n");
    }

    printf("Total Allowable Meals: $%lf\n", e->total_allowable_meals);
    printf("Total Cost of Meals: $%lf\n", e->total_meals);
}
//_____5.2______\n\0
//float_buffer: 5.2
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