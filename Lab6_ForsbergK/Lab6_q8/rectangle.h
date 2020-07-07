#ifndef RECTANGLE_H 
#define RECTANGLE_H
#include <string>

using namespace std;

class Rectangle {
//private data members 
private:
	int h, w, p, a;
//public member functions
public:	
	void set_h(int);
	int get_h() const;
	void set_w(int);
	int get_w() const;
	int get_p() const;
	int get_a() const;
	int calculate_perim(int h, int w);
        int calculate_area(int h, int w);
	string to_str();

};

#endif
