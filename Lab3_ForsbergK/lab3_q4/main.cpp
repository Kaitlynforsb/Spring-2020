/* Kaitlyn Forsberg
 * This program reads a list of monthly sales from a separate file 
 * and can print the monthly sales, compute the total
 * yearly sales and the average monthly sale
 */ 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	cout << endl;
        cout << "Monthly Sales" << endl << endl;

        cout << "COMMAND MENU" << endl << "m - View monthly sales"
                << endl << "y - View yearly summary" << endl
                << "x - Exit program" << endl;

	while(true) {

		ifstream input_file;
		input_file.open("monthly_sales.txt");

		cout << endl;
		char option;
		cout << "Command: ";
		cin >> option;

		//enters loop if invalid command or if option == 'x'
		while ((option != 'm') && (option != 'y')){
			if (option == 'x') {
				cout << endl;
				cout << "Bye!" << endl << endl;
				input_file.close();
				return 0; }
			else {
				cout << "Invalid command. Try again. " << endl << endl;
				cout << "Command: ";
				cin >> option; }
							} //end while loop
	
		cout << endl;	

		//determines if file can be opened.
		//reads specified file and outputs the monthly sales.
		//computes the yearly sum and monthly avg through
		//reading the file.
		if (option == 'm' || option == 'y') {
			if(input_file) {
				string month;
				double amount;
				double sum = 0, average = 0;

				if (option == 'm') {
                                                cout << right << setw(15) << "MONTHLY SALES" << endl;
						   }		
				//if option != 'm' then the yearly sum is calculated 
				while ((input_file >> month >> amount)) {
					if (option == 'm') {
						cout << right;	
					//	cout << setw(10) << "MONTHLY SALES" << endl;
						cout << fixed << setprecision(2) << setw(5) << month 
						<< setw(10)  << amount << endl; } 
					else {
						sum += amount;
					     } 
										} //end while loop 
				
				if(option == 'y') {
            	                        average = sum;
                	                average /= 12;
					cout << left;
					cout << "YEARLY SUMMARY" << endl;
                                        cout << fixed << setprecision(2) << left <<  setw(16)
                                             << "Yearly total:" << right << setw(20) << sum << endl;
                                        cout << fixed << setprecision(2) << left << setw(16)
                                             << "Monthly average:" << right <<  setw(20) << average << endl; 
                                                }
							amount = 0;	} //end nested if
								} //end if
	
		
		
	} 
	

} //end main 
