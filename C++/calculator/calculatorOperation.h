/*
 * 		Base class sets the structure of what a operation does and what members it holds
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

#ifndef CALCULATOROPERATION_H_
#define CALCULATOROPERATION_H_

class calculatorOperation {
public:
	calculatorOperation();
	virtual ~calculatorOperation();
	bool supportOperation(string op_string);
	const int requiredParameters() {return this->required_parameters;};
	virtual double calcResult(double currVal, vector<string> parameters) = 0;


protected:
	string* operations;
	int required_parameters;
	int n_operations;
};

#endif /* CALCULATOROPERATION_H_ */
