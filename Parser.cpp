#include "Parser.h"
#include <iostream>


Parser::Parser(vector<token*> tok) : all_tokens(tok), current_token(tok.begin())
{
	if (program())
	{
		std::cout << "parsing successfull" << endl;
	}
	else
	{
		std::cout << "Syntax Error" << endl;
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
	//<func1>->semicolon
	//<func1>->left_brace <data decls> <statements> right_brace
	if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare(";"))
	{
		current_token++;
		return true;
	}
	else if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("{"))
	{
		if (data_decl())
		{
			if (statements())
			{
				if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("}"))
				{
					return true;
				}
			}
		}
	}
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
		if (parameter_list())
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
	//<parameter list> -> empty
	//<parameter list> -> void
	//<parameter list> -> <nonempty list>
	if ((*current_token)->token_type == KEYWORD && !(*current_token)->token_value.compare("void"))
	{
		current_token++;
		return true;
	}
	else if (nonempty_list())
	{
		return true;
	}
	return false;
}

bool Parser::nonempty_list()
{
	//<nonempty list> -> <type name> ID <extended nonempty>
	if (type_name())
	{
		if ((*current_token)->token_type == IDENTIFIER)
		{
			current_token++;
			if (extended_nonempty_list())
			{
				return true;
			}
		}
	}
	return false;
}

bool Parser::extended_nonempty_list()
{
	//<extended nonempty> -> comma <type name> ID <extended nonempty>
	//<extended nonempty>->empty

	if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare(","))
	{
		current_token++;
		if (type_name())
		{
			if ((*current_token)->token_type == IDENTIFIER)
			{
				if (extended_nonempty_list())
					return true;
				else
					return false;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	return isepsilon();
}


bool Parser::id_list()
{
	if (id())
	{
		if (extended_id_list())
		{			
			return true;
		}
	}
	return false;
}

bool Parser::extended_id_list()
{
	//<extended id list>->comma <id> <extended id list>
	//<extended id list>->empty	
	if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare(","))
	{
		current_token++;
		if (id())
		{
			if (extended_id_list())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return isepsilon();
}

bool Parser::id()
{
	if ((*current_token)->token_type == IDENTIFIER)
	{
		current_token++;
		//<id> -> ID <id1>
		if(id1())
			return true;
	}
	return false;
}

bool Parser::id1()
{
	//<id1>->empty
	//<id1>->left_bracket <expression> right_bracket
	if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("["))
	{
		current_token++;
		if (expression())
		{
			if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("]"))
			{
				current_token++;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return isepsilon();
	}
	
}

bool Parser::block_statements()
{
	//<block statements> -> left_brace <statements> right_brace
	if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("{"))
	{
		current_token++;
		if (statements())
		{
			if ((*current_token)->token_type == SPL_CHAR && !(*current_token)->token_value.compare("}"))
			{
				current_token++;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	return false;
}

bool Parser::statements()
{
	//<statements> -> empty
	//<statements> -> <statement> <statements>
	if (statement())
	{
		if (statements())
		{
			return true;
		}
		else
		{
			return false();
		}
	}
	else
	{
		//what if something was wrong in statement
		//check
		return true;
	}
	//return false;
}

bool Parser::statement()
{
	/*
	<statement> -> <assignment>
	<statement> -> <func call>
	<statement> -> <if statement>
	<statement> -> <while statement>
	<statement> -> <return statement>
	<statement> -> <break statement>
	<statement> -> <continue statement>
	<statement> -> read left_parenthesis ID right_parenthesis semicolon
	<statement> -> write left_parenthesis <expression> right_parenthesis semicolon
	<statement> -> print left_parenthesis STRING right_parenthesis semicolon
	*/
	if (assignment())
	{
		return true;
	}
	else if (func_call())
	{
		return true;
	}
	else if (if_statement())
	{
		return true;
	}
	else if (while_statement())
	{
		return true;
	}
	else if (return_statement())
	{
		return true;
	}
	else if (break_statement())
	{
		return true;
	}
	else if (continue_statement())
	{
		return true;
	}
	else if ((*current_token)->token_type == KEYWORD && !((*current_token)->token_value.compare("read")))
	{
		current_token++;
		if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare("(")))
		{
			current_token++;
			if ((*current_token)->token_type == IDENTIFIER)
			{
				current_token++;
				if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(")")))
				{
					current_token++;
					if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(";")))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((*current_token)->token_type == KEYWORD && !((*current_token)->token_value.compare("write")))
	{
		current_token++;
		if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare("(")))
		{
			current_token++;
			if (expression())
			{
				if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(")")))
				{
					current_token++;
					if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(";")))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((*current_token)->token_type == KEYWORD && !((*current_token)->token_value.compare("print")))
	{
		current_token++;
		if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare("(")))
		{
			current_token++;
			if ((*current_token)->token_type == CONST)//spl check for string const
			{
				current_token++;
				if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(")")))
				{
					current_token++;
					if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(";")))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Parser::assignment()
{
	//<assignment> -> <id> equal_sign <expression> semicolon
	if (id())
	{
		if ((*current_token)->token_type == OPERATOR && ((*current_token)->token_value.compare("=")))
		{
			current_token++;
			if (expression())
			{
				if ((*current_token)->token_type == SPL_CHAR && ((*current_token)->token_value.compare(";")))
				{
					current_token++;
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Parser::func_call()
{
	//<func call> -> ID left_parenthesis <expr list> right_parenthesis semicolon
	if ((*current_token)->token_type == IDENTIFIER)
	{
		current_token++;
		if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare("(")))
		{
			current_token++;
			if (expr_list())
			{
				current_token++;
				if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(")")))
				{
					current_token++;
					if ((*current_token)->token_type == SPL_CHAR && !((*current_token)->token_value.compare(";")))
					{
						current_token++;
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
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

