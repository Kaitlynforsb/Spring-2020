#include <string>
#include "card.h"

using namespace std;

Card::Card(string rank_param, string suit_param) {
	rank = rank_param;
	suit = suit_param;
}
   
string Card::to_str() const {
	return rank + " of " + suit;
}

