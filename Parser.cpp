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
			if (current_token == all_tokens.end())
			{
				return true;
			}
		}
	}
	return false;
}

bool Parser::data_decl()
{
	if (type_name())
	{
		if (id_list())
		{
			if (current_token != all_tokens.end() && ((*current_token)->token_type == SPL_CHAR ) && !((*current_token)->token_value.compare(";")))
			{
				current_token++;
				data_decl();
			}
			else
			{
				current_token--;
				current_token--;
				return isepsilon();
			}

		}
		return false;
	}
	return isepsilon();
}

bool Parser::func_list()
{
	//<func list> -> <func> <func list>
	if (func())
	{
		if (func_list())
		{
			return true;
		}

	}
	return false;
}

bool Parser::func()
{
	if (func_decl())
	{
		if (func1())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Parser::func1()
{
	return false;
}

bool Parser::func_decl()
{
	//<func decl> -> <type name> ID left_parenthesis <parameter list> right_parenthesis
	if (type_name())
	{
		if ((*current_token)->token_type == IDENTIFIER)
		{
			current_token++;
		}
		else
		{
			return false;
		}
		if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("("))
		{
			current_token++;
		}
		else
		{
			return false;
		}
		if (parameter_list)
		{

		}
		else
		{
			return false;
		}
		if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare(")"))
		{
			current_token++;
			return true;
		}
		else
		{
			return false;
		}

	}
	return isepsilon();
}

bool Parser::type_name()
{
	if ((*current_token)->token_type == KEYWORD && (!(*current_token)->token_value.compare("int") || !(*current_token)->token_value.compare("binary") || !(*current_token)->token_value.compare("decimal") || !(*current_token)->token_value.compare("void")))
	{
		current_token++;
		return true;
	}
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
	if (id())
	{
		/*if (extended_id_list)
		{
			//<extended id list> -> comma <id> <extended id list>
		}*/
	}
	return false;
}

bool Parser::extended_id_list()
{
	return false;
}

bool Parser::id()
{
	if ((*current_token)->token_type == IDENTIFIER)
	{
		current_token++;
		//ID1
		return true;
	}
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

bool Parser::isepsilon()
{
	return true;
}

