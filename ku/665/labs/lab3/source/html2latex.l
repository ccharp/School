%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int yydebug = 1;
int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARAGRAPH PRE OL UL LIST

%%

"<h1>"[^<]*"</h1>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4 );
}

"<h2>".*"</h2>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\subsection{%s}", yytext+4 );
}

"<h3>"[^<]*"</h3>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\subsubsection{%s}", yytext+4 );
}

"<pre>"(.|[\r\n])*"</pre>" {
	// matched HTML PRE. Do the same thing as if h1 encountered except 
	//	copy all text in between the open and close tags verbatim. 
	yytext[yyleng-6] = 0;
	printf( "\\begin{verbatim}%s\\end{verbatim}\n", yytext+5 );
}

"<!--" {
    /**************************************************************************
     * Matched an HTML comment so print it out as a LateX comment. The
     * beginning and ending tags are stripped off before the LateX  * is emitted.
     *************************************************************************/
    printf( "%% " ); // '%' escapes the following '%' character. Just prints 
					 // 	as comment in latex. 
    BEGIN COMMENT;
}

"<ul>".*"</ul>" {
	printf( "{\\Large bullshit}" );
}

"<p>" {
    /**************************************************************************
     * Matched an HTML paragraph to print it out as a LateX paragraph. The
     * beginning and ending tags are stripped off before the LateX paragraph 
     * is emitted.
     *************************************************************************/
	 // paragraphs have no begin symbol. 
	 BEGIN PARAGRAPH;
}

"<ul>" {
	printf( "\\begin{itemize}\n" );
	BEGIN LIST;
}

"<ol>" {
	printf( "\\begin{enumerate}\n " );
	BEGIN LIST;
}

[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

. {
    /**************************************************************************
     * Matched something that we did not expect to see. Issue an error and
     * exit the program with a failure message.
     *************************************************************************/
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 5 );
}

<LIST>"<li>" {
	printf( "\\item " );
	BEGIN PARAGRAPH;
}

<LIST>"</ul>" {
	printf( "\\end{itemize}\n" );
	BEGIN 0;
}

<LIST>"</ol>" {
	printf( "\\end{enumerate}\n" );
	BEGIN 0;
}

<PARAGRAPH>"</p>" {
	// Match with end of paragraph. print new line. 
	printf( "\n\n" );
	BEGIN 0;
}

<PARAGRAPH>"</li>" {
	printf( "\n" );
	BEGIN LIST;
}

<PARAGRAPH>[^<]* {
	// Matched inside of HTML paragraph with any alpha text. Print it and
	// 	continue parsing.
	printf( "%s", yytext ); 
}

<PARAGRAPH>"<b>"[^<]*"</b>" {
	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext + 3 );
}

<PARAGRAPH>"<big>".*"</big>" {
	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext + 5 );
}

<PARAGRAPH>"<small>".*"</small>" {
	yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext + 7 );
}


<PARAGRAPH>"<b>".*"</b>" {
	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext + 3 );
}

<PARAGRAPH>"<i>".*"</i>" {
	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext + 3 );
}

<PARAGRAPH>"<em>".*"</em>" {
	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}" , yytext + 4 );
}

<PARAGRAPH>"<strong>".*"</strong>" {
	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext + 8 );
}

<PARAGRAPH>"<sub>".*"</sub>" {
	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext + 5 );
}

<PARAGRAPH>"<sup>"[^<]*"</sup>" {
	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext + 5 );
}

<PARAGRAPH>. {
	printf( "ERROR AT: %s.", yytext );
	exit(1);
}

<COMMENT>"-->" {
    /**************************************************************************
     * Matched an HTML end comment while parsing an HTML comment. Print out
     * a new line and resume normal parsing.
     *************************************************************************/
    printf( "\n" );
    BEGIN 0;
}

<COMMENT>[\n](\r)? {
    /**************************************************************************
     * Matched a newline and possible carriage return while parsing an HTML
     * comment. Print out a new line making sure to mark the next line as a
     * comment as well.
     *************************************************************************/
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    /**************************************************************************
     * Matched some white space while parsing an HTML comment. Print out
     * the white space as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>. {
    /**************************************************************************
     * Matched any other text while parsing an HTML comment. Print out
     * the text as is.
     *************************************************************************/
	printf( "%s", yytext );
    //fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
	//exit(1);
}

%%

/**************************************************************************
 * The main function for the HTML to LateX converter. Here we do three
 * things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
