#include <cstdlib>
#include "lexer.h"
#include <iostream>
#include "Parser.h"
using namespace std;


int main(int argc, char** argv) {

	//cout << "HELLO";
	Lexer L;
	L.Tokenise("test_input.txt");
	vector<token*> list_of_toks = L.get_All_Tokens();
	Parser P(list_of_toks);

	getchar();
	return 0;
}
