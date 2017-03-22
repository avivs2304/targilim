/*
 * 		Operation has the ability to add a value to currVal
 */

#ifndef ADDITION_H_
#define ADDITION_H_
#include "calculatorOperation.h"

class Addition : public calculatorOperation {
public:
	Addition();
	virtual ~Addition();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* ADDITION_H_ */
