#include"Lexer.h"

class Parser
{
public:
	vector<token*> all_tokens;
	vector<token*>::iterator current_token;

	Parser(vector<token*>);
	virtual ~Parser();
	bool program();
	bool data_decl();
	bool func_list();
	bool func();
	bool func1();
	bool func_decl();
	
	//bool type_id();
	bool type_name();
	bool parameter_list();
	bool nonempty_list();
	bool extended_nonempty_list();
	
	bool id_list();
	bool extended_id_list();
	bool id();
	bool id1();

	bool block_statements();
	bool statements();
	bool statement();

	bool assignment();
	bool func_call();
	bool expr_list();
	bool nonempty_expr_list();
	bool ext_nonempty_expr_list();

	bool if_statement();

	bool condition_expr();
	bool condition_expr1();
	bool condition_op();
	bool Logical_AND();

	bool condition();
	bool comparison_op();
	bool while_statement();
	bool return_statement();
	bool return1();

	bool break_statement();
	bool continue_statement();
	bool expression();
	bool extended_expression();

	bool addop();
	bool term();
	bool extended_term();
	
	bool mulop();

	bool factor();
	bool factor1();

	bool isepsilon();


};
