/*
 * 		Operation has the ability to divide currVal with a parameter
 */

#ifndef DIVIDE_H_
#define DIVIDE_H_
#include "calculatorOperation.h"

class Divide : public calculatorOperation{
public:
	Divide();
	virtual ~Divide();
	virtual double calcResult(double currVal, vector<string> parameters);
};

#endif /* DIVIDE_H_ */
