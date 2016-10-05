//this is a modified version for lab 2
#ifndef lexical_analyzer_H
#define lexical_analyzer_H

#include <iostream>
#include <vector>
#include "Token.h"

using namespace std;

class lexical_analyzer
{

enum states{one,two,three,four,five,six,seven,eight};

public:

	lexical_analyzer();
	lexical_analyzer(string text);
	void input_file(string text);  // takes text file and creates a matrix of its characters
	void add_tokens(); //parses through matrix, and adds tokens to vector
	void print_tokens(); //prints out to output file
	void clear_list();
	vector<Token> get_tokens();
	
private:

	vector<vector<char>> myFile_Matrix; // Matrix of char's from input file
	vector<Token> myToken_vec; // vector of all found tokens
	int myRow; //current row looking at in myFile_Matrix
	int myCol; //current col looking at in myFile_Matrix
	bool r_end;
	
	   // The following function checks to see if following chars equal these tokens
	   // if fits, raise flag to stop check from that pos, also add it to myToken_Vec,
	   
	void comma(); 
	void period();
	void q_mark();
	void left_paren();
	void right_paren();
	void colon();
	void colon_dash();
	void multiply();
	void add();
	void word_check(string word);
	void word_check(string word,int& myTemp_row, int& myTemp_col, string& tempWord);
	bool facts();
	bool rules();
	bool queries();
	void id();
	void string_func();
	void comment();
	void undefined();
	void end_of_file();
	void white_space();
	bool increment(int& row, int& col);
	
	void comment_case_one(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void comment_case_two(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void comment_case_three(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void comment_case_four(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void comment_case_five(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	
	void string_case_one(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void string_case_two(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void string_case_three(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	
	void id_case_one(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void id_case_two(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	
	void colon_dash_case_one(string& temp,char& character, int& row, int& col, bool& loop, states& state);
	void colon_dash_case_two(string& temp,char& character, int& row, int& col, bool& loop, states& state);


};
	
	
	
	
#endif
