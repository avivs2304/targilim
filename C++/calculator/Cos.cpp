
#include "Cos.h"

Cos::Cos() {
	n_operations = 2;
	operations = new string[n_operations];
	operations[0]="Cos";
	operations[1]="cos";
	required_parameters=0;

}

Cos::~Cos() {
	delete operations;
}

double Cos::calcResult(double currVal, vector<string> parameters){
	return cos(currVal);
}
