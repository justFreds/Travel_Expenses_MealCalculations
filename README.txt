README:

Responsibilities:
	
	implement: 
			main.c: 		Cong Shen
		TASK 1: expenseSheet.c: 	group member 1
		TASK 2: mealCalc.c: 		group member 2
		TASK 3: finalCalc.c:		group member 3
	
	unit-testing and debugging (and input validation?): group member 4


### TASK 1: expenseSheet.c/.h

	** this file holds the Struct of all relevant fields **
	** the struct will be filled out and passed to all other tasks.**

1.1v	void fillExpenses(Expenses *e)
		fill out the struct for everything that does not need calculation
		note: meals will be filled out by another group member

	

1.2	void printExpenses(Expenses *e)
		print everything in the struct filled out so far (for testing)
	
	

### TASK 2: mealCalc.c/.h

	** meals are stored in a 2D array: meals[days][mealType] **
	** rows are days (0 is day 1)
    	** cols are meals (0 = breakfast, 1 = lunch, 2 = dinner)
    	** ex: e->meals[0][1] refers to lunch on the 1st (departure) day

2.1	void getMeals(Expenses *e)
		fill out the array ($ of each meal) based on user input 
		accounting for departure and arrival
	
2.2	void printMeals(Expenses *e)
		//print the array for testing, after being filled

### TASK 3: finalCalc.c/.h

	** Performs the final calculations per the following instructions:

	** The program should calculate and display: 
	** the total expenses incurred by the businessperson, 
	** the total allowable expenses for the trip, 
	** the excess that must be reimbursed by the businessperson, if any.
	** The amount saved by the businessperson if the expenses were under the total allowed
	
	skeleton functions below: (just a suggestion)
	
	//print line-items of each expense occurred
	void totalIncurred(Expenses *e);
	//print line-items of each expense allowable
	void totalAllowable(Expenses *e);
	//display excess or amount saved
	void totalBill(Expenses *e);

### TASK 4: unit testing, debugging, and possibly input validation