
#include "Drink.h"


//constructor
Drink::Drink(const char* drink_name_arg) {
	drink_name = new char[strlen(drink_name_arg)+1];
	strcpy(drink_name, drink_name_arg);
};

Drink::~Drink() {

};

//returns the name of the drink
const char* Drink::getName() {
	char* tmp = new char[256];
	sprintf(tmp, "%s", drink_name);
	return tmp;
};
