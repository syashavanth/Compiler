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

bool Parser::func()
{
	return false;
}

bool Parser::func1()
{
	return false;
}

bool Parser::func_decl()
{
	return false;
}

bool Parser::type_name()
{
	return false;
}

bool Parser::parameter_list()
{
	return false;
}

bool Parser::nonempty_list()
{
	return false;
}

bool Parser::extended_nonempty_list()
{
	return false;
}

bool Parser::id_list()
{
	return false;
}

bool Parser::extended_id_list()
{
	return false;
}

bool Parser::id()
{
	return false;
}

bool Parser::id1()
{
	return false;
}

bool Parser::block_statements()
{
	return false;
}

bool Parser::statements()
{
	return false;
}

bool Parser::statement()
{
	return false;
}

bool Parser::assignment()
{
	return false;
}

bool Parser::func_call()
{
	return false;
}

bool Parser::expr_list()
{
	return false;
}

bool Parser::nonempty_expr_list()
{
	return false;
}

bool Parser::ext_nonempty_expr_list()
{
	return false;
}

bool Parser::if_statement()
{
	return false;
}

bool Parser::condition_expr()
{
	return false;
}

bool Parser::condition_expr1()
{
	return false;
}

bool Parser::condition_op()
{
	return false;
}

bool Parser::Logical_AND()
{
	return false;
}

bool Parser::condition()
{
	return false;
}

bool Parser::comparison_op()
{
	return false;
}

bool Parser::while_statement()
{
	return false;
}

bool Parser::return_statement()
{
	return false;
}

bool Parser::return1()
{
	return false;
}

bool Parser::break_statement()
{
	return false;
}

bool Parser::continue_statement()
{
	return false;
}

bool Parser::expression()
{
	return false;
}

bool Parser::extended_expression()
{
	return false;
}

bool Parser::addop()
{
	return false;
}

bool Parser::term()
{
	return false;
}

bool Parser::extended_term()
{
	return false;
}

bool Parser::mulop()
{
	return false;
}

bool Parser::factor()
{
	return false;
}

bool Parser::factor1()
{
	return false;
}

