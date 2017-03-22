/*
 * 		Operation has the ability to power currVal by 2 or by any other specified value
 */

#ifndef POWER_H_
#define POWER_H_
#include "calculatorOperation.h"

class Power : public calculatorOperation {
public:
	Power();
	virtual ~Power();
	virtual double calcResult(double currVal, vector<string> parameters);

};

#endif /* POWER_H_ */
