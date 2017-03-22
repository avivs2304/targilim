/*
 * Addition.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: aviv
 */

#include "Addition.h"

Addition::Addition() : calculatorOperation() {
	operations = new string[5];
	operations[0]="add";
	operations[1]="Add";
	operations[2]="+";
	operations[3]="plus";
	operations[4]="Plus";
	required_parameters=1;
}

Addition::~Addition() {
	// TODO Auto-generated destructor stub
}

