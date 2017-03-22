
#include "Sqrt.h"
#include <math.h>

Sqrt::Sqrt() {
	n_operations = 6;
	operations = new string[n_operations];
	operations[0]="sqrt";
	operations[1]="Sqrt";
	operations[2]="Square";
	operations[3]="square";
	operations[4]="root";
	operations[5]="Root";
	required_parameters=0;

}

Sqrt::~Sqrt() {
	delete operations;
}

double Sqrt::calcResult(double currVal, vector<string> parameters){
	return sqrt(currVal);
}

