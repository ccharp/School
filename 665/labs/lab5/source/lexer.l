%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcg.yacc.h>

#ifndef NDEBUG
	#define printf( ...) DEBUGF(__VA_ARGS__ )
#else
	#define printf( ... )
#endif

int list_type;
%}

%option       noyywrap nounput yylineno
%x 			  BLOCKCOMMENT

%%

"/*" {
	BEGIN BLOCKCOMMENT; 
}

<BLOCKCOMMENT>.|\n {

}

<BLOCKCOMMENT>"*/" {
	BEGIN 0;
}

"static" {
	printf( "STATIC\n" );
	return STATIC;
}

"void" {
	printf(  "VOID\n"  );
	return VOID;
}

"char" {
	printf(  "CHAR\n"  );
	return CHAR;
}

"short" {
	printf(  "SHORT\n"  );
	return SHORT;
}

"int" {
	printf(  "INT\n"  );
	return INT;
}

"float" {
	printf(  "FLOAT\n"  );
	return FLOAT;
}

"long" {
	printf(  "LONG\n"  );
	return LONG;
}

"double" {
	printf(  "DOUBLE\n"  ); 
	return DOUBLE; 
}

"==" {
	printf(  "EQ\n"  );
	return EQ; 
}

"<=" {
	printf(  "LE\n" );
	return LTE; 
}

"&&" {
	printf(  "AND\n"  );
	return AND; 
}

"<<" {
	printf(  "LSH\n"  ); 
	return BITSHIFTL; 
}

"+=" {
	printf(  "SETADD\n"  );
	return PLUSEQ; 
}

"/=" {
	printf(  "SETDIV\n"  );
	return DIVEQ; 
}

"&=" {
	printf(  "SETAND\n"  );
	return ANDEQ; 
}

">>=" {
	printf(  "SETRSH\n"  );
	return RIGHTSHIFTEQ; 
}

"!=" {
	printf(  "NE\n"  );
	return NOTEQ; 
}

"||" {
	printf(  "OR\n"  );
	return OR;
}

">>" {
	printf(  "RSH\n"  );
	return BITSHIFTRIGHT; 
}

"-=" {
	printf(  "SETSUB\n"  );
	return SUBEQ; 
}

"%=" {
	printf(  "SETMOD\n"  );
	return MODEQ;
}

"^=" {
	printf(  "SETXOR\n"  );
	return XOREQ; 
}

">=" {
	printf(  "GE\n"  );
	return GTEQ; 
}

"<" {
	printf(  "LT\n"  );
	return '<';
}

">" {
	printf(  "GT\n"  );
	return '>'; 
}

"~" {
	printf(  "COM\n"  );
	return '~';
}

"*=" {
	printf(  "SETMUL\n"  );
	return MULTEQ; 
}

"|=" {
	printf(  "SETOR\n"  );
	return OREQ;
}

"<<=" {
	printf(  "SETLSH\n"  );
	return BITSHIFTLEFTEQ; 
}

"&" {
	printf(  "BITAND\n"  );
	return '&';
}

"*" {
	printf(  "MUL\n"  );
	return '*';
}

"-" {
	printf(  "SUB\n"  );
	return '-';
}

"+" {
	printf(  "ADD\n"  );
	return '+'; 
}

"!" {
	printf(  "NOT\n"  );
	return '!';
}

"^" {
	printf(  "BITXOR\n"  );
	return '^'; 
}

"%" {
	printf(  "MOD\n"  );
	return '%';
}

"/" {
	printf(  "DIV\n"  );
	return '/';
}

"|" {
	printf(  "BITOR\n"  );
	return '|';
}

"=" {
	printf(  "SET\n"  );
	return '=';
}

"return" {
	printf(  "RETURN\n"  );
	return RETURN; 
}

"while" { 
	printf(  "WHILE\n"  );
	return WHILE;
}

"switch" { 
	printf(  "SWITCH\n"  );
	return SWITCH;
}

"default" { 
	printf(  "DEFAULT\n"  );
	return DEFAULT;
}

"else" { 
	printf(  "ELSE\n"  );
	return ELSE;
}

"break" { 
	printf(  "BREAK\n"  );
	return BREAK;
}

"do" { 
	printf(  "DO\n"  );
	return DO;
}

"for" { 
	printf(  "FOR\n"  );
	return FOR;
}

"case" { 
	printf(  "CASE\n"  );
	return CASE;
}

"if" { 
	printf(  "IF\n"  );
	return IF;
}

"continue" { 
	printf(  "CONTINUE\n"  );
	return CONTINUE;
}

"goto" { 
	printf(  "GOTO\n"  );
	return GOTO;
}

"unsigned" { 
	printf(  "UNSIGNED\n"  );
	return UNSIGNED;
}

"struc" { 
	printf(  "STRUCT\n"  );
	return STRUCT;
}

"const" { 
	printf(  "CONST\n"  );
	return CONST;
}

"extern" { 
	printf(  "EXTERN\n"  );
	return EXTERN;
}

"register" { 
	printf(  "REGISTER\n"  );
	return REGISTER;
}

"typedef" { 
	printf(  "TYPEDEF\n"  );
	return TYPEDEF;
}

"union" { 
	printf(  "UNION\n"  );
	return UNION;
}

"auto" { 
	printf(  "AUTO\n"  );
	return AUTO;
}

"sizeof" { 
	printf(  "SIZEOF\n"  );
	return SIZEOF;
}

"#".*"\n" {
	printf(  "PREPROC\n"  );
	return PREPROC;
}

([0-9]+)|("0x"[a-fA-F0-9]+)|("0"[0-7]+) {
	printf(  "INTVAL\n"  );
	return INTVAL;
}

[0-9]+"."[0-9]+"f" {
	printf(  "FLTVAL\n"  );
	return FLTVAL;
}

[0-9]+"."[0-9]+ {
	printf(  "DBLVAL\n"  );
	return DBLVAL;
}

"\""[^\"]*"\"" {
	printf(  "STRVAL\n"  );
	return STRVAL;
}

"'"(.|" "|"\\n"|"\\t")"'" {
	printf(  "CHARVAL\n"  );
	return CHARVAL;
}

[a-zA-Z][_a-zA-Z0-9]* {
	printf(  "ID\n"  );
	yylval.id = strdup(yytext);
	return ID;
}

";" {
	printf( ";\n" );
	return SEMICOLON;
}
"(" {
	printf( "(\n" );
	return LEFTPAREN;
}
")" {
	printf( ")\n" );
	return RIGHTPAREN;
}
"{" {
	printf( "{\n" );
	return LEFTBRACKET;
}

"}" {
	printf( "}\n" );
	return RIGHTBRACKET;
}

"]" {
	printf( "]\n" );
	return RIGHTSQRBRACK;
}

"[" {
	printf( "[\n" );
	return LEFTSQRBRACK;
}

"," {
	printf( ",\n" );
	return COMMA;
}

[ \t\n\r]+ {
	//Matched some whitespace
//	printf(  "FOUND SOME WHITE SPACE!"  ); 
}

. {
	// Something wasn't correctly caught by a previous regexp
	fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
	exit( 5 );
}

%%

/*int main( int argc, const char *argv[] ) {
	while( yylex() > 0 );
	return 0;
}*/




















