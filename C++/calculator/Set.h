/*
 * Operation has the ability to set currVal to any specified value
 */

#ifndef SET_H_
#define SET_H_
#include "calculatorOperation.h"

class Set : public calculatorOperation{
public:
	Set();
	virtual ~Set();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* SET_H_ */
