// $ANTLR 3.4 Lab6.g 2012-10-30 23:03:01



import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class Lab6Parser extends Parser {
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


    public Lab6Parser(TokenStream input) {
        this(input, new RecognizerSharedState());
    }
    public Lab6Parser(TokenStream input, RecognizerSharedState state) {
        super(input, state);
    }

    public String[] getTokenNames() { return Lab6Parser.tokenNames; }
    public String getGrammarFileName() { return "Lab6.g"; }


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
    // Lab6.g:64:1: top returns [double v] : e= expr ;
    public final double top() throws RecognitionException {
        double v = 0.0;


        double e =0.0;


        try {
            // Lab6.g:65:2: (e= expr )
            // Lab6.g:65:4: e= expr
            {
            pushFollow(FOLLOW_expr_in_top288);
            e=expr();

            state._fsp--;


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
        return v;
    }
    // $ANTLR end "top"



    // $ANTLR start "expr"
    // Lab6.g:68:1: expr returns [double v] : e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )* ;
    public final double expr() throws RecognitionException {
        double v = 0.0;


        double e =0.0;

        double e1 =0.0;

        double e2 =0.0;


        try {
            // Lab6.g:69:2: (e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )* )
            // Lab6.g:69:4: e= exprMult ( PLUS e1= exprMult | MINUS e2= exprMult )*
            {
            pushFollow(FOLLOW_exprMult_in_expr308);
            e=exprMult();

            state._fsp--;


            v = e;

            // Lab6.g:70:4: ( PLUS e1= exprMult | MINUS e2= exprMult )*
            loop1:
            do {
                int alt1=3;
                int LA1_0 = input.LA(1);

                if ( (LA1_0==PLUS) ) {
                    alt1=1;
                }
                else if ( (LA1_0==MINUS) ) {
                    alt1=2;
                }


                switch (alt1) {
            	case 1 :
            	    // Lab6.g:70:5: PLUS e1= exprMult
            	    {
            	    match(input,PLUS,FOLLOW_PLUS_in_expr316); 

            	    pushFollow(FOLLOW_exprMult_in_expr320);
            	    e1=exprMult();

            	    state._fsp--;


            	    v += e1;

            	    }
            	    break;
            	case 2 :
            	    // Lab6.g:71:5: MINUS e2= exprMult
            	    {
            	    match(input,MINUS,FOLLOW_MINUS_in_expr328); 

            	    pushFollow(FOLLOW_exprMult_in_expr332);
            	    e2=exprMult();

            	    state._fsp--;


            	    v -= e2;

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return v;
    }
    // $ANTLR end "expr"



    // $ANTLR start "exprMult"
    // Lab6.g:74:1: exprMult returns [double v] : m1= exprFunc ( MULT m2= exprFunc | DIV m3= exprFunc | POW m4= exprFunc )* ;
    public final double exprMult() throws RecognitionException {
        double v = 0.0;


        double m1 =0.0;

        double m2 =0.0;

        double m3 =0.0;

        double m4 =0.0;


        try {
            // Lab6.g:75:2: (m1= exprFunc ( MULT m2= exprFunc | DIV m3= exprFunc | POW m4= exprFunc )* )
            // Lab6.g:75:4: m1= exprFunc ( MULT m2= exprFunc | DIV m3= exprFunc | POW m4= exprFunc )*
            {
            pushFollow(FOLLOW_exprFunc_in_exprMult355);
            m1=exprFunc();

            state._fsp--;


            v = m1;

            // Lab6.g:76:4: ( MULT m2= exprFunc | DIV m3= exprFunc | POW m4= exprFunc )*
            loop2:
            do {
                int alt2=4;
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

                switch (alt2) {
            	case 1 :
            	    // Lab6.g:76:5: MULT m2= exprFunc
            	    {
            	    match(input,MULT,FOLLOW_MULT_in_exprMult363); 

            	    pushFollow(FOLLOW_exprFunc_in_exprMult367);
            	    m2=exprFunc();

            	    state._fsp--;


            	    v *= m2;

            	    }
            	    break;
            	case 2 :
            	    // Lab6.g:77:5: DIV m3= exprFunc
            	    {
            	    match(input,DIV,FOLLOW_DIV_in_exprMult375); 

            	    pushFollow(FOLLOW_exprFunc_in_exprMult380);
            	    m3=exprFunc();

            	    state._fsp--;


            	    v /= m3;

            	    }
            	    break;
            	case 3 :
            	    // Lab6.g:78:5: POW m4= exprFunc
            	    {
            	    match(input,POW,FOLLOW_POW_in_exprMult388); 

            	    pushFollow(FOLLOW_exprFunc_in_exprMult393);
            	    m4=exprFunc();

            	    state._fsp--;


            	    v = Math.pow(v, m4);

            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }

        finally {
        	// do for sure before leaving
        }
        return v;
    }
    // $ANTLR end "exprMult"



    // $ANTLR start "exprFunc"
    // Lab6.g:82:1: exprFunc returns [double v] : (f1= numExp | ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )* );
    public final double exprFunc() throws RecognitionException {
        double v = 0.0;


        double f1 =0.0;

        double f2 =0.0;

        double f3 =0.0;

        double f4 =0.0;

        double f5 =0.0;


        try {
            // Lab6.g:83:2: (f1= numExp | ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )* )
            int alt4=2;
            int LA4_0 = input.LA(1);

            if ( (LA4_0==BINNUM||LA4_0==DECFRAC||LA4_0==DECNUM||LA4_0==HEXNUM||LA4_0==OCTNUM||LA4_0==24) ) {
                alt4=1;
            }
            else if ( (LA4_0==EOF||LA4_0==COS||LA4_0==DIV||(LA4_0 >= LOG && LA4_0 <= MULT)||(LA4_0 >= PLUS && LA4_0 <= TAN)||LA4_0==25) ) {
                alt4=2;
            }
            else {
                NoViableAltException nvae =
                    new NoViableAltException("", 4, 0, input);

                throw nvae;

            }
            switch (alt4) {
                case 1 :
                    // Lab6.g:83:4: f1= numExp
                    {
                    pushFollow(FOLLOW_numExp_in_exprFunc420);
                    f1=numExp();

                    state._fsp--;


                    v = f1;

                    }
                    break;
                case 2 :
                    // Lab6.g:85:4: ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )*
                    {
                    // Lab6.g:85:4: ( COS f2= numExp | SIN f3= numExp | TAN f4= numExp | LOG f5= numExp )*
                    loop3:
                    do {
                        int alt3=5;
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

                        switch (alt3) {
                    	case 1 :
                    	    // Lab6.g:85:5: COS f2= numExp
                    	    {
                    	    match(input,COS,FOLLOW_COS_in_exprFunc432); 

                    	    pushFollow(FOLLOW_numExp_in_exprFunc436);
                    	    f2=numExp();

                    	    state._fsp--;


                    	    v = Math.cos(f2);

                    	    }
                    	    break;
                    	case 2 :
                    	    // Lab6.g:86:5: SIN f3= numExp
                    	    {
                    	    match(input,SIN,FOLLOW_SIN_in_exprFunc444); 

                    	    pushFollow(FOLLOW_numExp_in_exprFunc448);
                    	    f3=numExp();

                    	    state._fsp--;


                    	    v = Math.sin(f3);

                    	    }
                    	    break;
                    	case 3 :
                    	    // Lab6.g:87:5: TAN f4= numExp
                    	    {
                    	    match(input,TAN,FOLLOW_TAN_in_exprFunc456); 

                    	    pushFollow(FOLLOW_numExp_in_exprFunc460);
                    	    f4=numExp();

                    	    state._fsp--;


                    	    v = Math.tan(f4);

                    	    }
                    	    break;
                    	case 4 :
                    	    // Lab6.g:88:5: LOG f5= numExp
                    	    {
                    	    match(input,LOG,FOLLOW_LOG_in_exprFunc468); 

                    	    pushFollow(FOLLOW_numExp_in_exprFunc472);
                    	    f5=numExp();

                    	    state._fsp--;


                    	    v = Math.log(f5);

                    	    }
                    	    break;

                    	default :
                    	    break loop3;
                        }
                    } while (true);


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
        return v;
    }
    // $ANTLR end "exprFunc"



    // $ANTLR start "numExp"
    // Lab6.g:91:1: numExp returns [double v] : (b= BINNUM |h= HEXNUM |d= DECNUM |df= DECFRAC |o= OCTNUM | '(' e= expr ')' );
    public final double numExp() throws RecognitionException {
        double v = 0.0;


        Token b=null;
        Token h=null;
        Token d=null;
        Token df=null;
        Token o=null;
        double e =0.0;


        try {
            // Lab6.g:92:2: (b= BINNUM |h= HEXNUM |d= DECNUM |df= DECFRAC |o= OCTNUM | '(' e= expr ')' )
            int alt5=6;
            switch ( input.LA(1) ) {
            case BINNUM:
                {
                alt5=1;
                }
                break;
            case HEXNUM:
                {
                alt5=2;
                }
                break;
            case DECNUM:
                {
                alt5=3;
                }
                break;
            case DECFRAC:
                {
                alt5=4;
                }
                break;
            case OCTNUM:
                {
                alt5=5;
                }
                break;
            case 24:
                {
                alt5=6;
                }
                break;
            default:
                NoViableAltException nvae =
                    new NoViableAltException("", 5, 0, input);

                throw nvae;

            }

            switch (alt5) {
                case 1 :
                    // Lab6.g:92:4: b= BINNUM
                    {
                    b=(Token)match(input,BINNUM,FOLLOW_BINNUM_in_numExp495); 

                    v = Integer.parseInt((b!=null?b.getText():null).substring(2, (b!=null?b.getText():null).length()), 2);

                    }
                    break;
                case 2 :
                    // Lab6.g:93:4: h= HEXNUM
                    {
                    h=(Token)match(input,HEXNUM,FOLLOW_HEXNUM_in_numExp504); 

                    v = Integer.parseInt((h!=null?h.getText():null).substring(2, (h!=null?h.getText():null).length()), 16);

                    }
                    break;
                case 3 :
                    // Lab6.g:94:4: d= DECNUM
                    {
                    d=(Token)match(input,DECNUM,FOLLOW_DECNUM_in_numExp513); 

                    v = Integer.parseInt((d!=null?d.getText():null));

                    }
                    break;
                case 4 :
                    // Lab6.g:95:4: df= DECFRAC
                    {
                    df=(Token)match(input,DECFRAC,FOLLOW_DECFRAC_in_numExp522); 

                    v = Double.parseDouble((df!=null?df.getText():null));

                    }
                    break;
                case 5 :
                    // Lab6.g:96:4: o= OCTNUM
                    {
                    o=(Token)match(input,OCTNUM,FOLLOW_OCTNUM_in_numExp531); 

                    v = Integer.parseInt((o!=null?o.getText():null).substring(1, (o!=null?o.getText():null).length()), 8);

                    }
                    break;
                case 6 :
                    // Lab6.g:97:4: '(' e= expr ')'
                    {
                    match(input,24,FOLLOW_24_in_numExp538); 

                    pushFollow(FOLLOW_expr_in_numExp542);
                    e=expr();

                    state._fsp--;


                    match(input,25,FOLLOW_25_in_numExp544); 

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
        return v;
    }
    // $ANTLR end "numExp"

    // Delegated rules


 

    public static final BitSet FOLLOW_expr_in_top288 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_exprMult_in_expr308 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_PLUS_in_expr316 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_exprMult_in_expr320 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_MINUS_in_expr328 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_exprMult_in_expr332 = new BitSet(new long[]{0x0000000000088002L});
    public static final BitSet FOLLOW_exprFunc_in_exprMult355 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_MULT_in_exprMult363 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_exprFunc_in_exprMult367 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_DIV_in_exprMult375 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_exprFunc_in_exprMult380 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_POW_in_exprMult388 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_exprFunc_in_exprMult393 = new BitSet(new long[]{0x0000000000110802L});
    public static final BitSet FOLLOW_numExp_in_exprFunc420 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_COS_in_exprFunc432 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc436 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_SIN_in_exprFunc444 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc448 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_TAN_in_exprFunc456 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc460 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_LOG_in_exprFunc468 = new BitSet(new long[]{0x0000000001042520L});
    public static final BitSet FOLLOW_numExp_in_exprFunc472 = new BitSet(new long[]{0x0000000000604042L});
    public static final BitSet FOLLOW_BINNUM_in_numExp495 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_HEXNUM_in_numExp504 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_DECNUM_in_numExp513 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_DECFRAC_in_numExp522 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_OCTNUM_in_numExp531 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_24_in_numExp538 = new BitSet(new long[]{0x0000000001756D60L});
    public static final BitSet FOLLOW_expr_in_numExp542 = new BitSet(new long[]{0x0000000002000000L});
    public static final BitSet FOLLOW_25_in_numExp544 = new BitSet(new long[]{0x0000000000000002L});

}