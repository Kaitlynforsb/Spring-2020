#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "random_vector.h"

using namespace std;
      
	//adds all elements in vector together 
	 double RandomIntVector::get_total(int count_param) {

	
		int i; 
		double total = 0;

		for(i = 0; i < count_param; i++) {
			total += rand_ints.at(i); 
		}
		
		return total;	
	}

	//gets average
        double RandomIntVector::get_avg(int count_param) {	
		return (get_total(count_param)/count_param);	
	}

	//returns all the elements in the vector and the number of 
	//elements
        void RandomIntVector::get_str(int count_param) {
		int i;

		cout << "Integers: ";		

		for(i = 0; i < count_param; i++) {
			cout << rand_ints.at(i) << ", ";
		}		
		cout << endl;
		cout << "Count:	" << i;
	}


