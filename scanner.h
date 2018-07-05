/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scanner.h
 * Author: shruthi
 *
 * Created on July 2, 2018, 10:57 PM
 */

#ifndef SCANNER_H
#define SCANNER_H

#include <string>
using namespace std;
        

enum TOKENS_TYPE {IDENTIFIER=1, KEYWORD, SPL_CHAR, OPERATOR, CONST};

static string op_list[] = {"+", "-", "*", "/", "%", ">", "<", "=", "==", "!=", ">=", "<=", "&&", "||", "!" };
static string key_list[] = {"int", "float", "char", "double", "if", "else", "switch", "while", "do", "include", "return", "break"};

class token
{
public:
   

    void Tokenise(string s);
    int tokenise_word(string word);
    bool check_digit(string word);
    bool isoperator(string word);
    bool iskeyword(string word);
    bool identifier_check(string word);

};


#endif /* SCANNER_H */

