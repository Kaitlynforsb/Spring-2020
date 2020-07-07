#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Product.h"
#include "Media.h"

using namespace std;

class Movie : public Media {
private:
    int year;
   // string format;
public:
    Movie(string name = "", double price = 0.0, 
          int disc_pct = 0, int year_param = 1888, string format_param = "") 
						: Media(name, price, disc_pct, format) {
        year = year_param;
	format = format_param;
    }

    void set_year(int year_param) {
        year = year_param;
    }
    int get_year() const { return year; }

    string get_description() const {
        return name + " (" + to_string(year) + ')' + " - " + format;
    }
};
#endif // MURACH_MOVIE_H

