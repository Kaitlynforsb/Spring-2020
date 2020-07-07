#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
	string rank;
	string suit;
public:
	Card(string, string);
	string to_str() const;
};



#endif
