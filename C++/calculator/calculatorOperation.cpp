/*
 * calculatorOperation.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: aviv
 */

#include "calculatorOperation.h"

calculatorOperation::calculatorOperation() {
	operations=NULL;
	required_parameters=0;
}

calculatorOperation::~calculatorOperation() {
	// TODO Auto-generated destructor stub
}

bool calculatorOperation::supportOperation(string op_string) {

	int len = sizeof(operations)/sizeof(operations[0]);
	int i=0;
	while(len<i){
		if(operations[i]==op_string) return true;
		i++;
	}
	return false;
}

s
