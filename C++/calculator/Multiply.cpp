
#include "Multiply.h"

Multiply::Multiply() {
	n_operations = 9;
	operations = new string[n_operations];
	operations[0]="multiply";
	operations[1]="Multiply";
	operations[2]="*";
	operations[3]="Mult";
	operations[4]="mult";
	operations[5]="x";
	operations[6]="X";
	operations[7]="times";
	operations[8]="Times";
	required_parameters=1;

}

Multiply::~Multiply() {
	delete operations;
}

double Multiply::calcResult(double currVal, vector<string> parameters){
	return (currVal * atof(parameters[0].c_str()));
}



