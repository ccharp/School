%{
#include <stdio.h>
%}

%option       noyywrap nounput

%%
^[0-9]+ {
	printf( "qdel %s", yytext );
}

\.fusion.* {
	printf( "" );
}

\/\/.*$ {
	printf( "\/* %s *\/", yytext + 2 );
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
