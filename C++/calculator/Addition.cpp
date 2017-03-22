
#include "Addition.h"

Addition::Addition() : calculatorOperation() {
	n_operations = 5;
	operations = new string[n_operations];
	operations[0]="add";
	operations[1]="Add";
	operations[2]="+";
	operations[3]="plus";
	operations[4]="Plus";
	required_parameters=1;
}

Addition::~Addition() {
	delete operations;
}

double Addition::calcResult(double currVal, vector<string> parameters){
	return (currVal + atof(parameters[0].c_str()));
}

