#ifndef
#define

#include <iostream>
#include <vector>

class parser
{

	public:
		
		parser();
		
		parser(string text)
		{
			input_file(text);
		}
		
		void input_file(string text)
		{
			lexical_analyzer lex(text);
			lex.add_tokens();
			datalogProgram myDat(lex.get_tokens());
		}
		
		bool parse()
		{
			myDat.parse();
		}
			
		void print_output()
		{
			myDat.print_output();
		}
	
	private:
	
		datalogProgram myDat;
	
};
