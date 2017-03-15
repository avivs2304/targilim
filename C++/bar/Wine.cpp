
#include "Wine.h"

Wine::Wine(const int year_arg, const char* drink_type_arg, const char* drink_name_arg) : Drink(drink_name_arg) {
	drink_type = new char[strlen(drink_type_arg)+1];
	strcpy(drink_type, drink_type_arg);
	this->year = year_arg;
}

Wine::~Wine() {

}
// output wine preparations: if Red or White wine.
const void Wine::prepare() {
	if(strcmp(drink_type,"Red")==0){
		std::cout << "Served with temperature of the room (16* - 18*), only need to pour into glass" << std::endl;
	} else {
		std::cout << "Served cold, only need to pour into glass" << std::endl;
	}
}

// Get name of drink with its year date.
const char* Wine::getName() {
	char* tmp = new char[256];
	sprintf(tmp, "%s (year %d)", drink_name, year);
	return tmp;
}

