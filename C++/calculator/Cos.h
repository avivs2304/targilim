/*
 * 		Operation has the ability to calculate the cos value of a RADIAN currVal
 */

#ifndef COS_H_
#define COS_H_
#include "calculatorOperation.h"
#include <math.h>

class Cos : public calculatorOperation {
public:
	Cos();
	virtual ~Cos();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* COS_H_ */
