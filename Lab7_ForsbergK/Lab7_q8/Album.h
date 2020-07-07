#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Product.h"
#include "Media.h"

using namespace std;

class Album : public Media {
private:
	string artist;
public: 
	Album(string name = "", double price = 0.0, int disc_pct = 0,
		string artist_param = "", string format_param = "") : Media(name, price, disc_pct, format) {
		format = format_param;
		artist = artist_param;
	}


	string get_description() const {
		return name + " (" + artist + ")" + " - " + format;
	}





};

#endif
