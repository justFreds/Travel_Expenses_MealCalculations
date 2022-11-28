#include "expenseSheet.h"
#include <stdio.h>

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

/*
    ****FIRST DAY OF TRIP****
        CALCULATING COMPED MEALS BASED ON DEPARTURE TIME
*/
    if(e->departTime < 7) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay 1 meals: \n");
        //ask for meal costs
        for(int i = 0; i < 3; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->departTime >= 7 && e->departTime < 12) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_LUNCH;
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay 1 meals: \n");
        //ask for meal costs        
        for(int i = 1; i < 3; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
            e->meals[0][i] = mealCost;
            e->total_meals += mealCost;
        }
    }
    else if(e->departTime >= 12 && e->departTime < 18) {
        //tally allowable meals
        e->total_allowable_meals += COMPED_DINNER;

        printf("\nDay 1 meals: \n");
        //ask for meal cost        
        for(int i = 2; i < 3; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
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
        for(int j = 0; j < 3; j++) {
            printf("How much was %s: ", mealType[j]);
            scanf("%lf", &mealCost);
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

        printf("\nDay %d meals: \n", day);
        for(int i = 0; i < 3; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost;            
        }
    }
    else if(e->arriveTime > 13 && e->arriveTime <= 19) {
        e->total_allowable_meals += COMPED_BREAKFAST;
        e->total_allowable_meals += COMPED_LUNCH;
        printf("\nDay %d meals: \n", (day));       
        for(int i = 0; i < 2; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost; 
        }
    }
    else if(e->arriveTime > 8 && e->arriveTime <= 13) {
        e->total_allowable_meals += COMPED_BREAKFAST;
        printf("\nDay %d meals: \n", (day));        
        for(int i = 0; i < 1; i++){
            printf("How much was %s: ", mealType[i]);
            scanf("%lf", &mealCost);
            e->meals[e->totalDays-1][i] = mealCost;
            e->total_meals += mealCost; 
        }
    }
    // printMeals(e);        
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