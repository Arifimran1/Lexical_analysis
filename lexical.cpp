#include <iostream>
#include <bits/stdc++.h>
#include "lexical.h"


string keyword[32] = {"auto","break","case","char","const","continue","default",
                    "do","double","else","enum","extern","float","for","goto",
                    "if","int","long","register","return","short","signed",
                    "sizeof","static","struct","switch","typedef","union",
                    "unsigned","void","volatile","while"
                   };
string oper[27] = {"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=",
				"*=", "/=", "==", "!=", ">", "<", ">=", "<=", "&&", "||","!", "&",
				"|", "^", "~", "<<", ">>"};

string oper_name[27] = {"Addition", "Subtraction", "Multiplication", "Division", "Modulas", "Increment",
				"Decrement", "Assign\t", "Addition with assign", "Subtraction with assign", "Multiplication with assign",
				"Division with assign", "Equal", "NotEqual", "Greaterthan", "Lessthan", "Greaterthan or equal",
				"Lessthan or equal", "Logical and", "Logical or","Logical not", "Bitwise and", "Bitwise or",
				"Bitwise exclusive OR", "Bitwise complement", "Shift left", "Shift right"};

string symb[6] = { "(", ")", "{", "}", ";", "," };
string symb_name[6] = { "opening braces", "closing braces", "left curly braces", "right curly braces",
				"semicolon", "comma" };

string reserved[5] = {"main", "return", "printf", "scanf", "null" };

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}
bool is_keyword(string str)
{
    for(int i = 0; i < 32; i++)
    {
        if(str == keyword[i])
            return 1;
    }
    return 0;
}
int is_symbol(string str)
{
    for(int i = 0; i < 6; i++)
    {
        if(str == symb[i])
            return i;
    }
    return -1;
}
int is_operator(string str)
{
    for(int i = 0; i < 27; i++)
    {
        if(str == oper[i])
            return i;
    }
    return -1;
}
bool is_reserved(string str)
{
    for(int i = 0; i < 5; i++)
    {
        if(str == reserved[i])
            return 1;
    }
    return 0;
}

string names(int num, string val)
{
    if(val == "oper")
        return oper_name[num];
    else if(val == "symb")
        return symb_name[num];
}


