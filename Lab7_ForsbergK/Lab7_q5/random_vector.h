#ifndef random_vector_h
#define random_vector_h
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

class RandomIntVector : public vector<int> {
protected:
	vector<int> rand_ints;
public:
	//constructor to make RandomIntVector objects with count_param elements
	RandomIntVector(int count_param = 0) : vector<int>() {

                srand(time(NULL));

                int i, j;
                for(i = 0; i < count_param; i++) {
                        j = rand() % 100;
			j += 1;
			rand_ints.push_back(j);
                } 
	}

	double get_total(int);
	double get_avg(int);
	void get_str(int);
};

#endif
