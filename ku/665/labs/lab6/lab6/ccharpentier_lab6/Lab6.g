//import java.lang.String
// The name of the grammar. The name here needs to match the name of the
// file, including capitalization.
grammar Lab6;

// Define literals, keywords or operators, here as tokens.
tokens {
}

// Written in the target language. The header section can be
// used to import any Java classes that may be required.
@header {
}

// A main function to the parser. This function will setup the
// parsers input stream and execute the rule named "top".
@members {
    public static void main(String[] args) throws Exception {
        Lab6Lexer lex = new Lab6Lexer(new ANTLRInputStream(System.in));
       	CommonTokenStream tokens = new CommonTokenStream(lex);
        Lab6Parser parser = new Lab6Parser(tokens);

        try {
            parser.top();
        } catch (RecognitionException e)  {
            e.printStackTrace();
        }
    }
}

// Some example lexer fragments. These fragments don't produce any
// tokens themselves but can be used inside of other lexer rules.
fragment BIN: '0' .. '1';
fragment OCT: '0' .. '7';
fragment DEC: '0' .. '9';
fragment HEX: ('0' .. '9' | 'A' .. 'F' | 'a' .. 'f');

PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
POW : '^'; 

LOG : 'l''o''g';
SIN : 's''i''n';
COS : 'c''o''s';
TAN : 't''a''n'; 

BINNUM : '0''b'(BIN)* ;
HEXNUM : '0''x'HEX* ;
DECNUM : '1' .. '9'DEC* ;
DECFRAC : DEC*'.'DEC* ;
OCTNUM : '0'OCT* ;

// The white space lexer rule. Match any number of white space characters
// and hide the results from the parser.
WS : (' ' | '\t' | '\r' | '\n')+ { $channel=HIDDEN; };

// The decimal value lexer rule. Match one or more decimal digits.
DECIMAL : DEC+ ;

// The top rule. You should replace this with your own rule definition to
// parse expressions according to the assignment.
top returns [double v] 
	: e=expr {System.out.print($e.v);}//$v = $e.v;}
	;

expr returns [double v] 
	: e=exprMult {$v = $e.v;}
	  (PLUS e1=exprMult {$v += $e1.v;}
	  |MINUS e2=exprMult {$v -= $e2.v;})*
	  ;

exprMult returns [double v]
	: m1=exprFunc {$v = $m1.v;}
	  (MULT m2=exprFunc {$v *= $m2.v;}
	  |DIV  m3=exprFunc {$v /= $m3.v;}
	  |POW  m4=exprFunc {$v = Math.pow($v, $m4.v);})*
	  ;
	  

exprFunc returns [double v]
	: f1=numExp	{$v = $f1.v;} 
	|
	  (COS f2=numExp {$v = Math.cos($f2.v);}
	  |SIN f3=numExp {$v = Math.sin($f3.v);}
	  |TAN f4=numExp {$v = Math.tan($f4.v);}
	  |LOG f5=numExp {$v = Math.log($f5.v);})*
	  ;

numExp returns [double v]
	: b=BINNUM {$v = Integer.parseInt($b.text.substring(2, $b.text.length()), 2);}
	| h=HEXNUM {$v = Integer.parseInt($h.text.substring(2, $h.text.length()), 16);}
	| d=DECNUM {$v = Integer.parseInt($d.text);}
	| df=DECFRAC {$v = Double.parseDouble($df.text);}
	| o=OCTNUM {$v = Integer.parseInt($o.text.substring(1, $o.text.length()), 8);}
	| '(' e=expr ')' {$v = $e.v;}
	;



/*
	: a1=DECNUM '+' a2=DECNUM {System.out.print(Integer.parseInt($a1.text) + Integer.parseInt($a2.text));}//$value = a1 + a2}
	;*/



















