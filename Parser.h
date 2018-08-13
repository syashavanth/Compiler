#include"Lexer.h"

class Parser
{
public:
	Parser(vector<token*>);
	virtual ~Parser();
	bool program(token&);
	bool data_decl(token&);
	bool func_list(token&);

};
