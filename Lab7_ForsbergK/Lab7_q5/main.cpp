/* Kaitlyn Forsberg
 * This program creates a vector of random integers with the amount of elements
 * in the vector given by the user. It then outputs all of the random integers in
 * the vector, the number of elements in the vector, and the total and average of 
 * the elements
 */

#include <iostream>
#include <string>
#include <vector>
#include "random_vector.h"

using namespace std;

int main()
{

	char cont = 'y';

while (cont == 'y') {

	cout << endl;
	cout << "Random Integer List" << endl << endl;

	int num;
	cout << "How many random integers should the list contain?: ";
	cin >> num;

	cout << "Random Integers" << endl;
	cout << "===============" << endl;

	//call constructor to make ints
	RandomIntVector rand_ints = RandomIntVector(num);
	rand_ints.get_str(num);	
	cout << endl;
	cout << "Total: " << rand_ints.get_total(num) << endl;
	cout << "Average: " << rand_ints.get_avg(num) << endl;

	cout << "Continue? (y/n): ";
	cin >> cont;
}

	return 0;
}
