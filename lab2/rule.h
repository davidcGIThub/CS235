#ifndef rule_H
#define rule_H

#include <iostream>
#include <vector>
#include "predicate.h"

class rule
{

	public:
		
		rule();
		void print();
	
	private:
		
		vector<string> myHeadPredicates;
		vector<predicate> myPredicates;
	
};

#endif
