/* Kaitlyn Forsberg

This program accepts five double values from the user and computes the
sum, average, product, and absolute values of these five numbers
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double one, two, three, four, five;

	cout << "Enter five numbers: ";

	//receive input from console
	cin >> one >> two >> three >> four >> five;

	//perform calculations
	double sum = one + two + three + four + five;
	double average = sum / 5;
	double product = one * two * three * four * five;
	

	//output to console
	cout << "Sum: " << sum << endl
	     << "Average: " << average << endl
	     << "Product: " << product << endl
	     << "Absolute Values: " << abs(one) << " " 
	     << abs(two) << " " << abs(three) << " "
	     << abs(four) << " " << abs(five) << endl
	     << "Done" << endl;
	
	return 0;

} //end main
