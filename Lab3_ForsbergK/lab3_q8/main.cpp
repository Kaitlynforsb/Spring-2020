/* Kaitlyn Forsberg 
 * This program allows the user to pick up items, discard items, and 
 * display the current items on-hand. The user can carry up to
 * four items at a time. It uses various functions to separate the
 * commands the user inputs. 
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//function declarations 
void walking ();
void show ();
void drop ();

int main()
{

cout << endl;
cout << "COMMAND MENU" << endl;
cout << "walk - Walk down the path\n" 
     << "show - Show all items\n"
     << "drop - Drop an item\n"
     << "exit - Exit program\n" << endl;

	
string command = "walk";

while (command != "exit") {

	cout << endl;
	cout << "Command: ";
	cin >> command;

	if (command == "walk") {
		walking();
	}
	else if (command == "show") {
		show();		
	}
	else if (command == "drop"){
		drop();
	} 
	else {
		cout << endl;
        	cout << "Bye!" << endl;
        	return 0;
	}
}

} //end main

void walking () {

	//open file
	ifstream input_file;
        input_file.open("wizard_all_items.txt");

	//used to generate random number 
	int elapsed_seconds = time(nullptr);
	srand(elapsed_seconds); 

	vector<string> items(9);
        
	 //checks if file successfully opened
	 //reads input from file with all the possible items
        	if (input_file) {
			int i = 0;
    	 		while (getline(input_file, items[i])) {       
				i++;
				if (i < 0 || i > 8) {
					break;
				}
			} //end while loop
			
	          } //end if statement

	input_file.close();

		//index between 0 and 8
	int index = rand() % 9;

	cout << "While walking down a path, you see "
	     << items[index] << "." << endl 
	     << "Do you want to grab it? (y/n): ";

	char grab;
	cin >> grab;

	if (grab == 'n') {
		return;	
	}

	vector<string> current_items(4);
	//current items
	fstream current_bag;
        current_bag.open("wizards_items.txt", ios::in);

	//if file does not exist then it is created and the item is added			
	if (!current_bag) {
		cout << "You picked up a " << items[index] << endl;
		
		current_bag.open("wizards_items.txt", ios::app);
			
		current_bag << items[index] << endl;	
		current_bag.close();

         }
	//if file does exist and the user has less than 4 items 
	//then the item is added - given user selected 'y' 
       	else {
               	string item;

		int size = 1;
               	while (getline(current_bag, current_items[size-1])) {
			if (size < 4) {
				size++;
			}
			else {
				 
                           cout << "You can't carry any more items. "
                              	        "Drop something first. " << endl;

                               	current_bag.close();
                               	return;
				}
			}
		
		current_bag.close();
		current_bag.open("wizards_items.txt", ios::app);
		current_bag << items[index] << endl;
		cout << "You picked up " << items[index] << endl;
		current_bag.close();					
		
	 }
		

} //end function 

void show () {

		fstream current_bag;
                current_bag.open("wizards_items.txt", ios::in);
	
		//file cannot be opened / doesn't exist	
		if (!current_bag) {
			cout << "Bag is empty.";
		 }
		//lists all items within user's item file
		else {
			string item;
			int counter = 0;
			while (getline(current_bag, item)) {       
				counter++;
                        	cout << counter << ". " <<  item <<  endl; 
			}
		}

		current_bag.close();	

} //end function 

void drop () {

	fstream current_bag;
        current_bag.open("wizards_items.txt", ios::in);

	vector<string> current_items(4);

	cout << "Number: ";
	int number;
	cin >> number;

	//user validation since only 4 items can on-hand
	//at a time
	while (number < 1 || number > 4) {
		cout << "Invalid number." << endl << "Number: ";
		cin >> number;
	}

	//if file does not exist
	if (!current_bag) {
		cout << "Bag is empty." << endl;	
	}
	//reads items that the user currently has 
	else {
		string item;
		int i = 0;
		while (getline(current_bag, item)) {       
		        current_items[i] = item;
			i++;	
		}


	cout << endl;
	cout << "You dropped " << current_items[number-1] << endl; 
	//gets rid of the item from the vector
	current_items.erase(current_items.begin() + (number-1));	

	current_bag.close();

	//outputs the new vector to the file with the updated
	//items 
	current_bag.open("wizards_items.txt", ios::out);
	unsigned int k;
	for (k = 0; k < current_items.size(); k++) {
		current_bag << current_items[k] << endl;
	}	

	} //end else statement  

	current_bag.close();

} //end function 
