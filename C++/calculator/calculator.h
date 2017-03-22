
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

// Add a new operation include here
#include "Addition.h"
#include "Divide.h"
#include "Multiply.h"
#include "Power.h"
#include "Set.h"
#include "Sqrt.h"
#include "Subtraction.h"
#include "Sin.h"
#include "Cos.h"


string find_word(string str);
void PrintError();
vector<string> getParameters(string str);

#endif /* CALCULATOR_H_ */
