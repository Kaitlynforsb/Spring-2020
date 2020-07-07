//This class is a subclass of class Media and it is one of the
//two parent classes to class Recommendation.

#ifndef SONGS_H
#define SONGS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Media.h"

using namespace std;

class Shows;

class Songs : public Media  {
protected:
        static vector<string> songs;
        static vector<string> albums;
        static vector<string> artists;
        static vector<string> release_year;
        static vector<string> genres;
	static int song_count;
public:
        void set_songs(); 

	void add_to_vectors(string, string, string, string, string);
		
	static int get_song_count();

        string get_description() const;

	friend string determine_type(Songs song, Shows show);
};


	

#endif
