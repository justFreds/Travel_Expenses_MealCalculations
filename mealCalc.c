#include "expenseSheet.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10000
#define COMPED_BREAKFAST 9.00
#define COMPED_LUNCH 12.00
#define COMPED_DINNER 16.00

bool parse_float(char *str, double *floatNumber);
void totalSavedAndOwed(char* str, double mealCost, double *total_owed_meals, double *total_saved_meals);

//fill out the meals array based on user input
//will depend on the hour parameters of depart/arrival days
//as well as number of whole days
void getMeals(Expenses *e){
    //reset all meals to 0
    e->total_meals = 0;
    e->total_owed_meals = 0;
    e->total_saved_meals = 0;
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j < 3; j++)
            e->meals[i][j] = 0;

    char *mealType[] = {"breakfast", "lunch", "dinner"};
    double mealCost;
    int day = 1;
    bool parsed_correct = true;

    fflush(stdin);
/*
    FIRST DAY OF TRIP
*/
    if(e->departTime < 7) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->departTime >= 7 && e->departTime < 12) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->departTime >= 12 && e->departTime < 18) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    day++;
/*
    DAY2 thru (LASTDAY-1)
*/
    for(int i = 1; i <= e->wholeDays; i++) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[i][j] = mealCost;
            e->total_meals += mealCost;
        }
        day++;
    }
/*
    LAST DAY
*/
    if(e->arriveTime > 19) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->arriveTime > 13 && e->arriveTime <= 19) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->arriveTime > 8 && e->arriveTime <= 13) {
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
            totalSavedAndOwed(mealType[i], mealCost, &e->total_owed_meals, &e->total_saved_meals);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
}
//print the array for testing
void printMeals(Expenses *e){
    printf("\n");
    for (int i = 0; i < e->totalDays; i++){
        for (int j = 0; j < 3; j++){
            printf("$%6.2lf ", e->meals[i][j]);
        }
        printf("\n");
    }
    printf("\nTotal Cost of Meals: $%6.2lf\n", e->total_meals);
    printf("Total owed : $%6.2lf\nTotal saved: $%6.2lf\n", e->total_owed_meals, e->total_saved_meals);
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
void totalSavedAndOwed(char* str, double mealCost, double *total_owed_meals, double *total_saved_meals) {
    if(str =="breakfast") {
            if(mealCost > COMPED_BREAKFAST) {
                *total_owed_meals += (mealCost - COMPED_BREAKFAST);
            } else if (mealCost < COMPED_BREAKFAST) {
                *total_saved_meals += (COMPED_BREAKFAST - mealCost);
            }
        }
        if(str=="lunch") {
            if(mealCost > COMPED_LUNCH) {
                *total_owed_meals += (mealCost - COMPED_LUNCH);
            } else if (mealCost < COMPED_LUNCH) {
                *total_saved_meals = (COMPED_LUNCH - mealCost);
            }
        }
        if(str=="dinner") {
            if(mealCost > COMPED_DINNER) {
                *total_owed_meals += (mealCost - COMPED_DINNER);
            } else if (mealCost < COMPED_DINNER) {
                *total_saved_meals += (COMPED_DINNER - mealCost);
            }
        }
}