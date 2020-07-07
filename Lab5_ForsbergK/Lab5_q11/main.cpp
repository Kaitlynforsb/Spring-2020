/* Kaitlyn Forsberg
 * This program generates a ten random numbers and allows the user to enter
 * a number between 0 and 100 (0 allows the user to exit). The program then checks
 * whether the number the user entered is in the random number set. 
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

	cout << endl;
	cout << "Binary Search program" << endl << endl;
	cout << "Enter 0 to exit" << endl << endl;

	int elapsed_seconds = time(nullptr);
	srand(elapsed_seconds);
	
	vector<int> random_nums(10);	

	int i;
	//sets 10 random numbers
	for(i = 0; i < 10; i++) {
		random_nums[i] = (rand() % 100) + 1;
	}
	
	int j;
	cout << "Random numbers:  [ ";

	//print random number list
	for(j = 0; j < 10; j++) {
		cout << random_nums[j] << " ";
	}
	
	cout << "]" << endl;

	while(true) {

		cout << "Enter a number from 1 to 100: ";
	
		int choice;
		cin >> choice;

		if(choice == 0) {
			cout << "Bye!" << endl << endl;
			return 0;
		}
		
		while(choice < 0 || choice > 100) {
			cout << "Invalid data! Enter a number from 1 to 100: ";
			cin >> choice;
			cout << endl;
		}

		//sort numbers in ascending order
		sort(random_nums.begin(), random_nums.end());

		bool is_found;
		
		//determines if user's choice if within the random number set
		is_found = binary_search(random_nums.begin(), random_nums.end(), choice);

		if(is_found == true) {
			cout << choice << " is in random numbers. " << endl << endl;
		}
		else {
			cout << choice << " is NOT in random numbers. " << endl << endl;
		}
	
	} //end while loop



} //end main 
