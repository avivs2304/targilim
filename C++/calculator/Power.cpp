
#include "Power.h"

Power::Power() {
	n_operations = 5;
	operations = new string[n_operations];
	operations[0]="power";
	operations[1]="Power";
	operations[2]="**";
	operations[3]="pow";
	operations[4]="Pow";
	required_parameters=1;


}

Power::~Power() {
	delete operations;
}


//if there is no parameters it powers by 2 if there is it powers by the parameter value
double Power::calcResult(double currVal, vector<string> parameters){
	if(parameters.size()==0){
		return (currVal * currVal);
	}
	double tmpVal=currVal;
	for(int i = 1; i<atoi(parameters[0].c_str());i++)
	{
		tmpVal=tmpVal*currVal;
	}
	return tmpVal;
}
