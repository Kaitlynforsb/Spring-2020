//This class is the subclass of classes Shows and Songs

#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Media.h"
#include "Songs.h"
#include "Shows.h"

using namespace std;

class Recommendation : public Songs, public Shows {
private:
        static int object_count;
        int rand_int;
        static vector<int> already_used;
public:
        Recommendation();

	void get_song_rec();

	void get_show_rec();

	void get_song_description();

	void get_show_description();

	friend ostream& operator<< (ostream&, Recommendation&);
};




#endif
