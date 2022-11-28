#ifndef FINALCALC_H
#define FINALCALC_H

typedef struct expenses Expenses;

//print line-items of each expense occurred
void totalIncurred(Expenses *e);
//print line-items of each expense allowable
void totalAllowable(Expenses *e);
//display excess or amount saved
void totalBill(Expenses *e);

#endif