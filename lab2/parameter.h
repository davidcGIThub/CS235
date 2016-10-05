#ifndef parameter_H
#define parameter_H

#include <iostream>
#include <vector>

class parameter
{

	public:
		
		parameter();
		virtual void print();
		
};

class parameter_string: public parameter
{
	public:
	
		paramter_string();
		void print();
	
	private:
		
		string myString;
		
};

class parameter_expression: public parameter
{
	public:
	
		parameter_expression();
		void print();
	
	private:
		
		string myOperator;
		vector<parameter> myParameters;
		
};
	
		
#endif
