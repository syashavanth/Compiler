/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "scanner.h"
#include <fstream>

void token::Tokenise(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    
    char c;
    string word;
    
    while(ifs.get(c))
    {
        if(c==' ' || c=='\n' || c=='\t')
        {
            int result = tokenise_word(word);
            cout<<"tokenize ";
            cout<<word;
            
            word = "";
            cout<<result<<endl;
        }
        else
        {
            word.push_back(c);
        }
    }
}

int token::tokenise_word(string word)
{
    if(iskeyword(word))
    {
        return KEYWORD;
    }
    else if(isalpha(word[0]) || word[0]=='_')
    {
        //check if identifier
        cout<<"IDEnt";
        if(identifier_check(word))
            return IDENTIFIER;
        else
            return -1;
    }
    else if(isoperator(word))
    {
        return OPERATOR;
    }
    else if(isdigit(word[0]))
    {
        if(check_digit(word))
            return CONST;
        else
            return -1;
    }
    else if(word[0]=='"' || word[0]=='\'')
    {
        //check for string constant
    }
    
}

bool token::identifier_check(string word)
{
    if(word.size()>32)
    {
        return false;
    }
    for(string::iterator c = word.begin()+1; c!=word.end(); c++)
    {
        if(!isalpha(*c) && !isdigit(*c) && *c!='_')
            return false;
    }
    return true;
    
}

bool token::check_digit(string word)
{
    bool d = false;
    
    for(string::iterator i = word.begin(); i<word.end(); i++)
    {
        if(!isdigit(*i))
        {
            if(*i=='.' && !d )
            {
                d = true;
            }
            else
            {
                return false;
            }
        }
    }
    
    return true;
}

bool token::isoperator(string word)
{
    for(int i = 0; i<15; i++ )
    {
        if(word.compare(op_list[i])==0)
            return true;
    }
    return false;
}

bool token::iskeyword(string word)
{
    for(int i = 0; i<12; i++ )
    {
        if(word.compare(key_list[i])==0)
        {
            cout<<key_list[i];
            return true;
    
        }
    }
    return false;
}