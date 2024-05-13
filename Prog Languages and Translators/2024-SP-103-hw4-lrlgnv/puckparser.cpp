#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string token;
void getToken();
void error(string expected, string got );
bool is_Integer( string& s );
bool is_digit(char c);
bool is_digit(char c);
bool is_Decimal( string& s );
bool is_Identifier( string& s );
bool is_alpha(char c);
bool is_String( string& s );
bool is_MulOperator();
bool is_RelationalOperator();
bool is_AddOperator();
void parse_Term();
void parse_Factor();
void parse_WriteStmt();
void parse_Stmt();
void is_StmtSeq();
void parse_Expression();
void parse_SimpleExpression();
void parse_Assignment();
void parse_Designator();
void parse_Selector();

int main(){
  getToken();
  is_StmtSeq();
  cout << "CORRECT";
  return 0;
}

//input and output functions
void getToken() {
  cin >> token;
  if (token == "\n"){
    cout << "End of line" << endl;
    getToken();
    is_StmtSeq();
  }
}
void error(string expected, string got ){
  cout << "Error: \"" << expected << "\" expected, got \"" << got << "\"" << endl;
  exit(0);
}


//check type functions
bool isKey(const string token)
{
  bool keyword = true;

  //If the token is none of the following, it is not a keyword
  if (token != "WRITE" && token != "." && token != "[" && token != "]"
      && token != "(" && token != ")" && token != ";")
  {
    keyword = false;
  }

  return keyword;
}

bool is_Integer( string& s ){
  int i = 0;
  int state = 0;
  
  while ( i < s.length() ){
    switch(state){
      case 0 : if ( s[i] == '+' || s[i] == '-' ) state = 0;
               else if ( is_digit(s[i]) ) state = 1;
               else return false;
      case 1 : if ( is_digit(s[i]) ) state = 1;
               else return false;
	}
	i++;
  }
  if ( state != 1 ) return false;
  return true;
}
bool is_digit(char c){
    if (isdigit(c)) return true;
    else return false;
}
bool is_Decimal( string& s ){
  int i = 0;
  int state = 0;
  
  while ( i < s.length() ){
    switch(state){
      case 0 : if ( s[i] == '+' || s[i] == '-' ) state = 0;
               else if ( is_digit(s[i]) ) state = 1;
               else return false;
      case 1 : if ( is_digit(s[i]) ) state = 1;
               else if ( s[i] == '.' ) state = 2;
               else return false;
      case 2 : if ( is_digit(s[i]) ) state = 3;
               else return false;
      case 3 : if ( is_digit(s[i]) ) state = 3;
               else return false;
  }
  i++;
  }
  if ( state != 3 ) return false;
  return true;
}

bool is_Identifier( string& s ){
  int i = 0;
  int state = 0;
  if( isKey(s) ){
    return false;
  }
  while ( i < s.length() ){
    switch(state){
      case 0 : if ( is_alpha(s[i]) ) state = 1;
               else return false;
      case 1 : if ( is_alpha(s[i]) || is_digit(s[i]) ) state = 1;
               else return false;
    }
    i++;
  }
  if ( state != 1 ) return false;
  return true;
}
bool is_alpha(char c){
    if (isalpha(c)) return true;
    else return false;
}

bool is_String( string& s ){
  int i = 0;
  int state = 0;
  while ( i < s.length() ){
    switch(state){
      case 0 : if ( s[i] == '\"' ) state = 1;
               else return false;
      case 1 : if ( s[i] == '\"' ) state = 2;
               else if ( s[i] == ' ' ) return false;
               else state = 1;
      case 2 : if ( s[i] != '\"' ) state =1;
               else state = 2;
    }
    i++;
  }
  if ( state != 2 ) return false;
  return true;
}

bool is_MulOperator(){
  if ( token == "*" || token == "/" || token == "AND" ) {
    return true;
  }
  else return false;
  } 

bool is_RelationalOperator(){
  if ( token == "=" || token == "<" ||  token == ">" || token == "#" ) {
    return true;
  }
  else return false;
}
bool is_AddOperator(){
  if ( token == "+" || token == "-" || token == "OR" || token == "&" ) {
    return true;
  }
  else return false;
}


//parse functions
void parse_Term(){
  parse_Factor();
  while ( is_MulOperator() )
  {
    getToken();
    parse_Factor();
  } 
}

void parse_Factor(){
  if ( is_Integer( token ) ){
    getToken();
  }
  else if ( is_Decimal( token )){
    getToken();
  }
  else if ( is_Identifier( token )){
    getToken();
  }
  else if (is_String( token )){
    getToken();
  }
  else if ( token == "(" ) {
    getToken();
    parse_Expression();
    if ( token == ")" ) {
      getToken();
    }
    else error("Expected )", token);
  }
  else if ( token == "~" ){
    getToken();
    parse_Factor();
  }
  else error("Factor", token);
}

void parse_WriteStmt(){
  if ( token == "WRITE" ) {
    getToken();
    if( token == "(" ) {
      getToken();
      parse_Expression();
      if( token == ")" ){
        getToken();
 }
      else error("Expected )", token);
    }
    else error("Expected (", token);
  }
  else error("Expected WRITE", token);
}

void parse_Stmt(){
  if ( is_Identifier( token )) parse_Assignment();
  else if ( token == "WRITE" ) parse_WriteStmt();
  else
    error("Assignment or WriteStmt", token);
}

void is_StmtSeq(){
  parse_Stmt();
  while ( token == ";" ) {
  getToken();
    parse_Stmt();
  }
}

void parse_Expression(){
  parse_SimpleExpression();
  while ( is_RelationalOperator() )
  {
    getToken();
    parse_SimpleExpression();
  }
}
void parse_SimpleExpression(){
  parse_Term();
  while ( is_AddOperator() )
  {
    getToken();
    parse_Term();
  }
}

void parse_Assignment(){
  parse_Designator();
  if ( token == ":=" ){
    getToken();
    parse_Expression();
  }
  else error(":=", token);
}

void parse_Designator(){
  if ( is_Identifier( token ) ){
    getToken();
  while ( token == "."  || token == "[" ){
    parse_Selector();
  }
  }
  else error("identifier", token);
}
void parse_Selector(){
  if ( token == "." ){
    getToken();
    if ( is_Identifier( token ) ){
      getToken();
    }
    else error("Identifier", token);
  }
  else{
    if ( token == "[" ){
      getToken();
      parse_Expression();
      if ( token == "]" ){
        getToken();
      }
      else error("]", token);
    }
    else error(". or [", token);
  }
}
