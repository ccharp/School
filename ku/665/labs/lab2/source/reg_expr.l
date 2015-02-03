%{
#include <stdio.h>
%}

%option       noyywrap nounput

%%

. {
  /**************************************************************************
  * Example rule: matches any character but a newline
  * By default, if the input does not match any specified rules, the input
  * is printed as output.
  *************************************************************************/
  printf( "%s", yytext );
}

%%

/**************************************************************************
* If the user subroutines section was left empty and 'main' was specified
* as an option in the definitions section, Lex would provide this same
* main() by default.
*************************************************************************/
int main() {
  yylex();
  return 0;
}
