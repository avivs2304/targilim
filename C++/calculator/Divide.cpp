
#include "Divide.h"

Divide::Divide() {
	n_operations = 3;
	operations = new string[n_operations];
	operations[0]="divide";
	operations[1]="Divide";
	operations[2]="/";
	required_parameters=1;

}

Divide::~Divide() {
	delete operations;
}

double Divide::calcResult(double currVal, vector<string> parameters){
	return (currVal / atof(parameters[0].c_str()));
}
