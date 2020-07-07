#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Recommendation.h"
#include "Songs.h"
#include "Shows.h"

using namespace std;

	//forward function declaration - friend function used in 
	//overloading operator function 
	string determine_type();	

	int Recommendation::object_count = 0;
	vector<int> Recommendation::already_used;

	//constructor
	Recommendation::Recommendation() : Songs(), Shows() {
		object_count++;
	}

	//Generates a new random index to be pulled from either the
	//shows or songs vector that was created in those classes.
	//The index generated has not been used before so that
	//a rec is not given more than once
	void Recommendation::get_song_rec() {
	
                int elapsed_seconds = time(nullptr);
                srand(elapsed_seconds);

		//0 to # of songs in the file		
		if(song_count != 0) {
                	rand_int = rand() % song_count;
		}
	
               	int i;
		int used_size = already_used.size();
                for(i = 0; i < used_size; i++) {
                        if(already_used[i] == rand_int && song_count != 0) {
               	                rand_int = rand() % song_count;
                       	        i = -1;
               		}
	 	}

               	already_used.push_back(rand_int);
		used_size++;
	}

	//similar to above function, but for shows
	void Recommendation::get_show_rec() {

		int elapsed_seconds = time(nullptr);
                srand(elapsed_seconds);

		if(show_count != 0) {
			rand_int = rand() % show_count;
		}

		int i;
                int used_size = already_used.size();
                for(i = 0; i < used_size; i++) {
                        if(already_used[i] == rand_int && show_count != 0) {
                                rand_int = rand() % show_count;
                                i = -1;
                        }
                }

                already_used.push_back(rand_int);
                used_size++;

	}

	void Recommendation::get_song_description() {
                        cout << "Song Recommendation #" << object_count << ": " << endl
			     << "Name: " <<  songs[already_used[object_count-1]] << endl
                             << "Album: " << albums[already_used[object_count-1]] << endl
                             << "Artist: " << artists[already_used[object_count-1]] << endl
                             << "Release Year: " << release_year[already_used[object_count-1]] << endl
                             << "Genre: " << Songs::genres[already_used[object_count-1]] << endl << endl;
	
	}

	void Recommendation::get_show_description() {
		 cout << "Show Recommendation #" << object_count << ": " << endl
                             << "Name: " <<  shows[already_used[object_count-1]] << endl
                             << "Release Year: " << years[already_used[object_count-1]] << endl
                             << "IMDB Rating: " << ratings[already_used[object_count-1]] << "/10" << endl
                             << "Platform: " << platforms[already_used[object_count-1]] << endl
                             << "Genre: " << Shows::genres[already_used[object_count-1]] << endl
			     << "Approx Length Per Ep: " << lengths[already_used[object_count-1]] << " hr(s)" << endl << endl;



	}

	//Recommendation is friend of ostream class 
	ostream& operator<< (ostream& out, Recommendation& rec_param) {
		int size = Recommendation::object_count; 
		Songs song_param;	
		Shows show_param;
		string media_type = determine_type(song_param, show_param);	
		
		if(media_type == "Television shows") {
			out << "Name: " <<  rec_param.shows[rec_param.already_used[size-1]] << endl
                	    << "Release Year: " << rec_param.years[rec_param.already_used[size-1]] << endl
               		    << "IMDB Rating: " << rec_param.ratings[rec_param.already_used[size-1]] << "/10" << endl
                    	    << "Platform: " << rec_param.platforms[rec_param.already_used[size-1]] << endl
                            << "Genre: " << rec_param.Shows::genres[rec_param.already_used[size-1]] << endl
                            << "Approx Length Per Ep: " << rec_param.lengths[rec_param.already_used[size-1]] 
           	            								<< " hr(s)" << endl << endl;
		}
        
		else if(media_type == "Music") {
			out << "Name: " << rec_param.songs[rec_param.already_used[size-1]] << endl
        	            << "Album: " << rec_param.albums[rec_param.already_used[size-1]] << endl
        	            << "Artist: " << rec_param.artists[rec_param.already_used[size-1]] << endl
        	            << "Release Year: " << rec_param.release_year[rec_param.already_used[size-1]] << endl
        	            << "Genre: " << rec_param.Songs::genres[rec_param.already_used[size-1]] << endl << endl;
		}       

			return out;
	
	}

	//friend function -> used in above function to determine type of media 
	string determine_type(Songs song, Shows show) {
		if(song.song_count == 0) {
			return "Television shows";
		}
		else if(show.show_count == 0) {
			return "Music";
		}	
		
		return 0;
	}



