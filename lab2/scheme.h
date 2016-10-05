#ifndef scheme_H
#define scheme_H

#include <iostream>
#include <vector>

class rule
{

	public:
		
		scheme();
		void print();
	
	private:
		string myHeadID;
		vector<string> myIDs;
		
};

#endif
