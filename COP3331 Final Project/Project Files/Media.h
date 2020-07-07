//This is an abstract class and it is the parent class to the Songs 
//and Shows subclasses.

#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>

using namespace std;


class Media {
protected:
        int num_recs;
        string media_type;
	string decade_option;	
	string genre;
public:
        void set_num_recs(int num_recs_param) {
                num_recs = num_recs_param;
        }

        void set_media_type(string param) {
                media_type = param;
        }

	void set_decade_option(string option_param) {
		decade_option = option_param;
	}

        void set_genre(string genre_param) {
                genre = genre_param;
        }

	//pure virtual function - must be overridden by subclasses (Polymorphism)
	virtual string get_description() const = 0;
};


#endif
