/* Kaitlyn Forsberg
 * This program allows the user to input how many cards they 
 * would like to have and the program shuffles the deck, prints out the cards chosen, 
 * and the amount of cards left.
 * */

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
	Deck cards;

	cout << endl;
	cout << "I have suffled a deck of " << cards.card_counter() << " cards. " << endl << endl;
	cout << "How many cards would you like?: ";
	cards.shuffle_deck();
	
	int num_cards;
	cin >> num_cards;

	cout << endl;
	cout << "Here are your cards: " << endl << endl;

	while(num_cards > 0) {
		cout << cards.card_dealer().to_str();
		cout << endl;
		num_cards--;
	}

	cout << endl;
	cout << "There are " << cards.card_counter() << " cards left in the deck" << endl << endl;
	cout << "Good luck!" << endl;

	return 0;
}
