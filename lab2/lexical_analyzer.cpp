//this is a modified version for lab 2
#include "lexical_analyzer.h"
#include <fstream>
#include <string>
#include "comment_cases.txt"
#include "string_cases.txt"
#include "id_cases.txt"
#include "colon_dash_cases.txt"


using namespace std;

lexical_analyzer::lexical_analyzer()
{
	myRow = 0;
	myCol = 0;
	r_end = false;
	
}

lexical_analyzer::lexical_analyzer(string text)
{
	myRow = 0;
	myCol = 0;
	r_end = false;
	input_file(text);
}

void lexical_analyzer::clear_list()
{
	myRow = 0;
	myCol = 0;
	r_end = false;
	for(unsigned int i = 0; i < myFile_Matrix.size(); i++)
	{
		myFile_Matrix[i].clear();
	}
	myFile_Matrix.clear();
	myToken_vec.clear();
}

void lexical_analyzer::input_file(string text)
{
	clear_list();
	ifstream file;
	file.open(text);
	char c;
	vector<char> temp_vec;
	
	while(file.get(c))
	{
		if(!isspace(c))
		{
			temp_vec.push_back(c);
		}
		else
		{
			if(c == '\n')
			{
				//test
				//cout << "its a new line" << endl;
				temp_vec.push_back(c);
				//test
				//cout << temp_vec.size() << endl;
				myFile_Matrix.push_back(temp_vec);
				temp_vec.clear();
			}
			else
			{
				if(c == '\r') continue;
				temp_vec.push_back(c);
			}
				
		}
	}	
		
}

void lexical_analyzer::add_tokens()
{
	char character;
	if(myFile_Matrix.size() == 0) r_end = true;
	while (r_end == false)
	{
		character = myFile_Matrix[myRow][myCol];
		//test
		//cout << "the character is " << character << endl;
		switch(character)
		{
			case ',' :
				//test
			//	cout << "COMMA" << endl;
				comma();
				break;
				
			case '.' :
				//test
				//cout << "Period" << endl;
				period();
				break;
				
			case '?' :
				//test
				//cout << "q_mark" << endl;
				q_mark();
				break;
				
			case '(' :
				//test
				//cout << "leftparen" << endl;
				left_paren();
				break;
				
			case ')' :
				//test
				//cout << "rightparen" << endl;
				right_paren();
				break;
				
			case ':' :
				//test
				//cout << "colondash" << endl;
				colon_dash();
				break;
				
			case '*' :
				//test
				//cout << "mulitply" << endl;
				multiply();
				break;
				
			case '+' :
				//test
				//cout << "add" << endl;
				add();
				break;
				
			case 'S' : 
				//test
				//cout << "schems" << endl;
				word_check("Schemes");
				break;
				
			case 'F' :
				//test
				//cout << "facts" << endl;
				word_check("Facts");

				break;
				
			case 'R' :
				//test
				//cout << "rules" << endl;
				word_check("Rules");
				break;
				
			case 'Q' :
				//test
				//cout << "Query" << endl;
				word_check("Queries");
				break;
	
			case '\'':
				//test
				//cout << "apostrophe" << endl;
				string_func();
				break;
				
			case '#' :
				//test
				//cout << "pound" << endl;
				comment();
				break;
				
			default :
				if(isalpha(myFile_Matrix[myRow][myCol]))
				{
					//test
					//cout << "id" << endl;
					id();
				}
				else if(isspace(myFile_Matrix[myRow][myCol]))
				{
					white_space();
				}
				else
				{
					//test
					//cout << "undefined" << endl;
					undefined();
				}
		}
	}	
	end_of_file();	
	
}

void lexical_analyzer::comma()
{
	if (myFile_Matrix[myRow][myCol] == ',')
	{
		Token tok;
		tok.word = ",";
		tok.line = myRow;
		tok.type = "COMMA";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
}

void lexical_analyzer::period()
{
	if (myFile_Matrix[myRow][myCol] == '.')
	{
		Token tok;
		tok.word = ".";
		tok.line = myRow;
		tok.type = "PERIOD";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
}

void lexical_analyzer::q_mark()
{
	if (myFile_Matrix[myRow][myCol] == '?')
	{
		Token tok;
		tok.word = "?";
		tok.line = myRow;
		tok.type = "Q_MARK";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
}

void lexical_analyzer::left_paren()
{
	if (myFile_Matrix[myRow][myCol] == '(')
	{
		Token tok;
		tok.word = "(";
		tok.line = myRow;
		tok.type = "LEFT_PAREN";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
}

void lexical_analyzer::right_paren()
{
	if (myFile_Matrix[myRow][myCol] == ')')
	{
		Token tok;
		tok.word = ")";
		tok.line = myRow;
		tok.type = "RIGHT_PAREN";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
	
}

void lexical_analyzer::colon_dash()
{
	char character;
	int row = myRow;
	int col = myCol;
	bool loop = true;
	string temp;
	states state;
	state = one;
	
	while(loop)
	{
		character = myFile_Matrix[row][col];
		//test
		//cout << "reached loop" << endl;
		
		switch(state)
		{
			case one:
				colon_dash_case_one(temp,character,row,col,loop,state);
				break;
				
			case two:
				colon_dash_case_two(temp,character,row,col,loop,state);
				break;
			case three:
				break;
			case four:
				break;
			case five:
				break;
			case six:
				break;
			case seven:
				break;
			case eight:
				break;
		}
	}
	
}

void lexical_analyzer::multiply()
{
	if (myFile_Matrix[myRow][myCol] == '*')
	{
		Token tok;
		tok.word = "*";
		tok.line = myRow;
		tok.type = "MULTIPLY";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
	
}

void lexical_analyzer::add()
{
	if (myFile_Matrix[myRow][myCol] == '+')
	{
		Token tok;
		tok.word = "+";
		tok.line = myRow;
		tok.type = "ADD";
		myToken_vec.push_back(tok);
		if(!increment(myRow,myCol)) r_end = true;
	}
	
}
			
void lexical_analyzer::word_check(string word, int& myTemp_row, int& myTemp_col, string& tempWord)
{
	//test
	//cout << myFile_Matrix[myTemp_row][myTemp_col] << " ?==? " << word[0] << endl;
	//test
	//cout << "myTemp_row = " << myTemp_row << " myTemp_col = " << myTemp_col << endl;
	if (myFile_Matrix[myTemp_row][myTemp_col] == word[0]) //if char is next char in sequence
	{
		//test
		//cout << "is char equal" << endl;
		tempWord.push_back(myFile_Matrix[myTemp_row][myTemp_col]);
		if (word.size() == 1)	//if last char
		{
			//test
			//cout << "last char?" << endl;
							
		}
		else
		{
			if(!increment(myTemp_row,myTemp_col)) cout << "cant be incremented?" << endl;
			else word_check(word.substr(1,word.size()),myTemp_row,myTemp_col,tempWord);
		}
	}
	else
	{
						
	}
}
				
				
void lexical_analyzer::word_check(string word)
{
	int myTemp_row = myRow;
	int myTemp_col = myCol;
	string tempWord;
	//test
	//cout << "This is the first call " << myFile_Matrix[myTemp_row][myTemp_col] << " ?==? " << word[0] << endl;
	//test
	//cout << "myTemp_row = " << myTemp_row << " myTemp_col = " << myTemp_col << endl;
	word_check(word, myTemp_row, myTemp_col, tempWord);
	//test
	//cout << "does it get past the func?" << endl;
	if(tempWord == word)
	{
		//test
		//cout << "OKAY LETS SEE IF IT EVEN GETS THIS FAR" << endl;
		Token tok;
		tok.word = tempWord;
		tok.line = myRow;
		for(unsigned int i = 0; i < tempWord.size(); i ++)
		{
			tempWord[i] = toupper(tempWord[i]);
		}
		tok.type = tempWord;
						
		if(increment(myTemp_row,myTemp_col))
		{
			if(isalpha(myFile_Matrix[myTemp_row][myTemp_col]) || isdigit(myFile_Matrix[myTemp_row][myTemp_col]))
			{
				id();
			}
			else
			{
				myToken_vec.push_back(tok);
				myRow = myTemp_row;
				myCol = myTemp_col;
			}
		}
		else
		{
			myToken_vec.push_back(tok);
			myRow = myTemp_row;
			myCol = myTemp_col;
			r_end = true;
		}
	}
	else
	{
		id();
	}
}
						

void lexical_analyzer::id()
{
	string temp;
	int row = myRow;
	int col = myCol;
	bool loop = true;
	states state;
	state = one;
	char character;
	
	while(loop == true)
	{
		character = myFile_Matrix[row][col];
		
		switch(state)
		{
			case one:
				id_case_one(temp,character,row,col,loop,state);
				break;
		
			case two:
				id_case_two(temp,character,row,col,loop,state);	
				break;
			case three:
				break;
			case four:
				break;
			case five:
				break;
			case six:
				break;
			case seven:
				break;
			case eight:
				break;
		}
     }
 }

void lexical_analyzer::string_func()
{
	string temp;
	states state;
	char character;
	int row = myRow;
	int col = myCol;
	bool loop = true;
	state = one;
	
	while(loop)
	{
		//test
		//cout << "string loop" << endl;
		character = myFile_Matrix[row][col];
		switch(state)
		{
			case one:
				string_case_one(temp,character,row,col,loop,state);
				break;
			
			case two:
				string_case_two(temp,character,row,col,loop,state);
				break;
				
			case three:
				string_case_three(temp,character,row,col,loop,state);
				break;
			case four:
				break;
			case five:
				break;
			case six:
				break;
			case seven:
				break;
			case eight:
				break;
		}
	}
}
						

void lexical_analyzer::comment()
{
	string temp;
	states state;
	char character;
	int row = myRow;
	int col = myCol;
	bool loop = true;
	state = one;
	
	//test
	//cout << "comment has been called" << endl;
	
	while(loop)
	{
		//test
		//cout << "comments loop" << endl;
	character = myFile_Matrix[row][col];
	//test
	//cout << "character =" << character << " row" << row << "col" << col << endl;
	switch(state)
	{
		case one:
			//test
			//cout << " case one " << endl;
			comment_case_one(temp,character,row,col,loop,state);
			break;

		case two:
			//test
			//cout << " case two " << endl;
			comment_case_two(temp,character,row,col,loop,state);
			break;

		case three:
			//test
			//cout << " case three " << endl;
			comment_case_three(temp,character,row,col,loop,state);
			break;
				
		case four:
			//test
			//cout << " case four " << endl;
			comment_case_four(temp,character,row,col,loop,state);
			break;
		
		case five:
			//test
			//cout << " case five " << endl;
			comment_case_five(temp,character,row,col,loop,state);
			break;
		case six:
			break;
		case seven:
			break;
		case eight:
			break;
							
	}
	//test
	//cout << "escaped the loop" << endl;

	}
}

void lexical_analyzer::undefined()
{
	string temp;
	char character = myFile_Matrix[myRow][myCol];
	temp.push_back(character);
	Token tok;
	tok.word = temp;
	tok.line = myRow;
	tok.type = "UNDEFINED";
	
	if(character != '\n') myToken_vec.push_back(tok);
	
	if(!increment(myRow,myCol))
	{
		r_end = true;
	}	
}

void lexical_analyzer::end_of_file()
{
	if(r_end)
	{
		Token tok;
		tok.word = "";
		tok.line = myFile_Matrix.size();
		//test
		//cout << tok.line << endl;
		//if (myFile_Matrix.size() == 0) tok.line == 1;
		//test
		//cout << tok.line << endl;
		//test
		//cout << "end of file row = " << tok.line << endl;
		if(myFile_Matrix.size() != 0)
		{
			if(myFile_Matrix[myFile_Matrix.size()-1][myFile_Matrix[myFile_Matrix.size()-1].size()-1] != '\n') tok.line--;
		}
		tok.type = "EOF";
		myToken_vec.push_back(tok);

		
	}
	
}

bool lexical_analyzer::increment(int& row, int& col)
{
	unsigned int temp_col = col;
	unsigned int temp_row = row;
	if(temp_col == myFile_Matrix[row].size()-1)
	{
		if(temp_row == myFile_Matrix.size()-1)
		{
			return false;
		}
		else
		{
			row++;
			col = 0;
			return true;
		}
	}
	else
	{
		col++;
		return true;
	}
}


void lexical_analyzer::print_tokens()
{
	int total = myToken_vec.size();
	for(int i = 0; i < total; i++)
	{
		Token tok = myToken_vec[i];
		//test
		//cout << "token number " << i << endl;
		cout << "(" << tok.type << "," << "\"" << tok.word << "\"" << "," << (tok.line + 1) << ")" << endl;
	}
	
	cout << "Total Tokens = " << total << endl;
}

vector<Token> lexical_analyzer::get_tokens()
{
	vector<Token> temp;
	temp = myToken_vec;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if (temp[i].type == "COMMENT")
			temp.erase(temp.begin()+i);
	}
	return temp;
}

void lexical_analyzer::white_space()
{
	if(isspace(myFile_Matrix[myRow][myCol]))
	{
		if(increment(myRow,myCol))
		{
		
		}
		else
		{
			r_end = true;
		}
	}
}


	//This is only for testing
	/*
	for(int i = 0; i < myFile_Matrix.size(); i++)
	{
		for(int j = 0; j < myFile_Matrix[i].size(); j++)
		{
			cout << myFile_Matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "rows = " << myFile_Matrix.size() << " cols = " << myFile_Matrix[1].size() << endl;
	*/	

