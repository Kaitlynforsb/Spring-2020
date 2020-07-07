/* Kaitlyn Forsberg
 * 
 * The program determines whether a password is hard, medium, or weak depending
 * upon the given requirements. 
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{

	cout << endl;
	cout << "Password Analyzer " << endl << endl;

	cout << "Enter password: ";

	string string1; 
	cin >> string1;

	cout << endl;

	int len = string1.length();

	int i, num_counter = 0, punct_counter = 0, alpha_counter = 0, up_counter = 0;
		
	//determines the number of digits, punctuation marks, and
	//uppercase letters in the string given

	for (i = 0; i < len; i++) {
		if (isdigit(string1[i])){
			(num_counter)++; }
		
		if(ispunct(string1[i])){
			(punct_counter)++; }

		if(isalpha(string1[i])){
			(alpha_counter)++; }

		if(isupper(string1[i])){
			(up_counter)++; }

	} //end for loop

	int strength; 

	//determines the corresponding strength depending upon the 
	//given requirements. The strength corresponds with the 
	//following switch statement 
	if (num_counter >= 4 && punct_counter >= 3 && alpha_counter >= 8
		&& up_counter >= 2) {
		strength = 1; }
        else if (num_counter >= 2 && punct_counter >= 1 && alpha_counter >= 5
			 && up_counter >= 1) {
                strength = 2; }
	else {
                strength = 3; }

	switch (strength) {
		case 1:
			cout << "Strength: Hard" << endl << endl;
			break;
		case 2:
			cout << "Strength: Medium" << endl << endl;
			break;
		case 3:
			cout << "Strength: Weak" << endl << endl;
	} //end switch

	
	cout << "Bye!" << endl << endl;



} //end main 
