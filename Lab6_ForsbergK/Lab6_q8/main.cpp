/* Kaitlyn Forsberg
 * This program uses user input for height and width so that it can calculate
 * the rectangle's perimeter and area. The perimeter and area is then outputted.
 * A diagram of the rectangle with the user's dimensions is printed to console as well.
 */

#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{

	cout << endl;
	cout << "Rectangle Calculator" << endl;

	int height, width, perim, area;

	char another = 'y';

	while (tolower(another) == 'y') {
	
		Rectangle rectangle;

		cout << "Height: ";
  	        cin >> height;

        	cout << "Width: ";
        	cin >> width;

		//prints perimeter and area to console
		rectangle.set_h(height);
		rectangle.set_w(width);
		perim = rectangle.calculate_perim(height, width);
		area = rectangle.calculate_area(height, width);

		//the output is the diagram of the rectangle
		string output;
		output = rectangle.to_str();

		cout << "Perimeter: " << perim << endl 
			<< "Area: " << area << endl;

		cout << output << endl;

		cout << "Continue? (y/n): ";
		cin >> another;
	}

	cout << "Bye!" << endl;

	return 0;


} //end main 
