#ifndef datalogProgram_H
#define datalogProgram_H

#include <iostream>
#include <vector>
#include <set>
#include "Token.h"

class datalogProgram
{

	public:
		
		datalogProgram();
		datalogProgram(vector<Token> Token_vec);
		void input_Tokens(vector<Token> Token_vec);
		bool parse();
		void print_output();
	
	private:
		
		int myPos;
		vector<Token> myTokens;
		
		vector<rule> myRules;
		vector<sceme> mySchemes;
		vector<fact> myFacts;
		vector<query> myQueries;
		set<string> myDomain;
		
		vector<string> temp_vec;
		vector<predicate> temp_pred_vec;
		vector<paramater> temp_param_vec;
		
		rule temp_rule;
		scheme temp_scheme;
		fact temp_fact;
		query temp_query;
		string temp_string;
		predicate temp_predicate;
		parameter temp_parameter;
		
		
		bool datalogue_Program();
		bool scheme_();
		bool scheme_List();
		bool id_List_();
		bool fact_();
		bool fact_List();
		bool rule_();
		bool rule_List();
		bool head_Predicate();
		bool predicate_();
		bool predicate_List();
		bool parameter_();
		bool parameter_List();
		bool expression_();
		bool operator_();
		bool query_();
		bool query_List();
		bool string_List();
		
		add_domain();
		
	
};

#endif
