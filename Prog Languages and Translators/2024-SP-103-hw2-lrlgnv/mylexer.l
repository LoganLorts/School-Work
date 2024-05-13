/*Logan Lorts */
/* A starting flex file */
		               /* ---- PROLOGUE ---- */
%{
#include <iostream>
using namespace std;
#include <string>

int no_lines = 0;
int no_tokens = 0;

void print_format(int no_tokens, const char* type, const char* token);
%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap
DIGIT		[0-9]
NONZERODIGIT [1-9]
INTCONST    (\+|-)?{DIGIT}+
NONZEROINTCONST (\+|-)?{NONZERODIGIT}+
DECCONST    {INTCONST}\.{DIGIT}+
SCICONST    {DECCONST}"E"{NONZEROINTCONST}
HEXCONST    ([A-F]|{DIGIT})+"H"
BINCONST    (0|1)+"B"
STRCONST    \"(.*)\"
CHCONST     ([A-F]|{DIGIT}){2}"X"
IDENT       [A-Za-z]+([A-Z]|[a-z]|[0-9]|_)*
COMMENT     \%+.*\n

%%  		              /* ---- REGULAR EXPRESSIONS ---- */

"+"|"-"|"*"|"/"|"<"|">"|"="|"&"|"#" { print_format(no_tokens, "OPERATOR", yytext); no_tokens++; }
"FUNCTION"      { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"IF"            { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"THEN"          { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"ELSE"          { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"WHILE"         { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"END"           { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
"WRITE"         { print_format(no_tokens, "KEYWORD", yytext); no_tokens++; }
[ \t]           ;
\n              { no_lines++; }
{INTCONST}      { print_format(no_tokens, "INTCONST", yytext); no_tokens++; }
{DECCONST}      { print_format(no_tokens, "DECCONST", yytext); no_tokens++; }
{SCICONST}      { print_format(no_tokens, "SCICONST", yytext); no_tokens++; }
{HEXCONST}      { print_format(no_tokens, "HEXCONST", yytext); no_tokens++; }
{BINCONST}      { print_format(no_tokens, "BINCONST", yytext); no_tokens++; }
{STRCONST}      { print_format(no_tokens, "STRCONST", yytext); no_tokens++; }
{CHCONST}       { print_format(no_tokens, "CHCONST", yytext); no_tokens++; }
{IDENT}         { print_format(no_tokens, "IDENT", yytext); no_tokens++; }
{COMMENT}       { no_lines++; }
.               { print_format(no_tokens, "?", yytext); no_tokens++; }

%%  		              /* ---- EPILOGUE ---- */
void print_format(int no_tokens, const char* type, const char* token){
    printf("%i: TOKEN: %-30s LEXEME: %s\n", no_tokens, type, token);
}
int main()
{
    yylex();
    cout << no_lines << " lines processed." << endl;
    return 0;
}
