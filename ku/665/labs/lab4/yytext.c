#include "lexer.l"

int main() {
	while( yytext() > 0 );
	return 0;
}
