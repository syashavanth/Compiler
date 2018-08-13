#include "Parser.h"
#include <iostream>


Parser::Parser(vector<token*> tok) : all_tokens(tok), current_token(tok.begin())
{
	if (program())
	{
		std::cout << "parsing successfull" << endl;
	}
}


Parser::~Parser()
{
}

bool Parser::program()
{
	if (data_decl())
	{
		if (func_list())
		{
			return true;
		}
	}
	return false;
}

bool Parser::data_decl()
{
	return true;
}

bool Parser::func_list()
{
	return true;
}
