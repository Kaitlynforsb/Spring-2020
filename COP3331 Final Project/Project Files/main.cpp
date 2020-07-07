/* Kaitlyn Forsberg
 * This program can give two different types of Media recommendations (Song(s) or Television Show(s))
 * It gives these recommendations based upon the input that the user provides for each type 
 * of media (genre, platform, etc). It also can save these recommendations if the user
 * would like to view them later. It also provides error checking to ensure that the
 * user enters the correct data type and within the bounds given.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "Recommendation.h"
#include "Songs.h"
#include "Shows.h"
#include "Media.h"

using namespace std;

//function declarations
void write_file(string file_name, int num_rec_param);
void get_info(Media &param, string type_param, string num_rec_param, 
                                string genre_param, string decade_param); 
void view_saved(string media_type, string file_name);

int main() {

	cout << endl;
	cout << "Recommendation Generator for Television Shows and Music" << endl << endl;

	string start_menu;

	cout << "Please choose an option: (1-3)" << endl
	     << "1. Get Recommendations" << endl
	     << "2. View Previously Saved Show Recommendations" << endl
	     << "3. View Previously Saved Song Recommendations" << endl
	     << "Option: ";

	cin >> start_menu;

	while(start_menu != "1" && start_menu != "2" && start_menu != "3") {
		cout << "Invalid input. Please enter an integer between 1 and 3" << endl
		     << "Option: ";
		cin >> start_menu;
		cout << endl;
	}

	cout << endl;
	if(start_menu == "2") {
		view_saved("Television shows", "Saved_shows.txt");	
		cout << "Bye!" << endl << endl;
		return 0;
	}
	else if(start_menu == "3") {
		view_saved("Music", "Saved_songs.txt");
		cout << "Bye!" << endl << endl;
		return 0;
	}
	
	cout << "Please choose from the following selections for recommendations (1-2): " << endl
	     << "1. Television shows " << endl
	     << "2. Music " << endl
	     << "Option: ";

	string option;
	cin >> option;
	while(option != "1" && option != "2") {
		cout << "Invalid input. Enter '1' or '2'" << endl
		     << "Option: ";
		cin >> option;
	}

	if(option == "1") {
		option = "Television shows";
	}
	else if(option == "2") {
		option = "Music";
	}

	cout << endl;

	int integer_genre;
	string genre;
	cout << "What genre of " << option << " would you like?" << endl
	     << "Please choose from the following genres: (1-7)" << endl;

	if(option == "Music") {
	     	 cout << "1. Pop" << endl
	              << "2. Country" << endl
	              << "3. Rock" << endl
	              << "4. Alternative" << endl
	              << "5. R&B" << endl
	              << "6. Rap" << endl
	              << "7. Electronic" << endl;
	}
	else {
		cout << "1. Drama" << endl
		     << "2. Sci-fi" << endl
		     << "3. Crime" << endl
		     << "4. Horror" << endl
		     << "5. Comedy" << endl
		     << "6. Anime" << endl
		     << "7. Action" << endl;				
	}

	cout << "Option: ";
	cin >> integer_genre;
	while((!cin) || (integer_genre < 1) || (integer_genre > 7)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter an integer between 1 and 7" << endl
		   << "Option: ";
		cin >> integer_genre;
		cout << endl;
	}

	if(option == "Music") {	
		if(integer_genre == 1) {
			genre = "Pop";
		}
		else if(integer_genre == 2) {	
			genre = "Country";
		}
		else if(integer_genre == 3) {	
			genre = "Rock";
		}
		else if(integer_genre == 4) {
			genre = "Alternative";
		}
		else if(integer_genre == 5) {
			genre = "R&B";
		}
		else if(integer_genre == 6) {
			genre = "Rap";
		}
		else if(integer_genre == 7) {
			genre = "Electronic";
		}
	}

	if(option == "Television shows") {
		if(integer_genre == 1) {
			genre = "Drama";
	        }
		else if(integer_genre == 2) {
			genre = "Sci-fi";
        	}
		else if(integer_genre == 3) {
			genre = "Crime";
        	}
		else if(integer_genre == 4) {
			genre = "Horror";
        	}
		else if(integer_genre == 5) {	
			genre = "Comedy";
       		}
		else if(integer_genre == 6) {
			genre = "Anime";
        	}
		else if(integer_genre == 7) {
			genre = "Action";
        	}
	}

	cout << endl;

	string dec_option, modified_dec_option;

	cout << "Please choose a time period for the release date (1-3)" << endl
             << "1. " << option << " after 2010" << endl
             << "2. " << option << " before 2010 (+ 2010)" << endl
             << "3. Any time" << endl
             << "Option: ";
        cin >> dec_option;

	while(dec_option != "1" && dec_option != "2" && dec_option != "3") {
                        cout << "Invalid input. Please enter a number between 1 and 3: " << endl
                             << "Option: ";
                        cin >> dec_option;
                        cout << endl;
        }

	if(dec_option == "1") {
		modified_dec_option = option + " after 2010";
	}
	else if(dec_option == "2") {
		 modified_dec_option = option + " before 2010 (+ 2010)";
	}
	else if(dec_option == "3") {
		modified_dec_option = "Any time";
	}

	cout << endl;

	int num_genre, num_rec, platform_option;
	if(option == "Music" ) {
                Songs songs;
                songs.set_media_type(option);
		songs.set_genre(genre);
		songs.set_decade_option(dec_option);
		songs.set_songs();
		num_genre = songs.get_song_count();
        	
        	cout << "How many song recommendations would you like? (1-" << num_genre << ")" << endl
       	 	     << "Option: ";
		cin >> num_rec;
		cout << endl << endl;

		while((!cin) || (num_rec < 1) || (num_rec > num_genre)) {
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	cout << "Invalid input. Please enter an integer between 1 and " << num_genre << endl
                	   << "Option: ";
                	cin >> num_rec;
        	        cout << endl;
		}

		songs.set_num_recs(num_rec);
		get_info(songs, option, to_string(num_rec), genre, modified_dec_option);
		cout << endl;
	}
	else if(option == "Television shows") {
		cout << "Would you like to choose a specific platform for watching?" << endl
		     << "Choose from the following options (1-3): " << endl
		     << "1. Netflix" << endl
		     << "2. Hulu" << endl
		     << "3. Either platform" << endl;

		cout << "Option: ";
		cin >> platform_option;
		cout << endl;
	
		 while((!cin) || (platform_option < 1) || (platform_option > 3)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter an integer between 1 and 3" << endl
                           << "Option: ";
                        cin >> platform_option;
                        cout << endl;
                }

		Shows shows;
		shows.set_media_type(option);
		shows.set_genre(genre);
		shows.set_chosen_platform(platform_option);
		shows.set_decade_option(dec_option);
		shows.set_shows();
		num_genre = shows.get_show_count();

		cout << "How many show recommendations would you like? (1-" << num_genre << ")" << endl
		     << "Option: ";
                cin >> num_rec;
                cout << endl;

		while((!cin) || (num_rec < 1) || (num_rec > num_genre)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter an integer between 1 and " << num_genre << endl
                           << "Option: ";
                        cin >> num_rec;
                        cout << endl;
                }
		
		shows.set_num_recs(num_rec);	
		get_info(shows, option, to_string(num_rec), genre, modified_dec_option);
		cout << endl;
	
	} //end else if

		//asks the user if they want to save each recommendation 
		//& saves it if they choose 'y'
		if(option == "Television shows") {	
			write_file("Saved_shows.txt", num_rec);	
		}
		else if(option == "Music") {
			write_file("Saved_songs.txt", num_rec);
		}

	

	cout << endl;
	cout << "Bye!" << endl;

	return 0;

} //end main

	void write_file(string file_name, int num_rec_param) {
		int i;
		string save;
		ofstream output_file;

		for(i = 0; i < num_rec_param; i++) {
                        Recommendation rec;
                        
			if(file_name == "Saved_songs.txt") {
				rec.get_song_rec();
                        	rec.get_song_description();
			}
			else if(file_name == "Saved_shows.txt") {
				rec.get_show_rec();
                        	rec.get_show_description();
			}
		
                        cout << "Would you like to save this recommendation? (y/n)" << endl
                             << "Option: ";
                        cin >> save;
                        cin.ignore();

                        while(save != "y" && save != "n") {
                                cout << "Invalid input. Please enter 'y' or 'n'" << endl
                                     << "Option: ";
                                cin >> save;
                                cin.ignore();
                        }

                        cout << endl;

                        if(save == "y") {
                                output_file.open(file_name, ios::app);
                                output_file << rec;
                                output_file.close();
                        }
                }
	} //end function

	//function that uses polymorphism to call virtual function get_description()
	void get_info(Media &param, string type_param, string num_rec_param, 
				string genre_param, string decade_param) {
        
		cout << "Media Type: " << type_param << endl
                        << "Number of Recommendations: " << num_rec_param << endl
                        << "Chosen Decade: " << decade_param << endl
			<< param.get_description();
	} //end function

	void view_saved(string media_type, string file_name) {
		ifstream input_file;
		string line;		
		input_file.open(file_name);

		if(input_file) {
			if(file_name == "Saved_songs.txt") {
				while(getline(input_file, line)) {
					cout << line << endl;
				}
			}
			else if(file_name == "Saved_shows.txt") {
				 while(getline(input_file, line)) {
	                	       	        cout << line << endl;
                       		}
			}
		}
		else {
			cout << "No recommendations have been made yet" << endl << endl;
		}

	} //end function


