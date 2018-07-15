//#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <string>
using namespace std;


enum TOKENS_TYPE { IDENTIFIER = 1, KEYWORD, SPL_CHAR, OPERATOR, CONST };

static string op_list[] = { "+", "-", "*", "/", "%", ">", "<", "=", "==", "!=", ">=", "<=", "&&", "||", "!" };
static string key_list[] = { "int", "float", "char", "double", "if", "else", "switch", "while", "do", "include", "return", "break" };

class token
{
public:

	int token_type;
	string token_value;
};

void Tokenise(string s);

int check_numeric_const(ifstream&);
int isoperator(ifstream&);
bool iskeyword(string word);
int identifier_check(ifstream&);
bool isdelimeter(char c);

int check_string_const(ifstream&);

bool isSpecial_Sybmol(char c);

class Lexer
{
public:
	Lexer();
	~Lexer();
};

#endif /* SCANNER_H */
