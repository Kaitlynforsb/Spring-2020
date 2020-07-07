/* Kaitlyn Forsberg
 * This program allows the user to choose a day to view the menu by
 * reading a given file. It reads the text within the file and 
 * stores the values for name, price, and day in a vector of structres.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct MenuItem {
	string name;
	int price;
	string day;
};


int main()
{

	cout << endl;
	cout << "Menu of the Day" << endl << endl;

	cout << "COMMAND MENU" << endl << "Specify the day using"
	     << " the three-letter format " << "(mon, tue, wed, thu, " 
	     << "fri, sat, sun)." << endl << "Or, enter 'exit' to exit" << endl << endl;

	string choice = "mon";

while (true) {

	cout << "Day: ";
	cin >> choice;
	cin.ignore();

	if (choice == "exit") {
		cout << "Bye!" << endl;
		return 0;
	}
	
	vector<MenuItem> menu(20);

	ifstream input_file;
	input_file.open("menu.txt");

	//if file opened successfully
	if (input_file) {

		//i is an item to be added to vector 
		int item = 0;
		while (true) {
	
		stringstream ss;
		string line;

		//reads a  line from file and stores the text into 
		//the stringstream
		getline(input_file, line);
		ss.str(line);

		//getline function reads stringstream until a 
		//tab is encountered 
		getline(ss, menu[item].name, '\t');
		ss >> menu[item].price;
		ss >> menu[item].day;

			if (item < 19) {	
				item++; }
			else {
				break; }
			
		} //end while loop 

	//iterate through vector of structures to determine what
	//menu choices correspond with the day that the 
	//user has chosen
	unsigned int j;
          for (j = 0; j < 20; j++) {
		 if (choice == menu[j].day) {
                        cout << fixed << left << setw(30) <<  menu[j].name << "\t"
                             << setw(30) << menu[j].price << endl;
		  } 
          }

	cout << endl;

	} //end if statement  
	else {
		cout << "File cannot be opened";
		return 0;
	}

} //end while loop		

} //end main 

