/* Kaitlyn Forsberg
 * This program allows the user to enter the cost of as many items as 
 * the user wants and it calculates a 6% sales tax, the cost of
 * all the items before tax, and the cost of the items after tax.
 * The user can repeat this process until a 0 is entered. 
 */ 

#include <iostream>
#include <iomanip>
#include "console.h"
#include "taxes.h"

using namespace std;
using namespace console;
using namespace tax;

//global variable
double price = 0.0;
double total = 0.0;

int main() {
	
	cout << endl;
	cout << "Sales Tax Calculator" << endl << endl;

while (true) {

	cout << "ENTER ITEMS (ENTER 0 TO END)" << endl;

	while (true) {

		//gets input from user + validates the given input
		price = get_double("Cost of item: ", 0);
	
		total += price;
		
		//if price = 0 then control is transferred out of loop 
		//so that tax and tax+total is calculated
		if (price == 0) {
			break;   }

	} //end while loop 

	double tax, last_total;
	
	//function calls
	tax = tax_amt(total);
	last_total = total_amt(total);

	cout << endl;
	cout << left << setw(18) << "Total: " << fixed << setprecision(2) 
	     << right << setw(18) << total << endl;
	cout << left << setw(18) << "Sales tax: " << fixed << setprecision(2) 
	     << right << setw(18) << tax << endl;
	cout << left << setw(18) << "Total after tax: " << fixed << setprecision(2) 
	     << right << setw(18) << last_total << endl << endl;
	

	//reset values
	total = 0;
	price = 0;


	char option;

	//determines whether the user would like to calculate a new total
	option = get_char("Again? (y/n): ");

	//if option = n then control exits the loop and the
	//program ends
	if (option == 'n') 
		break;
}

	cout << "Thanks, bye!" << endl << endl;
	return 0;

} //end main 
