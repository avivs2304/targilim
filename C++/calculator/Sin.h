/*
 * 		Operation has the ability to calculate the sin value of a RADIAN currVal
 */

#ifndef SIN_H_
#define SIN_H_
#include "calculatorOperation.h"
#include <math.h>

class Sin : public calculatorOperation {
public:
	Sin();
	virtual ~Sin();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* SIN_H_ */
