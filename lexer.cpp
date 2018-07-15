#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <vector>

vector<token*> t;

void Tokenise(string filename)
{
	ifstream ifs;
	ifs.open(filename);
	int result;

	char c;
	string word;

	//cout << "Tokenise " << endl;
	while (ifs.get(c))
	{
		if (isdelimeter(c))
		{	
			cout << c;
			continue;
		}
		else if (isSpecial_Sybmol(c))
		{
			result = SPL_CHAR;
		}
		else if (isalpha(c) || c == '_')
		{
			ifs.unget();
			result = identifier_check(ifs);
		}
		else if(isdigit(c))
		{
			ifs.unget();
			result = check_numeric_const(ifs);
		}
		else if (c == '\"')
		{
			result = check_string_const(ifs);
		}
		else if (c == '\'')
		{
			ifs.get(c);
			ifs.get(c);
			if (c == '\'')
				result = CONST;
			else
				result = -1;
		}
		else
		{
			//cout << c;
			ifs.unget();
			result = isoperator(ifs);
		}
		cout << result;
	}
}

int identifier_check(ifstream& ifs)
{
	char c;
	string word = "";

	while(ifs.get(c))
	{
		if (isalnum(c) || c == '_')
		{
			word.push_back(c);
			//continue;
		}
		else
		{
			ifs.unget();
			break;
		}
	}
	token *temp = new token();
	//cout << word;
	if (iskeyword(word))
	{
		temp->token_type = KEYWORD;
		temp->token_value = word;
		t.push_back(temp);
		return KEYWORD;
	}
	else
	{
		temp->token_type = IDENTIFIER;
		temp->token_value = word;
		t.push_back(temp);
		return IDENTIFIER;
	}
}

int check_numeric_const(ifstream& ifs)
{
	bool d = false;
	char c;
	string word = "";
	token *temp = new token();
	
	while (ifs.get(c))
	{
		if (isdigit(c))
		{
			word.push_back(c);
			continue;
		}
		else if (c == '.' && !d)
		{
			d = true;
		}
		else
		{
			ifs.unget();
			temp->token_type = CONST;
			temp->token_value = word;
			t.push_back(temp);

			return CONST;
		}
	}
	return -1;
}

int check_string_const(ifstream& ifs)
{
	string word = "";
	char c;
	token *temp = new token();
	while(ifs.get(c))
	{
		if (c == '\"')
		{
			//ifs.unget();
			temp->token_type = CONST;
			temp->token_value = word;
			t.push_back(temp);

			return CONST;
		}
		word.push_back(c);
	}

	return -1;

	
}

int isoperator(ifstream& ifs)
{
	string word = "";
	char c;
	token *temp = new token();

	while (ifs.get(c))
	{
		if (isdelimeter(c) || isalnum(c) || c == '_' || c== '\"' || c=='\'')
		{
			ifs.unget();
			break;
		}
		word.push_back(c);
	}
	
	
	
	for (unsigned int i = 0; i < 17; i++)
	{
		//cout << op_list->size();
		//cout << word << endl;
		//cout << op_list[i] << endl;

		if (word.compare(op_list[i])==0)
		{
			//cout << "equal";
			temp->token_type = OPERATOR;
			temp->token_value = word;
			t.push_back(temp);

			return OPERATOR;
		}
	}
	return -1;
}

bool iskeyword(string word)
{
	for (int i = 0; i<12; i++)
	{
		if (word.compare(key_list[i]) == 0)
		{
			//cout << key_list[i];
			return true;

		}
	}
	return false;
}

bool isdelimeter(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
	{
		return true;
	}

	return false;
}

bool isSpecial_Sybmol(char c)
{
	if (c == '(' || c == ')' || c == ',' || c == ';' || c == '{' || c == '}' || c == '[' || c == ']')
	{
		token *temp = new token();

		temp->token_type = SPL_CHAR;
		temp->token_value = to_string(c);

		t.push_back(temp);
		return true;
	}
	return false;
}


Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}
