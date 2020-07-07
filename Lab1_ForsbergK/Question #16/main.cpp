/* Kaitlyn Forsberg

This program randomly generates midterm and final exam grades. It also computes
the average of these exams. The user is then asked whether the grades
printed on the console are the grades they have gotten. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	//gets seed value for srand
	int elapsed_seconds = time(0);

	//specifies seed value for rand function
	srand(elapsed_seconds);
	
	//generates grade between 0 and 100
	int midterm = rand() % 101;
	int final_grade = rand() % 101;

	int average = (midterm + final_grade)/2;
	
	string first;
	
	cout << "Hi! Enter your first name: ";
	getline(cin, first); 

	cout << "Welcome, " << first << ". Were these" 
		" your exam grades last semester?" << endl << endl;

	cout << "Midterm Grade:\t\t\t" << midterm << endl
	     << "Final Exam Grade:\t\t" << final_grade << endl
	     << "Average:\t\t\t" << average << endl << endl;  

	cout << "Maybe I didn't do so good... " 
		"What do you think?" << endl;

	string user_feedback;
	
	getline(cin, user_feedback);

	cout << first << ", I understand. You feel that \""
	     << user_feedback << "\"; I assure you I tried my best!"; 

	return 0;

} //end main
