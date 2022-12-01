#include <stdio.h>
#include "expenseSheet.h"
#include "mealCalc.h"
#include "finalCalc.h"

int main()
{
    void fillExpenses(Expenses *e);
    void printExpenses(Expenses *e);
    void getMeals(Expenses *e);
    void printMeals(Expenses *e);
    void totalIncurred(Expenses *e);
    void totalAllowable(Expenses *e);
    void totalBill(Expenses *e);    
    Expenses trip1; // the struct holding all expenses
    Expenses *tripPtr = &trip1; //a pointer to pass the struct by reference into functions

    tripPtr->total_allowable_meals = 0;
    tripPtr->total_meals = 0;
    tripPtr->total_saved_meals = 0;
    tripPtr->total_owed_meals = 0;
    

    printf("\n*********************************");
    printf("\n*** Travel Expense Calculator ***");
    printf("\n*********************************\n\n");

    //****** TASK 1 ******
    //implement "expenseSheet"

    //get user input for expenses (does not include meals)
    fillExpenses(tripPtr);
    //print everything filled out so far in the struct (for testing)
    printExpenses(tripPtr);

    //****** TASK 2 ******
    //implement "mealCalc"

    //get user input for each relevant meal
    getMeals(tripPtr);
    //print the meals as a grid (for testing)
    printMeals(tripPtr);

    //****** TASK 3 ******
    //implement "finalCalc"

    //Note: the following functions are just guidelines,
    //display total incurred by line item
    totalIncurred(tripPtr);
    //display total allowed by line item
    totalAllowable(tripPtr);
    //display amount saved or reimbursed
    totalBill(tripPtr);

    //****** TASK 4 ******

    //can be responsible for unit tests and debugging
}