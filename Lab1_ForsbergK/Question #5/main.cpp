/* Kaitlyn Forsberg

This program accepts a double value for diameter from the user 
and outputs to the console the diameter, radius, circumference, and area 
corresponding to a circle of given diameter. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double diameter, radius, circumference, area, pi;	

	cout << "Circle Calculator" << endl << endl;

	//get diameter from user
	cout << "Please enter the diameter: ";
	cin >> diameter;

	//make calculations 
	pi = 3.14159;
	radius = diameter / 2;
	circumference = diameter * pi;
	area = pi * pow(radius, 2.0);

	//round to 1 decimal place
	circumference = round(circumference * 10)/10;
	area = round(area * 10)/10;

	//write output to console
	cout << "Radius: " << radius << endl
	     << "Circumference: " << circumference << endl
	     << "Area: " << area << endl << endl 
	     << "Bye!" << endl << endl;

	return 0;

} //end main
