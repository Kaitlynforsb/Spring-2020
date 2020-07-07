/* Kaitlyn Forsberg
 * This program randomly generates a number between 1 and 10. It then
 * has the user guess what the randomly generated number is. The user is able
 * to play infinitely many times.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
	char play_again = 'y';
	int upper_limit = 10;
	cout << "\nGuess the number!\n";
	cout << "I'm thinking of a number from 1 to " << upper_limit << "\n\n";

	while (play_again == 'y') {

		//get a random number between 1 and the upper limit
		srand(time(NULL));
		int number = rand() % upper_limit;
		++number;
	
		//initialized guess to random number outside threshold so
		//the condition for the while loop is definitely true
		int guess;
		guess = 11;
		int count = 1;	

		while (guess != number) {

       			cout << "Your guess: ";
			cin >>  guess;

			while (guess < 1 || guess > upper_limit) {
				cout << "Invalid guess. Try again.\n";
				cout << "Your guess: ";
				cin >> guess;  }

				if (guess < number) {
					cout << "Too low.\n"; }
				else if (guess > number) {
					cout << "Too high.\n"; }
				else {
					cout << "You guessed it in " << count << " tries.\n\n"; }

				++count;
	
				}

		cout << "Would you like to play again (y/n)?: "; 
       		cin >> play_again;
						 

		guess = 11;
		count = 1;

	} //end main while loop

	cout << "Bye!\n\n";

	return 0;

} //end main
