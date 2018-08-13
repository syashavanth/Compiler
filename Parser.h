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

};
