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
		
		string myHeadID;
		vector<string> myIDs;
		vector<predicate> myPredicates;
	
};

#endif
