#include <iostream>
#include "string.h"
#include "stdio.h"

#ifndef DRINK_H_
#define DRINK_H_
/*
 * 		base abstract class "Drink" that has a drink name, and two function
 */
class Drink {
public:
	Drink(const char* drink_name_arg);
	virtual ~Drink();
	// pure virtual function that outputs how the drink is prepared
	virtual const void prepare()=0;
	// returns the name of the drink
	virtual const char* getName();

protected:
	char* drink_name;

};
#endif /* DRINK_H_ */
