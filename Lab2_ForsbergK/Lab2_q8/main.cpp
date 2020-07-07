/* Kaitlyn Forsberg
 * This program extracts characters given by the user and creates a string
 * with these characters. For all characters given by the user, vowels
 * characters are capitalized and consonant letters are put into lower-case
 * before the string is created.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char char1;
	string string1;
	
	do {

		cout << "Enter a character: ";


		//gets first char
		char1 = cin.get();
		cin.ignore();
	
		switch(char1) {
			case 'a':
				 char1 = toupper(char1);
			case 'A':
				break;
			case 'e':
				 char1 = toupper(char1);
			case 'E':
				break;
			case 'i':
				 char1 = toupper(char1);
			case 'I':
				break;
			case 'o':
				 char1 = toupper(char1);
			case 'O':
				break;
			case 'u':
				 char1 = toupper(char1);
			case 'U':
				break;
			default:
				char1 = tolower(char1);
				break;
		}

		//concat strings together 
		if(char1 != '0')
			string1 += char1;
	
	} while(char1 != '0');

	//print string 
	cout << "Your string: " << string1 << endl;

	return 0;

} //end main
