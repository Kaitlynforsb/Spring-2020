#include <string>
#include "rectangle.h"

using namespace std;

void Rectangle::set_h(int height_param) {
	h = height_param;
}

int Rectangle::get_h() const  {
	return h;
}

void Rectangle::set_w(int width_param) {
	w = width_param;
}
 
int Rectangle::get_w() const {
	return w;
}

int Rectangle::calculate_perim(int height_perim, int width_perim) {
	return ((2*height_perim) + (2*width_perim));
}

int Rectangle::calculate_area(int height_perim, int width_perim) {
	return (height_perim * width_perim);
}

int Rectangle::get_p() const {
	return p;
}
 
int Rectangle::get_a() const {
	return a;	
}

string Rectangle::to_str()  {
	
	int j, i;
	string str = "";
	for(i = 0;i < h;i++)
   	{
		//prints rows of box
       		if(i == 0 || i == (h-1))
        	{
           		for(j = 0;j < w;j++) {
               			str += "* ";
			}
           		str+="\n";
       		}
       		//prints columns of box
		else
       		{
           		str += "* ";
           		for(j = 0;j < (2*w)-5;j++) {
               			str+= " ";
			}
           		str+=" *\n";
       		}
   	}
   return str;
}


