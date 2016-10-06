#ifndef Token_H
#define Token_H

#include <iostream>

struct Token
{
	std::string word;
	int line;
	std::string type;
	
	bool operator==(const std::string b)
	{
		return type == b;
	}

	bool operator!=(const std::string b)
	{
		return type != b;
	}
};

#endif
