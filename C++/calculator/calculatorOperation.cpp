
#include "calculatorOperation.h"

calculatorOperation::calculatorOperation() {
	operations=NULL;
	required_parameters=0;
}

calculatorOperation::~calculatorOperation() {
	// TODO Auto-generated destructor stub
}

bool calculatorOperation::supportOperation(string op_string) {
	int i=0;
	while(i<n_operations){
		if(strcmp(op_string.c_str(),operations[i].c_str())==0) return true;
		i++;
	}
	return false;
}


