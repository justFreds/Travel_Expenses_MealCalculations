#include "expenseSheet.h"
#include <stdio.h>

void totalIncurred(Expenses *e){
    //print line-items of each expense occurred
    //note: total incurred for meals can probably just be the sum total of everything in array meals[][]
    //ex:
    //Expenses incurred:
    //Airfare:              $100.95
    //Meals:                $50.24
}
void totalAllowable(Expenses *e){
    //print line-items of each expense allowable
    //note: total allowable for meals will have to account for departure and arrival time
    //note: this can probably be combined with the above in a single function:
    //ex:
    //Expenses incurred:
    //Airfare:              $100.95
    //Meals:                $50.24
    //      Allowable:      ($37.00)
    //Hotels:               $200.10
    //      Allowable;      ($180.00)                 
}
void totalBill(Expenses *e){
    //display excess or amount saved
}