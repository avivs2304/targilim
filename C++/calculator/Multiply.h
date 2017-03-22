/*
 * 		Operation has the ability to multiply currVal with a parameter value;
 */

#ifndef MULTIPLY_H_
#define MULTIPLY_H_
#include "calculatorOperation.h"

class Multiply : public calculatorOperation {
public:
	Multiply();
	virtual ~Multiply();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* MULTIPLY_H_ */
