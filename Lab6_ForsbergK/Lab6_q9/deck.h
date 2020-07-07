#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "card.h"

using namespace std;

class Deck {
private:
	vector<Card> deck;	
public:
	Deck();
	void shuffle_deck();
	int card_counter();
	Card card_dealer();		

};



#endif
