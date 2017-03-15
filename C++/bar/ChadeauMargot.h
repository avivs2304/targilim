
#ifndef CHADEAUMARGOT_H_
#define CHADEAUMARGOT_H_
#include "Wine.h"

/*
 * 		Inherits from Wine.
 */

class ChadeauMargot : public Wine {
public:
	ChadeauMargot(const int year_arg);
	virtual ~ChadeauMargot();
};

#endif /* CHADEAUMARGOT_H_ */
