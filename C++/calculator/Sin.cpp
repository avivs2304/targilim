
#include "Sin.h"

Sin::Sin() {
	n_operations = 2;
	operations = new string[n_operations];
	operations[0]="sin";
	operations[1]="Sin";
	required_parameters=0;

}

Sin::~Sin() {
	delete operations;
}

double Sin::calcResult(double currVal, vector<string> parameters){
	return sin(currVal);
}
