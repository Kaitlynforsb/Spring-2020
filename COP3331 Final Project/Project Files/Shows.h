//This class is one of the subclasses of the Media class and it is
//one of the two parent classes to the Recommendations class.

#ifndef SHOWS_H
#define SHOWS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Media.h"
#include "Songs.h"

using namespace std;

class Shows : public Media { 
private:
	void add_to_vectors(string, string, string, string, string, string);
protected:
	static vector<string> shows;
	static vector<string> years;
	static vector<string> ratings;
	static vector<string> platforms;
	static vector<string> genres;
	static vector<string> lengths;
	static int show_count;
	int chosen_platform;
public:
	void set_shows();
	
	//overrides virtual function from Media class
	string get_description() const;	

	static int get_show_count() {
		return show_count;
	} 	

	void set_chosen_platform(int platform_param) {
		chosen_platform = platform_param;
	}

	friend string determine_type(Songs song, Shows show);
};

#endif
