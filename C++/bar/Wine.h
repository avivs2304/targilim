
#ifndef WINE_H_
#define WINE_H_
#include "Drink.h"
#include <string>

/*
 * 		Inherits from Drink. has two more members specifying the wine type and year
 * 		also implements getName and prepare
 */

class Wine : public Drink {
public:
	Wine(const int year_arg, const char* drink_type_arg, const char* drink_name_arg);
	virtual ~Wine();
	virtual const void prepare();
	virtual const char* getName();

protected:
	char* drink_type;
	int year;
};

#endif /* WINE_H_ */
