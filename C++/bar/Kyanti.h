#ifndef KYANTI_H_
#define KYANTI_H_
#include "Wine.h"

/*
 * 		Inherits from Wine.
 */

class Kyanti : public Wine{
public:
	Kyanti(const int year_arg);
	virtual ~Kyanti();
};

#endif /* KYANTI_H_ */
