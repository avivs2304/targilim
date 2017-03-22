
#include "Set.h"

Set::Set() {
	n_operations = 8;
	operations = new string[n_operations];
	operations[0]="set";
	operations[1]="Set";
	operations[2]="init";
	operations[3]="Init";
	operations[4]="initialize";
	operations[5]="Inizialize";
	operations[6]="put";
	operations[7]="Put";
	required_parameters=1;


}

Set::~Set() {
	delete operations;
}

double Set::calcResult(double currVal, vector<string> parameters){
	return atof(parameters[0].c_str());
}
