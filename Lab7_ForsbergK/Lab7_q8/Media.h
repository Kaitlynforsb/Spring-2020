#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include "Product.h"

using namespace std;

class Media : public Product {
private:
protected:
	string format;
public:
	Media(string name = "", double price = 0.0, int disc_pct = 0,
		string format_param = "") : Product(name, price, disc_pct) {
		
		format = format_param;
	}





};

#endif
