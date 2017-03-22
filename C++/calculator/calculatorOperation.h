/*
 * calculatorOperation.h
 *
 *  Created on: Mar 16, 2017
 *      Author: aviv
 */
#include <iostream>
#include "string.h"
#include "stdio.h"
#include <vector>

using namespace std;

#ifndef CALCULATOROPERATION_H_
#define CALCULATOROPERATION_H_

class calculatorOperation {
public:
	calculatorOperation();
	virtual ~calculatorOperation();
	bool supportOperation(string op_string);
	const int requiredParameters() {return this->required_parameters;};
	virtual double calcResult(double currVal, vector<string> parameters);


protected:
	string* operations;
	int required_parameters;
};

#endif /* CALCULATOROPERATION_H_ */
