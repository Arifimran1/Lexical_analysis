#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED
#include <bits/stdc++.h>


using namespace std;
///digit or not
bool is_digits(const std::string &str);
///keyword or not
bool is_keyword(string str);
///symbol or not
int is_symbol(string str);
///operator or not
int is_operator(string str);
///show name
string names(int num, string val);

#endif // LEXICAL_H_INCLUDED
