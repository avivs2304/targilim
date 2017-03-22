/*
 * 		Operation has the ability to subtract a value from currVal
 */

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_
#include "calculatorOperation.h"

class Subtraction : public calculatorOperation {
public:
	Subtraction();
	virtual ~Subtraction();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* SUBTRACTION_H_ */
