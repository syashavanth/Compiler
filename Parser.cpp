#include "Parser.h"
#include <iostream>


Parser::Parser(vector<token*> tok)
{
	if (program(*tok[0]))
	{
		std::cout << "parsing successfull" << endl;
	}
}


Parser::~Parser()
{
}

bool Parser::program(token& tok)
{
	if (data_decl(tok))
	{
		if (func_list(tok))
		{
			return true;
		}
	}
	return false;
}

bool Parser::data_decl(token& tok)
{
	return true;
}

bool Parser::func_list(token& tok)
{
	return true;
}
