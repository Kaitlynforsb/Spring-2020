#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Shows.h"
#include "Media.h"

using namespace std;

//declarations of static variables - these variables belong to the class
int Shows::show_count = 0;
vector<string> Shows::shows;
vector<string> Shows::years;
vector<string> Shows::ratings;
vector<string> Shows::platforms;
vector<string> Shows::genres;
vector<string> Shows::lengths;

	void Shows::set_shows() {
	
		ifstream input_file;
		input_file.open("Shows.txt");
		string show, year, rating, platform, show_genre, length;

		//ensures file is opened properly and then reads the file
		if(input_file) {
                	        while(getline(input_file, show, '\t')) {
                        	        getline(input_file, year, '\t');
                                	getline(input_file, rating, '\t');
                              		getline(input_file, platform, '\t');
                                	getline(input_file, show_genre, '\t');
					getline(input_file, length, '\n');

					//puts contents of file into its respective vector depending on the 
					//conditions that the user entered
					//first if example: the info is saved if it has the same genre as the user 
					//chosen genre, if the user chose Netflix as the platform, and shows after 
					//the year 2010
					if(show_genre == genre && chosen_platform == 1 && decade_option == "1" && stoi(year) > 2010 
								&& (platform == "Netflix" || platform == "Netflix + Hulu")) {
				
             			        	add_to_vectors(show, year, rating, platform, show_genre, length);
					}
					else if(show_genre == genre && chosen_platform == 1 && decade_option == "2" && stoi(year) <= 2010
								&& (platform == "Netflix" || platform == "Netflix + Hulu")) {

                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                        		}
                        		else if(show_genre == genre && chosen_platform == 1 && decade_option == "3"
                                		                && (platform == "Netflix" || platform == "Netflix + Hulu")) {

                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                         		}
					else if(show_genre == genre && chosen_platform == 2 && decade_option == "1" && stoi(year) > 2010
								&&  (platform == "Hulu" || platform == "Netflix + Hulu")) {
				
    						add_to_vectors(show, year, rating, platform, show_genre, length);
					}
					else if(show_genre == genre && chosen_platform == 2 && decade_option == "2" && stoi(year) <= 2010
                                		                &&  (platform == "Hulu" || platform == "Netflix + Hulu")) {
                                
                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                         		}
					else if(show_genre == genre && chosen_platform == 2 && decade_option == "3"
                                		                &&  (platform == "Hulu" || platform == "Netflix + Hulu")) {
                                
                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                        		}
					else if(show_genre == genre && chosen_platform == 3 && decade_option == "1" && stoi(year) > 2010) {

						add_to_vectors(show, year, rating, platform, show_genre, length);
					}
					else if(show_genre == genre && chosen_platform == 3 && decade_option == "2" && stoi(year) <= 2010) {

                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                        		}
					else if(show_genre == genre && chosen_platform == 3 && decade_option == "3") {

                                		add_to_vectors(show, year, rating, platform, show_genre, length);
                        		}
	
                	} //end while
         	} //end if
                	else {
                        	cout << "File cannot be opened" << endl;
                	}
	
			show_count = shows.size();
		
			input_file.close();
	}

	//simplifies the above function 
	void Shows::add_to_vectors(string name_param, string year_param, string rating_param,
			string platform_param, string genre_param, string length_param) {
		
			shows.push_back(name_param);
        	        years.push_back(year_param);
                	ratings.push_back(rating_param);
                	platforms.push_back(platform_param);
                	genres.push_back(genre_param);
                	lengths.push_back(length_param);	
	}	

	//overwritten function from parent class (Media) -> uses polymorphism
	string Shows::get_description() const {

		string platform_desc;
		if(chosen_platform == 1) {
			platform_desc = "Netflix";
		}
		else if(chosen_platform == 2) {
			platform_desc = "Hulu";
		}
		else if(chosen_platform == 3) {
			platform_desc = "Any Platform";
		}	

		return "Chosen Genre: " + genre + "\n" +
			"Platform: " + platform_desc + "\n";
	}
