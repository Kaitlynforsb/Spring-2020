#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "deck.h"

using namespace std;
//initialize all the cards
Deck::Deck() {

	vector<string> ranks(13);  
	vector<string> suits(4); 

	ranks[0] = "2";
	ranks[1] = "3";
	ranks[2] = "4";
	ranks[3] = "5";
	ranks[4] = "6";
	ranks[5] = "7";
	ranks[6] = "8";
	ranks[7] = "9";
	ranks[8] = "10";
	ranks[9] = "Jack";
	ranks[10] = "Queen";
	ranks[11] = "King";
	ranks[12] = "Ace";

	suits[0] = "Clubs";
	suits[1] = "Diamonds";
	suits[2] = "Hearts";
	suits[3] = "Spades";
	
	

	unsigned int i, j;
	
	for(i = 0; i < ranks.size(); i++) {
		for(j = 0; j < suits.size(); j++) {
			deck.push_back(Card(ranks[i], suits[j]));

		}
	}

}

void Deck::shuffle_deck() {
	
	srand(time(NULL));	
	
	int size = deck.size();
	int i;

	for(i = 0; i < size; i++) {
		int index2 = rand() % size;
		Card temp = deck[i];
		deck[i] = deck[index2];
		deck[index2] = temp;	
	}

}



int Deck::card_counter() {
	return deck.size();
}
 
//picks a card and the # of cards in the deck is decreased by 1
Card Deck::card_dealer() {

		Card c = deck.back();
		deck.pop_back();
		return c;

}

 
