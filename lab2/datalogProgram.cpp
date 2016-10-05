#include "datalogProgram.h"

using namespace std;
		
datalogProgram::datalogProgram()
{

}
		
datalogProgram::datalogProgram(vector<Token> Token_vec)
{
	input_Tokens(Token_Vec);
}

void datalogProgram::input_Tokens(vector<Token> Token_vec)
{
	myTokens = Token_vec;
}
		
bool datalogProgram::parse()
{
	if (datalog_Progam())
	{
		cout << "Success!" << endl;
	}
	else
	{
		cout << "Failure!" << endl;
		Token tok = myTokens[myPos];
		cout << "\t" << "(" << tok.type << "," << "\"" << tok.word << "\"" << "," << (tok.line + 1) << ")" << endl;  
	}
}
		
void datalogProgram::print_output()  //assuming vector size is size of how many of each there are
{
	cout << "Schemes(" << mySchemes.size() << "):" << endl;
	for(unsigned int i = 0; i < mySchemes.size(); i++)
	{
		mySchemes[i].print();
	}
	cout << "Facts(" << myFacts.size() << "):" << endl;
	for(unsigned int i = 0; i < myFacts.size(); i++)
	{
		myFacts[i].print();
	}
	cout << "Rules(" << myRules.size() << "):" << endl;
	for(unsigned int i = 0; i < myRules.size(); i++)
	{
		myRules[i].print();
	}
	cout << "Queries(" << myQueries.size() << "):" << endl;
	for(unsigned int i = 0; i < myQueries.size(); i++)
	{
		myQueries[i].print();
	}
	cout << "Domain(" << myDomain.size() << "):" << endl;
	for(std::set<string>::iterator it=myDomain.begin(); it!=myset.end(); ++it)
	{
		cout << "\t" << *it << endl;
	}
}
		
//	datalogProgram	->	SCHEMES COLON scheme schemeList 
//				FACTS COLON factList
//		        RULES COLON ruleList
//		        QUERIES COLON query queryList

bool datalogProgram::datalogue_Program()
{
	int state = 1;
	string temp;
	bool wut = true;
	
	while(state < 15)
	{
		switch(state)
		{
			case 1:
				temp = "SCHEMES";
				break;
			case 2:
				temp = "COLON";
				break;
			case 3:
				wut = scheme_();
				break;
			case 4:
				wut = scheme_List();
				break;
			case 5:
				temp = "FACTS";
				break;
			case 6:
				temp = "COLON";
				break;
			case 7:
				wut = fact_List();
				break;
			case 8:
				temp = "RULES";
				break;
			case 9:
				temp = "COLON";
				break;
			case 10:
				wut = rule_List();
				break;
			case 11:
				temp = "QUERIES";
				break;
			case 12:
				temp = "COLON";
				break;
			case 13:
				wut = query_();
				break;
			case 14:
				wut = query_List();
				break;
		}
		state++;	
		if(temp != " " && myTokens[myPos++] != temp)
		{
			temp = " ";
			return false;
		}
		if (wut == false)
		{
			return false;
		}
	}
	return true;

}

//scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
bool datalogProgram::scheme_()
{
	if(myTokens[myPos] != "ID")
		return false;
	temp_scheme.myHeadID = myTokens[myPos++].word // add ID to scheme instance
	
	if(myTokens[myPos++] != "LEFT_PAREN")
		return false;
		
	if(myTokens[myPos] != "ID")
		return false;
	temp_vec.push_back(myTokens[myPos++].word); //add ID to temp_vec
	
	if(!id_List())
		return false;
	
	if(myTokens[myPos++] != "LEFT_PAREN")
		return false;
		
	temp_scheme.myIDs = temp_ID_vec; //add IDs in temp_vec to scheme instance
	temp_vec.clear(); //clear the temp_vec
		
	return true;
}
		
	
		/*
		int myPos;
		vector<Token> myTokens;
		
		vector<rule> myRules;
		vector<sceme> mySchemes;
		vector<fact> myFacts;
		vecotr<query> myQueries;
		set<string> myDomain;
		
		vector<string> temp_vec;
		vector<predicate> temp_pred;
		vector<paramater> temp_param;
		
		rule temp_rule;
		scheme temp_scheme;
		fact temp_fact;
		query temp_query;
		string temp_string;
	*/
	

//schemeList	->	scheme schemeList | lambda
bool datalogProgram::scheme_List()
{
	

}

//idList  	->	COMMA ID idList | lambda
bool datalogProgram::id_List_()
{
	if(myTokens[myPos] != "ID")
		return false;

}

//fact   -> 	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
bool datalogProgram::fact_()
{

}

//factList	->	fact factList | lambda
bool datalogProgram::fact_List()
{

}

//rule   ->	headPredicate COLON_DASH predicate predicateList PERIOD
bool datalogProgram::rule_()
{

}

//ruleList	->	rule ruleList | lambda
bool datalogProgram::rule_List()
{

}

//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
bool datalogProgram::head_Predicate()
{

}

//predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
bool datalogProgram::predicate_()
{

}

//predicateList	->	COMMA predicate predicateList | lambda
bool datalogProgram::predicate_List()
{

}

//parameter	->	STRING | ID | expression
bool datalogProgram::parameter_()
{

}


//parameterList	-> 	COMMA parameter parameterList | lambda
bool datalogProgram::parameter_List()
{

}

//expression	-> 	LEFT_PAREN parameter operator parameter RIGHT_PAREN
bool datalogProgram::expression_()
{

}

//operator	->	ADD | MULTIPLY
bool datalogProgram::operator_()
{

}

//query	 ->      predicate Q_MARK
bool datalogProgram::query_()
{

}

//queryList	->	query queryList | lambda
bool datalogProgram::query_List()
{

}

//stringList ->	COMMA STRING stringList | lambda 
bool datalogProgram::string_List()
{

}

		
add_domain()
{

}

		
	
};
