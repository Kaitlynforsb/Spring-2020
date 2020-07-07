#ifndef PET_H
#define PET_H

#include <string>

using namespace std;

class Pet {
private:
	string name;
	string species;
public:
	Pet(string name_param, string species_param) {
		set_name(name_param);
		set_species(species_param);
	}

	void set_name(string name_parameter) {
		name = name_parameter;
	}

	void set_species(string species_parameter) {
		species = species_parameter;
	}

	string get_name() {
		return name;
	}

	string get_species() {
		return species;
	}

};

#endif
