#ifndef BEER_H_
#define BEER_H_
#include "Drink.h"

/*
 * Beer is a Drink, a class inherited from Drink, does not add any members but implements prepare();
 */

class Beer : public Drink {
public:
	Beer(const char* drink_name);
	virtual ~Beer();
	virtual const void prepare();
};

#endif /* BEER_H_ */
