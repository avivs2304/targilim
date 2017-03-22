/*
 * 		Operation has the ability to calculate the square root of currVal
 */

#ifndef SQRT_H_
#define SQRT_H_
#include "calculatorOperation.h"

class Sqrt : public calculatorOperation {
public:
	Sqrt();
	virtual ~Sqrt();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* SQRT_H_ */
