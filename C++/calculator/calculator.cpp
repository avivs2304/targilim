
#include "calculator.h"

const int num_of_operations = 9;

/*
 * 		Function returns the first word in the string
 */

string find_word(string str){
	string newStr = "";
	int i = 0;
	while(str[i]!=' ' && str[i] != '\n' && str[i]!='\0'){
		newStr+=str[i];
		++i;
	}
	return newStr;
}

/*
 * 		Function returns a vector containing parameters extracted from a string
 */

vector<string> getParameters(string str){
	vector<string> params;
	params.reserve(10);
	string newParam = find_word(str);
	while(newParam!=""){
		str.erase(0,newParam.length());
		params.push_back(newParam);
		newParam = find_word(str);
	}
	return params;
}

/*
 *		Function prints an error if an unknown operation is parsed.
 */

void PrintError(){
	cout << "\t operation or syntax not supported \n\t be careful of spaces before operation"
			" and make sure there are spaces between parameters\n" << endl;
}

int main(int argc, char * argv[]){
	double currVal = 0.0;
	string str = "";
	// Supported Operations:
	calculatorOperation* operations[num_of_operations] = {new Addition(), new Divide(), new Multiply(),
					new Power(), new Set(), new Sqrt(), new Subtraction(), new Cos(), new Sin()};
	string op;
	vector<string> params;
	int i;
	bool found_op;
	cout << "Welcome to the module calculator!!" << endl;

	//For each operations until user types "end"
	while(strcmp(str.c_str(), "end")!=0){
		found_op=false;
		cout << "-> ";
		getline(cin, str);
		op = find_word(str);
		for(i = 0; i<num_of_operations; i++)
		{

			//Check if operation is supported
			if(operations[i]->supportOperation(op)){
				str.erase(0,op.length()+1);
				params = getParameters(str);

				//Check if parameters included reach the MINIMUM requirements
				if(operations[i]->requiredParameters() >= (int)params.size()){
					currVal = operations[i]->calcResult(currVal,params);
					found_op=true;
					printf(" Current value is: %f\n", currVal);
				}
			}
		}

		//if an unknown operation is parsed
		if(!found_op && (strcmp(str.c_str(), "end")!=0)) PrintError();
	}
	return 0;


}



