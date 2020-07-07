/* Kaitlyn Forsberg
 * This program uses dynamically stored memory to store objects of type Pet.
 * It keeps dynamically stores a Pet with its name and species type and allows
 * the user to make as many Pet objects as they would like. At the end of the program
 * the memory for the objects is deallocated.
 */

#include <iostream>
#include <string>
#include <vector>
#include "Pet.h"

using namespace std;

int main() {

	char choice = 'y';
	vector<Pet*> pets;
	Pet* temp;
	string name, species;	

	cout << endl;
	cout << "Dynamic Pets" << endl << endl;

	while(choice == 'y') {

		cout << "Enter the pet's name: ";
		cin >> name;
		
		cout << "Enter the pet's species: ";
		cin >> species;

		temp = new Pet(name, species);
		pets.push_back(temp);

		cout << "Add another pet? (y/n): ";
		cin >> choice;
		cout << endl;
	}	

	//The -> is used to call the getter functions since pets[i] is a pointer 
	int i, size = pets.size();
	for(i = 0; i < size; i++) {
		cout << pets[i]->get_name() << " is a(n) " << pets[i]->get_species() << endl;
	}

	cout << endl;
	cout << "Bye!" << endl;

	for(i = 0; i < size; i++) {
		delete pets[i];
	}

	return 0;
}
