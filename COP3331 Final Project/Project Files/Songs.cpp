#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Songs.h"
#include "Media.h"

int Songs::song_count = 0;
vector<string> Songs::songs;
vector<string> Songs::albums;
vector<string> Songs::artists;
vector<string> Songs::release_year;
vector<string> Songs::genres;

	void Songs::set_songs() {

                ifstream input_file;
                input_file.open("Songs.txt");
                string song, album, artist, year, genre1;

                //ensures file was opened
		 if(input_file) {
                        while(getline(input_file, song, '\t')) {
                                getline(input_file, album, '\t');
                                getline(input_file, artist, '\t');
                                getline(input_file, year, '\t');
                                getline(input_file, genre1, '\n');

				if(genre1 == genre && decade_option == "1" && stoi(year) > 2010) {
                        		add_to_vectors(song, album, artist, year, genre1);
				}
	
				if(genre1 == genre && decade_option == "2" && stoi(year) <= 2010) {
                        		add_to_vectors(song, album, artist, year, genre1);
				}

				if(genre1 == genre && decade_option == "3") {
					add_to_vectors(song, album, artist, year, genre1);
				}
               		} //end while

                }
                else {
                        cout << "File cannot be opened" << endl;
                }

		song_count = songs.size();
                input_file.close();

        }

	//simplifies above function
	void Songs::add_to_vectors(string name_param, string album_param, string artist_param,
                string year_param, string genre_param) {

	       songs.push_back(name_param);
               albums.push_back(album_param);
               artists.push_back(artist_param);
               release_year.push_back(year_param);
               genres.push_back(genre_param);
 
	}

	int Songs::get_song_count() {
                return song_count;
        }

	//function overwritten from Media class -> used for polymorphism
	string Songs::get_description() const {
		return "Chosen Genre: " + genre + "\n";
	}

