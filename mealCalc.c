#include "expenseSheet.h"
#include <stdio.h>

//fill out the meals array based on user input
//will depend on the hour parameters of depart/arrival days
//as well as number of whole days
void getMeals(Expenses *e){
    //reset all meals to 0
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 3; j++)
            e->meals[i][j] = 0;
    
    //fill out the array (price of each meal) based on user input
    //rows are days (0 is day 1)
    //cols are meals (0 = breakfast, 1 = lunch, 2 = dinner)
    //ex: e->meals[0][1] refers to lunch on the 1st (departure) day
        
}

//print the array for testing
void printMeals(Expenses *e){
    for (int i = 0; i < e->totalDays; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", e->meals[i][j]);
        }
        printf("\n");
    }

}