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
	string temp = " ";
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
			
		if(temp != " " && myTokens[myPos++] != temp)
		{
			return false;
		}

		if (wut == false)
		{
			return false;
		}
		
		temp = " ";
		state++;
	}
	return true;

}

//scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
bool datalogProgram::scheme_()
{
	if(myTokens[myPos] != "ID")
	{
		myPos++;
		return false;
	}
	temp_scheme.myHeadID = myTokens[myPos++].word // add ID to scheme instance
	
	if(myTokens[myPos++] != "LEFT_PAREN")
		return false;
		
	if(myTokens[myPos] != "ID")
	{
		myPos++;
		return false;
	}
	temp_vec.push_back(myTokens[myPos++].word); //add ID to temp_vec
	
	if(!id_List())
		return false;
	
	if(myTokens[myPos++] != "LEFT_PAREN")
		return false;
		
	temp_scheme.myIDs = temp_vec; //add IDs in temp_vec to scheme instance
	mySchemes.push_back(temp_scheme); // add scheme to mySchemes
	
	temp_scheme.myHeadId = ""; // clear the temp_scheme
	temp_scheme.myIDs.clear();
	
	temp_vec.clear(); //clear the temp_vec
		
	return true;
}
		

//schemeList	->	scheme schemeList | lambda
bool datalogProgram::scheme_List()
{
	if(myTokens[myPos] == "ID")
	{
		if(!scheme_())
			return false;
		if(!scheme_List())
			return false;
	}
	
	return true;
	
}

//idList  	->	COMMA ID idList | lambda
bool datalogProgram::id_List_()
{
	if(myTokens[myPos] == "COMMA")
	{
		myPos++;
		if(myTokens[myPos] != "ID")
		{
			myPos++;
			return false;
		}
		temp_vec.push_back(myTokens[myPos++].word);
		
		if(!id_List())
			return false;
	}
	return true;
}

//fact   -> 	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
bool datalogProgram::fact_()
{
	if(myTokens[myPos] != "ID")
	{
		myPos++;
		return false;
	}
	temp_fact.myHeadID = myTokens[myPos++].word // add ID to fact instance
	
	if(myTokens[myPos++] != "LEFT_PAREN")
	{
		return false;
	}
	
	if(myTokens[myPos] != "STRING")
	{
		myPos++;
		return false;
	}
	temp_fact.myStrings.push_back(myTokens[myPos++].word);
	
	if(!string_List())
		return false;
	
	if(myTokens[myPos++] != "RIGHT_PAREN")
	{
		return false;
	}	
	
	if(myTokens[myPos++] != "PERIOD")
	{
		return false;
	}
	
	myFacts.push_back(temp_fact); //add fact to myFacts
	
	temp_fact.myStrings.clear(); // clear the temp_fact
	temp_fact.myHeadID = "";
	
	return true;
}
	

//factList	->	fact factList | lambda
bool datalogProgram::fact_List()
{
	if(myTokens[myPos] == "ID")
	{
		if(!fact_())
		{
			return false;
		}
		if(!fact_List())
		{
			return false;
		}
	}
	return true;
		

}

//rule   ->	headPredicate COLON_DASH predicate predicateList PERIOD
bool datalogProgram::rule_()
{
	if(!head_Predicate())
	{
		return false;
	}
	
	if(myTokens[myPos++] != "COLON_DASH")
	{
		return false
	}
	
	if(!predicate_())
	{
		return false
	}
	
	if(!predicate_List())
	{
		return false;
	}
	
	if(myTokens[myPos++] != "PERIOD")
	{
		return false
	}
	
	temp_rule.myPredicates = temp_pred_vec; //add predicates to instance of rule
	temp_pred_vec.clear();
	
	myRules.push_back(temp_rule); //add rule to myRules
	
	temp_rule.myHeadID = "";
	temp_rule.myIDs.clear();
	temp_rule.myPredicates.clear();
	
	return true;

}

//ruleList	->	rule ruleList | lambda
bool datalogProgram::rule_List()
{
	if(myTokens[myPos] == "ID")
	{
		if(!rule_())
		{
			return false;
		}
		if(!rule_List())
		{
			return false;
		}
	}
	return true;
}

//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
bool datalogProgram::head_Predicate()
{
	if(myTokens[myPos] != "ID")
	{
			myPos++;
			return false;
	}
	temp_rule.myHeadID = myTokens[myPos++].word);
	
	if(myTokens[myPos++] != "LEFT_PAREN")
	{
		return false;
	}
	
	if(myTokens[myPos] != "ID")
	{
			myPos++;
			return false;
	}
	temp_vec.push_back(myTokens[myPos++].word);
	
	if(!id_List())
	{
		return false;
	}
	
	if(myTokens[myPos++] != "RIGHT_PAREN")
	{
		return false;
	}
	temp_rule.myIDs = temp_vec;
	temp_vec.clear();
	
	return true;

}

//predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
bool datalogProgram::predicate_()
{
	if(myTokens[myPos] != "ID")
	{
			myPos++;
			return false;
	}
	temp_predicate.myHeadID = myTokens[myPos++].word);
	
	if(myTokens[myPos++] != "LEFT_PAREN")
	{
		return false;
	}
	
	if(!parameter_())
	{
		return false
	}
	
	if(!parameter_List())
	{
		return false
	}
	
	if(myTokens[myPos++] != "RIGHT_PAREN")
	{
		return false;
	}
	
	temp_pred_vec.push_back(temp_predicate);
	
	temp_predicate.myHeadID = "";
	temp_predicate.myParameters.clear();
	
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
	





//predicateList	->	COMMA predicate predicateList | lambda
bool datalogProgram::predicate_List()
{
	if(myTokens[myPos] == "COMMA")
	{
		myPos++;
		if(!predicate_())
		{
			return false;
		}
		if(!predicate_List())
		{
			return false;
		}
	}
	return true;

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
