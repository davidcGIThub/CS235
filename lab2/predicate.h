#ifndef predicate_H
#define predicate_H

#include <iostream>
#include <vector>
#include "parameter.h"

class predicate
{

	public:
		
		predicate();
		void print();
	
	private:
		
		string myHeadID;
		vector<parameter> myParameters;
	
};

#endif
