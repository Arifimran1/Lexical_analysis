#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include "lexical.h"

using namespace std;

int main()
{   //token table array
    string tokensl[100]; //lexim
    string tokensn[100]; //token name
    string tokensa[100];//attribute_value

    //symbol table array
    string sys[100]; //symbol
    string syt[100]; //token
    string syd[100]; //data type
    string syp[100];//prior to data-type
    string scc;     //reserved word

    char ch, temp_name[100];

    FILE *f1;
    printf("enter file path (drive:\\fold\\filename)\n");
    gets(temp_name);

    f1 = fopen(temp_name,"r");
    if(f1==NULL)
    {
        printf("file not found");
        return 0;
    }
    else
    {
        string sss, lex_x[2000];
        char next_c;
        string p_c = ""; // for declaring new string
        int t = 0, tt = -1, s1 = 0;
        while((next_c=fgetc(f1))!=EOF) //for spaces
        {
            if(lex_x[s1] == "//")
                while((next_c=fgetc(f1)) != '\n'); //for single line comment


            string str_s1;
            str_s1 = next_c;

            if(is_operator(str_s1) != -1) //for comparing operator or not
            {
                if(str_s1 != p_c) //
                    if(!(is_operator(p_c) != -1)) //for comparing next opeator is not same
                        s1++;
            }
            else if(is_operator(p_c) != -1) //for comparing previous is not operator
                s1++;
            else if(is_symbol(str_s1) != -1) //
            {
                if(str_s1 != p_c)
                    //if(!(is_symbol(p_c) != -1)) //for comparing next symbol is not same
                        s1++;

            }
            else if(is_symbol(p_c) != -1) //for comparing previous is not symbol
                s1++;
            else if(isspace(next_c) || next_c == '\n' || next_c == '\0' || next_c == '\t') //for new line
            {
                p_c = next_c;
                s1++;
                continue;
            }
            lex_x[s1] = lex_x[s1] + next_c; //saving to lexime table
            p_c = next_c;
        }

        for(int hh = 0; hh <= s1; hh++)
        {

            //cout << ":" << lex_x[hh] << ":" <<endl; //
            strcpy(temp_name, lex_x[hh].c_str()); // copy from table to temp
            //temp_name = lex_x[hh];



        //while((fscanf(f1, "%s", temp_name)) != EOF)
            if(is_digits(temp_name)) //find digit
            {
                sss = temp_name;
                tokensl[t] = sss;
                tokensn[t] = "number\t";
                tokensa[t] = "constant";
                t++;
            }
            else if(lex_x[hh] == " " || lex_x[hh] == "\t" || lex_x[hh] == "\n" || lex_x[hh] == "" || lex_x[hh][0] == '\0')
                continue;
            else if(is_symbol(lex_x[hh]) != -1)  //find symbol
            {
                sss = temp_name;
                tokensl[t] = sss;
                tokensn[t] = "special symbol";
                tokensa[t] = names(is_symbol(temp_name), "symb");
                t++;
            }
            else if(is_keyword(temp_name))  //find keyword
            {
                scc = temp_name;
                sss = temp_name;
                tokensl[t] = sss;
                tokensn[t] = sss;
                tokensa[t] = "\t-";
                t++;
            }
            else if(is_operator(temp_name) != -1)   //find operator
            {
                sss = temp_name;
                tokensl[t] = sss;
                tokensn[t] = "operator";
                tokensa[t] = names(is_operator(temp_name), "oper");
                t++;
            }
            else         //invalid identifier
            {
                sss = temp_name; //invalid identifier
                if(temp_name[0] == '0' || temp_name[0] == '1' || temp_name[0] == '2' || temp_name[0] == '3' || temp_name[0] == '4' || temp_name[0] == '5' || temp_name[0] == '6' || temp_name[0] == '7' || temp_name[0] == '8' || temp_name[0] == '9' || temp_name[0] == '$' )
                    cout << "\n" << sss << ": invalid identifier detected." << endl;
                else if(temp_name[0] == '/' && (temp_name[1] == '/' ||temp_name[1] == '*') || temp_name[2] == '/')
                    cout << "\n" << sss << ": comment." << endl;
                else //valid
                {
                    //token table
                    tokensl[t] = sss;
                    tokensn[t] = "id\t";
                    tokensa[t] = "pointer to symbol table";
                    t++;

                    int aa = 0;
                    for(int c = 0; c <= tt; c++) //find duplicate
                    {
                        if(sys[c] == sss)
                            aa = 1;
                    }

                    if(aa == 0)  //symbol table
                    {
                        tt++;
                        sys[tt] = sss;
                        syt[tt] = "id";
                        if(sss == "main" || sss == "return" || sss == "printf" || sss == "scanf" || temp_name[0] == '"')
                            syd[tt] = "-";
                        else
                            syd[tt] = scc;
                    }
                }

            }
        }

        cout << "\n\tTokens\n";
        cout << "\tLexeme\t\tToken Name\t\tAttribute value\n";
        for(int i = 0; i < t; i++)
        {
            if(tokensl[i][0] != '\0' )
                cout << "\t" << tokensl[i] << "\t\t" << tokensn[i] << "\t\t" << tokensa[i] << "\t\t" << endl;
        }

        cout << "\n\n\n\tSymbol Table:\n";
        cout << "\tSymbol\t\tToken\t\tData type\tPointer to symbol table entry\n";
        for(int i = 0; i <= tt; i++)
        {
            cout << "\t" << sys[i] << "\t\t" << syt[i] << "\t\t" << syd[i] << "\t\t" << i << endl;
        }

    }









    /*
    char keyword[32][10] = {"auto","break","case","char","const","continue","default",
                    "do","double","else","enum","extern","float","for","goto",
                    "if","int","long","register","return","short","signed",
                    "sizeof","static","struct","switch","typedef","union",
                    "unsigned","void","volatile","while"
                   };

    char comper[17] = "\t\n,;(){}[]#\"<>";
    char ch, temp_name[100];
    FILE *f1;
    printf("enter file path (drive:\\fold\\filename)\n");
    gets(temp_name);
    int id = 0, key = 0, num = 0, comp = 0;


    f1 = fopen(temp_name,"r");
    //f1 = fopen("Input","r");
    if(f1==NULL)
    {
        printf("file not found");
        return 0;
    }
    else
    {
        int mm;
        while((fscanf(f1, "%s", temp_name)) != EOF)
        {
            mm = 0;

            for(int i = 0; i < 32; i++)
            {
                if(strcmp(keyword[i], temp_name) == 0)
                {
                    cout << temp_name << " is a keyword" << endl;
                    mm = 1;
                    key++;
                }
            }

            if(mm != 1)
                for(int i = 0; i < 17; i++)
                {
                    if(comper[i] == temp_name[0])
                    {
                        cout << temp_name << " is a Comparator" << endl;
                        mm = 1;
                        comp++;
                    }
                }
            if(mm != 1)
                if(is_digits(temp_name))
                {
                    cout << temp_name << " is a digit" << endl;
                    mm = 1;
                    num++;
                }



            if(mm == 0)
            {
                cout << temp_name << " is an identifier" << endl;
                id++;
            }
        }
        cout << "Identifier: " << id << endl;
        cout << "Digit: " << num << endl;
        cout << "Comparator: " << num << endl;
        cout << "Keyword: " << num << endl;

    }
*/
    return 0;
}
