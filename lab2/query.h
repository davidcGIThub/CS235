#ifndef query_H
#define query_H

#include <iostream>
#include <vector>
#include "predicate.h" 

class query
{

	public:
		
		query();
		void print();
	
	private:
		predicate myPredicate;
};

#endif
