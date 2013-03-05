// $ANTLR 3.4 /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g 2012-10-30 22:56:29



import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

import org.antlr.runtime.debug.*;
import java.io.IOException;
@SuppressWarnings({"all", "warnings", "unchecked"})
public class Lab6Parser extends DebugParser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "BIN", "BINNUM", "COS", "DEC", "DECFRAC", "DECIMAL", "DECNUM", "DIV", "HEX", "HEXNUM", "LOG", "MINUS", "MULT", "OCT", "OCTNUM", "PLUS", "POW", "SIN", "TAN", "WS", "'('", "')'"
    };

    public static final int EOF=-1;
    public static final int T__24=24;
    public static final int T__25=25;
    public static final int BIN=4;
    public static final int BINNUM=5;
    public static final int COS=6;
    public static final int DEC=7;
    public static final int DECFRAC=8;
    public static final int DECIMAL=9;
    public static final int DECNUM=10;
    public static final int DIV=11;
    public static final int HEX=12;
    public static final int HEXNUM=13;
    public static final int LOG=14;
    public static final int MINUS=15;
    public static final int MULT=16;
    public static final int OCT=17;
    public static final int OCTNUM=18;
    public static final int PLUS=19;
    public static final int POW=20;
    public static final int SIN=21;
    public static final int TAN=22;
    public static final int WS=23;

    // delegates
    public Parser[] getDelegates() {
        return new Parser[] {};
    }

    // delegators


public static final String[] ruleNames = new String[] {
    "invalidRule", "top", "expr", "numExp", "exprFunc", "exprMult"
};

public static final boolean[] decisionCanBacktrack = new boolean[] {
    false, // invalid decision
    false, false, false, false
};

 
    public int ruleLevel = 0;
    public int getRuleLevel() { return ruleLevel; }
    public void incRuleLevel() { ruleLevel++; }
    public void decRuleLevel() { ruleLevel--; }
    public Lab6Parser(TokenStream input) {
        this(input, DebugEventSocketProxy.DEFAULT_DEBUGGER_PORT, new RecognizerSharedState());
    }
    public Lab6Parser(TokenStream input, int port, RecognizerSharedState state) {
        super(input, state);
        DebugEventSocketProxy proxy =
            new DebugEventSocketProxy(this, port, null);

        setDebugListener(proxy);
        try {
            proxy.handshake();
        }
        catch (IOException ioe) {
            reportError(ioe);
        }
    }

public Lab6Parser(TokenStream input, DebugEventListener dbg) {
    super(input, dbg, new RecognizerSharedState());
}

protected boolean evalPredicate(boolean result, String predicate) {
    dbg.semanticPredicate(result, predicate);
    return result;
}

    public String[] getTokenNames() { return Lab6Parser.tokenNames; }
    public String getGrammarFileName() { return "/users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g"; }


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



    // $ANTLR start "top"
    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:64:1: top returns [double v] : e= expr ;
    public final double top() throws RecognitionException {
        double v = 0.0;


        double e =0.0;


        try { dbg.enterRule(getGrammarFileName(), "top");
        if ( getRuleLevel()==0 ) {dbg.commence();}
        incRuleLevel();
        dbg.location(64, 0);

        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:65:2: (e= expr )
            dbg.enterAlt(1);

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:65:4: e= expr
            {
            dbg.location(65,5);
            pushFollow(FOLLOW_expr_in_top288);
            e=expr();

            state._fsp--;

            dbg.location(65,11);
            System.out.print(e);

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        dbg.location(66, 1);

        }
        finally {
            dbg.exitRule(getGrammarFileName(), "top");
            decRuleLevel();
            if ( getRuleLevel()==0 ) {dbg.terminate();}
        }

        return v;
    }
    // $ANTLR end "top"



    // $ANTLR start "expr"
    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:68:1: expr returns [double v] : e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )* ;
    public final double expr() throws RecognitionException {
        double v = 0.0;


        double e =0.0;

        double e1 =0.0;

        double e2 =0.0;


        try { dbg.enterRule(getGrammarFileName(), "expr");
        if ( getRuleLevel()==0 ) {dbg.commence();}
        incRuleLevel();
        dbg.location(68, 0);

        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:69:2: (e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )* )
            dbg.enterAlt(1);

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:69:4: e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )*
            {
            dbg.location(69,5);
            pushFollow(FOLLOW_exprMult_in_expr308);
            e=exprMult();

            state._fsp--;

            dbg.location(69,15);
            v = e;
            dbg.location(70,4);
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:70:4: ( PLUS e1= exprMult | MINUS e2= exprMult )*
            try { dbg.enterSubRule(1);

            loop1:
            do {
                int alt1=3;
                try { dbg.enterDecision(1, decisionCanBacktrack[1]);

                int LA1_0 = input.LA(1);

                if ( (LA1_0==PLUS) ) {
                    alt1=1;
                }
                else if ( (LA1_0==MINUS) ) {
                    alt1=2;
                }


                } finally {dbg.exitDecision(1);}

                switch (alt1) {
            	case 1 :
            	    dbg.enterAlt(1);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:70:5: PLUS e1= exprMult
            	    {
            	    dbg.location(70,5);
            	    match(input,PLUS,FOLLOW_PLUS_in_expr316); 
            	    dbg.location(70,12);
            	    pushFollow(FOLLOW_exprMult_in_expr320);
            	    e1=exprMult();

            	    state._fsp--;

            	    dbg.location(70,22);
            	    v += e1;

            	    }
            	    break;
            	case 2 :
            	    dbg.enterAlt(2);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:71:5: MINUS e2= exprMult
            	    {
            	    dbg.location(71,5);
            	    match(input,MINUS,FOLLOW_MINUS_in_expr328); 
            	    dbg.location(71,13);
            	    pushFollow(FOLLOW_exprMult_in_expr332);
            	    e2=exprMult();

            	    state._fsp--;

            	    dbg.location(71,23);
            	    v -= e2;

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);
            } finally {dbg.exitSubRule(1);}


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        dbg.location(72, 3);

        }
        finally {
            dbg.exitRule(getGrammarFileName(), "expr");
            decRuleLevel();
            if ( getRuleLevel()==0 ) {dbg.terminate();}
        }

        return v;
    }
    // $ANTLR end "expr"



    // $ANTLR start "exprMult"
    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:74:1: exprMult returns [double v] : m1= exprFunc ( MULT m2= numExp | DIV m3= numExp | POW m4= numExp )* ;
    public final double exprMult() throws RecognitionException {
        double v = 0.0;


        double m1 =0.0;

        double m2 =0.0;

        double m3 =0.0;

        double m4 =0.0;


        try { dbg.enterRule(getGrammarFileName(), "exprMult");
        if ( getRuleLevel()==0 ) {dbg.commence();}
        incRuleLevel();
        dbg.location(74, 0);

        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:75:2: (m1= exprFunc ( MULT m2= numExp | DIV m3= numExp | POW m4= numExp )* )
            dbg.enterAlt(1);

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:75:4: m1= exprFunc ( MULT m2= numExp | DIV m3= numExp | POW m4= numExp )*
            {
            dbg.location(75,6);
            pushFollow(FOLLOW_exprFunc_in_exprMult355);
            m1=exprFunc();

            state._fsp--;

            dbg.location(75,16);
            v = m1;
            dbg.location(76,4);
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:76:4: ( MULT m2= numExp | DIV m3= numExp | POW m4= numExp )*
            try { dbg.enterSubRule(2);

            loop2:
            do {
                int alt2=4;
                try { dbg.enterDecision(2, decisionCanBacktrack[2]);

                switch ( input.LA(1) ) {
                case MULT:
                    {
                    alt2=1;
                    }
                    break;
                case DIV:
                    {
                    alt2=2;
                    }
                    break;
                case POW:
                    {
                    alt2=3;
                    }
                    break;

                }

                } finally {dbg.exitDecision(2);}

                switch (alt2) {
            	case 1 :
            	    dbg.enterAlt(1);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:76:5: MULT m2= numExp
            	    {
            	    dbg.location(76,5);
            	    match(input,MULT,FOLLOW_MULT_in_exprMult363); 
            	    dbg.location(76,12);
            	    pushFollow(FOLLOW_numExp_in_exprMult367);
            	    m2=numExp();

            	    state._fsp--;

            	    dbg.location(76,20);
            	    v *= m2;

            	    }
            	    break;
            	case 2 :
            	    dbg.enterAlt(2);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:77:5: DIV m3= numExp
            	    {
            	    dbg.location(77,5);
            	    match(input,DIV,FOLLOW_DIV_in_exprMult375); 
            	    dbg.location(77,12);
            	    pushFollow(FOLLOW_numExp_in_exprMult380);
            	    m3=numExp();

            	    state._fsp--;

            	    dbg.location(77,20);
            	    v /= m3;

            	    }
            	    break;
            	case 3 :
            	    dbg.enterAlt(3);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:78:5: POW m4= numExp
            	    {
            	    dbg.location(78,5);
            	    match(input,POW,FOLLOW_POW_in_exprMult388); 
            	    dbg.location(78,12);
            	    pushFollow(FOLLOW_numExp_in_exprMult393);
            	    m4=numExp();

            	    state._fsp--;

            	    dbg.location(78,20);
            	    v = Math.pow(v, m4);

            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);
            } finally {dbg.exitSubRule(2);}


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        dbg.location(79, 3);

        }
        finally {
            dbg.exitRule(getGrammarFileName(), "exprMult");
            decRuleLevel();
            if ( getRuleLevel()==0 ) {dbg.terminate();}
        }

        return v;
    }
    // $ANTLR end "exprMult"



    // $ANTLR start "exprFunc"
    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:82:1: exprFunc returns [double v] : f1= numExp ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )* ;
    public final double exprFunc() throws RecognitionException {
        double v = 0.0;


        double f1 =0.0;

        double f2 =0.0;

        double f3 =0.0;

        double f4 =0.0;

        double f5 =0.0;


        try { dbg.enterRule(getGrammarFileName(), "exprFunc");
        if ( getRuleLevel()==0 ) {dbg.commence();}
        incRuleLevel();
        dbg.location(82, 0);

        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:83:2: (f1= numExp ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )* )
            dbg.enterAlt(1);

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:83:4: f1= numExp ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )*
            {
            dbg.location(83,6);
            pushFollow(FOLLOW_numExp_in_exprFunc420);
            f1=numExp();

            state._fsp--;

            dbg.location(83,14);
            v = f1;
            dbg.location(84,4);
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:84:4: ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )*
            try { dbg.enterSubRule(3);

            loop3:
            do {
                int alt3=5;
                try { dbg.enterDecision(3, decisionCanBacktrack[3]);

                switch ( input.LA(1) ) {
                case COS:
                    {
                    alt3=1;
                    }
                    break;
                case SIN:
                    {
                    alt3=2;
                    }
                    break;
                case TAN:
                    {
                    alt3=3;
                    }
                    break;
                case LOG:
                    {
                    alt3=4;
                    }
                    break;

                }

                } finally {dbg.exitDecision(3);}

                switch (alt3) {
            	case 1 :
            	    dbg.enterAlt(1);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:84:5: COS f2= numExp
            	    {
            	    dbg.location(84,5);
            	    match(input,COS,FOLLOW_COS_in_exprFunc429); 
            	    dbg.location(84,11);
            	    pushFollow(FOLLOW_numExp_in_exprFunc433);
            	    f2=numExp();

            	    state._fsp--;

            	    dbg.location(84,19);
            	    v = Math.cos(f2);

            	    }
            	    break;
            	case 2 :
            	    dbg.enterAlt(2);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:85:5: SIN f3= numExp
            	    {
            	    dbg.location(85,5);
            	    match(input,SIN,FOLLOW_SIN_in_exprFunc441); 
            	    dbg.location(85,11);
            	    pushFollow(FOLLOW_numExp_in_exprFunc445);
            	    f3=numExp();

            	    state._fsp--;

            	    dbg.location(85,19);
            	    v = Math.sin(f3);

            	    }
            	    break;
            	case 3 :
            	    dbg.enterAlt(3);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:86:5: TAN f4= numExp
            	    {
            	    dbg.location(86,5);
            	    match(input,TAN,FOLLOW_TAN_in_exprFunc453); 
            	    dbg.location(86,11);
            	    pushFollow(FOLLOW_numExp_in_exprFunc457);
            	    f4=numExp();

            	    state._fsp--;

            	    dbg.location(86,19);
            	    v = Math.tan(f4);

            	    }
            	    break;
            	case 4 :
            	    dbg.enterAlt(4);

            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:87:5: LOG f5= numExp
            	    {
            	    dbg.location(87,5);
            	    match(input,LOG,FOLLOW_LOG_in_exprFunc465); 
            	    dbg.location(87,11);
            	    pushFollow(FOLLOW_numExp_in_exprFunc469);
            	    f5=numExp();

            	    state._fsp--;

            	    dbg.location(87,19);
            	    v = Math.log(f5);

            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);
            } finally {dbg.exitSubRule(3);}


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        dbg.location(88, 3);

        }
        finally {
            dbg.exitRule(getGrammarFileName(), "exprFunc");
            decRuleLevel();
            if ( getRuleLevel()==0 ) {dbg.terminate();}
        }

        return v;
    }
    // $ANTLR end "exprFunc"



    // $ANTLR start "numExp"
    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:90:1: numExp returns [double v] : (b= BINNUM |h= HEXNUM |d= DECNUM |df= DECFRAC |o= OCTNUM | '(' e= expr ')' );
    public final double numExp() throws RecognitionException {
        double v = 0.0;


        Token b=null;
        Token h=null;
        Token d=null;
        Token df=null;
        Token o=null;
        double e =0.0;


        try { dbg.enterRule(getGrammarFileName(), "numExp");
        if ( getRuleLevel()==0 ) {dbg.commence();}
        incRuleLevel();
        dbg.location(90, 0);

        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:91:2: (b= BINNUM |h= HEXNUM |d= DECNUM |df= DECFRAC |o= OCTNUM | '(' e= expr ')' )
            int alt4=6;
            try { dbg.enterDecision(4, decisionCanBacktrack[4]);

            switch ( input.LA(1) ) {
            case BINNUM:
                {
                alt4=1;
                }
                break;
            case HEXNUM:
                {
                alt4=2;
                }
                break;
            case DECNUM:
                {
                alt4=3;
                }
                break;
            case DECFRAC:
                {
                alt4=4;
                }
                break;
            case OCTNUM:
                {
                alt4=5;
                }
                break;
            case 24:
                {
                alt4=6;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 4, 0, input);

                dbg.recognitionException(nvae);
                throw nvae;

            }

            } finally {dbg.exitDecision(4);}

            switch (alt4) {
                case 1 :
                    dbg.enterAlt(1);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:91:4: b= BINNUM
                    {
                    dbg.location(91,5);
                    b=(Token)match(input,BINNUM,FOLLOW_BINNUM_in_numExp492); 
                    dbg.location(91,13);
                    v = Integer.parseInt((b!=null?b.getText():null).substring(2, (b!=null?b.getText():null).length()), 2);

                    }
                    break;
                case 2 :
                    dbg.enterAlt(2);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:92:4: h= HEXNUM
                    {
                    dbg.location(92,5);
                    h=(Token)match(input,HEXNUM,FOLLOW_HEXNUM_in_numExp501); 
                    dbg.location(92,13);
                    v = Integer.parseInt((h!=null?h.getText():null).substring(2, (h!=null?h.getText():null).length()), 16);

                    }
                    break;
                case 3 :
                    dbg.enterAlt(3);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:93:4: d= DECNUM
                    {
                    dbg.location(93,5);
                    d=(Token)match(input,DECNUM,FOLLOW_DECNUM_in_numExp510); 
                    dbg.location(93,13);
                    v = Integer.parseInt((d!=null?d.getText():null));

                    }
                    break;
                case 4 :
                    dbg.enterAlt(4);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:94:4: df= DECFRAC
                    {
                    dbg.location(94,6);
                    df=(Token)match(input,DECFRAC,FOLLOW_DECFRAC_in_numExp519); 
                    dbg.location(94,15);
                    v = Double.parseDouble((df!=null?df.getText():null));

                    }
                    break;
                case 5 :
                    dbg.enterAlt(5);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:95:4: o= OCTNUM
                    {
                    dbg.location(95,5);
                    o=(Token)match(input,OCTNUM,FOLLOW_OCTNUM_in_numExp528); 
                    dbg.location(95,13);
                    v = Integer.parseInt((o!=null?o.getText():null).substring(1, (o!=null?o.getText():null).length()), 8);

                    }
                    break;
                case 6 :
                    dbg.enterAlt(6);

                    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:96:4: '(' e= expr ')'
                    {
                    dbg.location(96,4);
                    match(input,24,FOLLOW_24_in_numExp535); 
                    dbg.location(96,9);
                    pushFollow(FOLLOW_expr_in_numExp539);
                    e=expr();

                    state._fsp--;

                    dbg.location(96,15);
                    match(input,25,FOLLOW_25_in_numExp541); 
                    dbg.location(96,19);
                    v = e;

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        dbg.location(97, 1);

        }
        finally {
            dbg.exitRule(getGrammarFileName(), "numExp");
            decRuleLevel();
            if ( getRuleLevel()==0 ) {dbg.terminate();}
        }

        return v;
    }
    // $ANTLR end "numExp"

    // Delegated rules


 

    public static final BitSet FOLLOW_expr_in_top288 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_exprMult_in_expr308 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_PLUS_in_expr316 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_exprMult_in_expr320 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_MINUS_in_expr328 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_exprMult_in_expr332 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_exprFunc_in_exprMult355 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_MULT_in_exprMult363 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprMult367 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_DIV_in_exprMult375 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprMult380 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_POW_in_exprMult388 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprMult393 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_numExp_in_exprFunc420 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_COS_in_exprFunc429 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc433 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_SIN_in_exprFunc441 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc445 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_TAN_in_exprFunc453 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc457 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_LOG_in_exprFunc465 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc469 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_BINNUM_in_numExp492 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_HEXNUM_in_numExp501 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_DECNUM_in_numExp510 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_DECFRAC_in_numExp519 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_OCTNUM_in_numExp528 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_24_in_numExp535 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_expr_in_numExp539 = new BitSet(new long[]{0x0000000002000000L});
    public static final BitSet FOLLOW_25_in_numExp541 = new BitSet(new long[]{0x0000000000000002L});

}