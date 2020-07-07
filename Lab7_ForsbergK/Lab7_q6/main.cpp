/* Kaitlyn Forsberg
 * This program calculates the flight time and required fuel amount for
 * a Cessna 172N based upon the specified distance in nautical miles
 * by the user
 */

#include <iostream>
#include <string>
#include <cmath>

#define MPH 120
#define gal_per_hour 8.4

using namespace std;

int main() 
{

	cout << endl;
	cout << "Aircraft Fuel Calculator" << endl << endl;

	char cont = 'y';
		
while(cont == 'y') {

	int distance, time_hours;
	double time_minutes;
	cout << "Distance in nautical miles: ";
	cin >> distance;

	time_hours = distance / MPH; 
	time_minutes = (distance % MPH) / 120.0;
	time_minutes *= 60;
	time_minutes = (int)time_minutes;

	cout << "Flight time: " << time_hours << " hour(s) and "
		<< time_minutes << " minute(s)" << endl;

	//calculates total time in hrs to calculate the required 
	//fuel amount	
	double req_fuel, total_in_hrs, total_min;
	total_min = (60.0*time_hours) + time_minutes;
	total_min += 30;
	total_in_hrs = total_min / 60;
	req_fuel = gal_per_hour * total_in_hrs;
	req_fuel = ceil(req_fuel * 10)/10;
	
	cout << "Required fuel: " << req_fuel << " gallons" << endl << endl;

	cout << "Continue? (y/n): ";
	cin >> cont;

} //end while 

	cout << endl;
	cout << "Bye!" << endl << endl;
	return 0;

} //end main
