#include "Beer.h"

//constructor
Beer::Beer(const char* drink_name_arg): Drink(drink_name_arg){

}

Beer::~Beer() {
	// TODO Auto-generated destructor stub
}

//outputs how to serve beer
const void Beer::prepare() {
	std::cout << "Well, all you need to do is pour it into a glass and serve." << std::endl;
}

