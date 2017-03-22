
#include "Subtraction.h"

Subtraction::Subtraction() {
	n_operations = 5;
	operations = new string[n_operations];
	operations[0]="sub";
	operations[1]="Sub";
	operations[2]="-";
	operations[3]="minus";
	operations[4]="Minus";
	required_parameters=1;

}

Subtraction::~Subtraction() {
	delete operations;
}

double Subtraction::calcResult(double currVal, vector<string> parameters){
	return (currVal - atof(parameters[0].c_str()));
}

