#ifndef EXPENSESHEET_H
#define EXPENSESHEET_H
struct expenses
{
    
    int wholeDays;//the number of "whole" days NOT INCLUDING depart and arrive (can be 0)
    double departTime;//the hour of departure (0-23)
    double arriveTime;//the hour of arrival to home (0-23)

    int totalDays;//the total number of days including depart and arrive

    double airfare;//total airfare
    double carRentals;//total car rental (0 if no car was rented)
    int milesDriven;//total miles driven (0 if no private car was used)
    double parkingFees;//total parking fees
    double taxiFees;//total taxi fees

    double registrationFees;//total registration fees
    double hotelExpenses;//total hotel expenses

    //2D array for meals
    //rows: day  (0 == day1)
    //col:  meal (0 == breakfast, 1 == lunch, 2 == dinner)
    double meals[30][3];
    double total_meals, total_allowable_meals, total_owed_meals, total_saved_meals;
};

typedef struct expenses Expenses;

void fillExpenses(Expenses *e);
void printExpenses(Expenses *e);

#endif