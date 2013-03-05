// $ANTLR 3.4 /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g 2012-10-30 22:56:29

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked"})
public class Lab6Lexer extends Lexer {
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
    // delegators
    public Lexer[] getDelegates() {
        return new Lexer[] {};
    }

    public Lab6Lexer() {} 
    public Lab6Lexer(CharStream input) {
        this(input, new RecognizerSharedState());
    }
    public Lab6Lexer(CharStream input, RecognizerSharedState state) {
        super(input,state);
    }
    public String getGrammarFileName() { return "/users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g"; }

    // $ANTLR start "T__24"
    public final void mT__24() throws RecognitionException {
        try {
            int _type = T__24;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:2:7: ( '(' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:2:9: '('
            {
            match('('); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__24"

    // $ANTLR start "T__25"
    public final void mT__25() throws RecognitionException {
        try {
            int _type = T__25;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:3:7: ( ')' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:3:9: ')'
            {
            match(')'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "T__25"

    // $ANTLR start "BIN"
    public final void mBIN() throws RecognitionException {
        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:33:13: ( '0' .. '1' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '1') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "BIN"

    // $ANTLR start "OCT"
    public final void mOCT() throws RecognitionException {
        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:34:13: ( '0' .. '7' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '7') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "OCT"

    // $ANTLR start "DEC"
    public final void mDEC() throws RecognitionException {
        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:35:13: ( '0' .. '9' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DEC"

    // $ANTLR start "HEX"
    public final void mHEX() throws RecognitionException {
        try {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:36:13: ( ( '0' .. '9' | 'A' .. 'F' | 'a' .. 'f' ) )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            {
            if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'F')||(input.LA(1) >= 'a' && input.LA(1) <= 'f') ) {
                input.consume();
            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;
            }


            }


        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "HEX"

    // $ANTLR start "PLUS"
    public final void mPLUS() throws RecognitionException {
        try {
            int _type = PLUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:38:6: ( '+' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:38:8: '+'
            {
            match('+'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "PLUS"

    // $ANTLR start "MINUS"
    public final void mMINUS() throws RecognitionException {
        try {
            int _type = MINUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:39:7: ( '-' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:39:9: '-'
            {
            match('-'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "MINUS"

    // $ANTLR start "MULT"
    public final void mMULT() throws RecognitionException {
        try {
            int _type = MULT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:40:6: ( '*' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:40:8: '*'
            {
            match('*'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "MULT"

    // $ANTLR start "DIV"
    public final void mDIV() throws RecognitionException {
        try {
            int _type = DIV;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:41:5: ( '/' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:41:7: '/'
            {
            match('/'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DIV"

    // $ANTLR start "POW"
    public final void mPOW() throws RecognitionException {
        try {
            int _type = POW;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:42:5: ( '^' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:42:7: '^'
            {
            match('^'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "POW"

    // $ANTLR start "LOG"
    public final void mLOG() throws RecognitionException {
        try {
            int _type = LOG;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:44:5: ( 'l' 'o' 'g' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:44:7: 'l' 'o' 'g'
            {
            match('l'); 

            match('o'); 

            match('g'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "LOG"

    // $ANTLR start "SIN"
    public final void mSIN() throws RecognitionException {
        try {
            int _type = SIN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:45:5: ( 's' 'i' 'n' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:45:7: 's' 'i' 'n'
            {
            match('s'); 

            match('i'); 

            match('n'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "SIN"

    // $ANTLR start "COS"
    public final void mCOS() throws RecognitionException {
        try {
            int _type = COS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:46:5: ( 'c' 'o' 's' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:46:7: 'c' 'o' 's'
            {
            match('c'); 

            match('o'); 

            match('s'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "COS"

    // $ANTLR start "TAN"
    public final void mTAN() throws RecognitionException {
        try {
            int _type = TAN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:47:5: ( 't' 'a' 'n' )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:47:7: 't' 'a' 'n'
            {
            match('t'); 

            match('a'); 

            match('n'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "TAN"

    // $ANTLR start "BINNUM"
    public final void mBINNUM() throws RecognitionException {
        try {
            int _type = BINNUM;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:49:8: ( '0' 'b' ( BIN )* )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:49:10: '0' 'b' ( BIN )*
            {
            match('0'); 

            match('b'); 

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:49:16: ( BIN )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( ((LA1_0 >= '0' && LA1_0 <= '1')) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '1') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "BINNUM"

    // $ANTLR start "HEXNUM"
    public final void mHEXNUM() throws RecognitionException {
        try {
            int _type = HEXNUM;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:50:8: ( '0' 'x' ( HEX )* )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:50:10: '0' 'x' ( HEX )*
            {
            match('0'); 

            match('x'); 

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:50:16: ( HEX )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( ((LA2_0 >= '0' && LA2_0 <= '9')||(LA2_0 >= 'A' && LA2_0 <= 'F')||(LA2_0 >= 'a' && LA2_0 <= 'f')) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'F')||(input.LA(1) >= 'a' && input.LA(1) <= 'f') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "HEXNUM"

    // $ANTLR start "DECNUM"
    public final void mDECNUM() throws RecognitionException {
        try {
            int _type = DECNUM;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:51:8: ( '1' .. '9' ( DEC )* )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:51:10: '1' .. '9' ( DEC )*
            {
            matchRange('1','9'); 

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:51:20: ( DEC )*
            loop3:
            do {
                int alt3=2;
                int LA3_0 = input.LA(1);

                if ( ((LA3_0 >= '0' && LA3_0 <= '9')) ) {
                    alt3=1;
                }


                switch (alt3) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop3;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DECNUM"

    // $ANTLR start "DECFRAC"
    public final void mDECFRAC() throws RecognitionException {
        try {
            int _type = DECFRAC;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:52:9: ( ( DEC )* '.' ( DEC )* )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:52:11: ( DEC )* '.' ( DEC )*
            {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:52:11: ( DEC )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( ((LA4_0 >= '0' && LA4_0 <= '9')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);


            match('.'); 

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:52:18: ( DEC )*
            loop5:
            do {
                int alt5=2;
                int LA5_0 = input.LA(1);

                if ( ((LA5_0 >= '0' && LA5_0 <= '9')) ) {
                    alt5=1;
                }


                switch (alt5) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop5;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DECFRAC"

    // $ANTLR start "OCTNUM"
    public final void mOCTNUM() throws RecognitionException {
        try {
            int _type = OCTNUM;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:53:8: ( '0' ( OCT )* )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:53:10: '0' ( OCT )*
            {
            match('0'); 

            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:53:13: ( OCT )*
            loop6:
            do {
                int alt6=2;
                int LA6_0 = input.LA(1);

                if ( ((LA6_0 >= '0' && LA6_0 <= '7')) ) {
                    alt6=1;
                }


                switch (alt6) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '7') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    break loop6;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "OCTNUM"

    // $ANTLR start "WS"
    public final void mWS() throws RecognitionException {
        try {
            int _type = WS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:57:4: ( ( ' ' | '\\t' | '\\r' | '\\n' )+ )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:57:6: ( ' ' | '\\t' | '\\r' | '\\n' )+
            {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:57:6: ( ' ' | '\\t' | '\\r' | '\\n' )+
            int cnt7=0;
            loop7:
            do {
                int alt7=2;
                int LA7_0 = input.LA(1);

                if ( ((LA7_0 >= '\t' && LA7_0 <= '\n')||LA7_0=='\r'||LA7_0==' ') ) {
                    alt7=1;
                }


                switch (alt7) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '\t' && input.LA(1) <= '\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt7 >= 1 ) break loop7;
                        EarlyExitException eee =
                            new EarlyExitException(7, input);
                        throw eee;
                }
                cnt7++;
            } while (true);


             _channel=HIDDEN; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "WS"

    // $ANTLR start "DECIMAL"
    public final void mDECIMAL() throws RecognitionException {
        try {
            int _type = DECIMAL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:60:9: ( ( DEC )+ )
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:60:11: ( DEC )+
            {
            // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:60:11: ( DEC )+
            int cnt8=0;
            loop8:
            do {
                int alt8=2;
                int LA8_0 = input.LA(1);

                if ( ((LA8_0 >= '0' && LA8_0 <= '9')) ) {
                    alt8=1;
                }


                switch (alt8) {
            	case 1 :
            	    // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:
            	    {
            	    if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
            	        input.consume();
            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;
            	    }


            	    }
            	    break;

            	default :
            	    if ( cnt8 >= 1 ) break loop8;
                        EarlyExitException eee =
                            new EarlyExitException(8, input);
                        throw eee;
                }
                cnt8++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        	// do for sure before leaving
        }
    }
    // $ANTLR end "DECIMAL"

    public void mTokens() throws RecognitionException {
        // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:8: ( T__24 | T__25 | PLUS | MINUS | MULT | DIV | POW | LOG | SIN | COS | TAN | BINNUM | HEXNUM | DECNUM | DECFRAC | OCTNUM | WS | DECIMAL )
        int alt9=18;
        alt9 = dfa9.predict(input);
        switch (alt9) {
            case 1 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:10: T__24
                {
                mT__24(); 


                }
                break;
            case 2 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:16: T__25
                {
                mT__25(); 


                }
                break;
            case 3 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:22: PLUS
                {
                mPLUS(); 


                }
                break;
            case 4 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:27: MINUS
                {
                mMINUS(); 


                }
                break;
            case 5 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:33: MULT
                {
                mMULT(); 


                }
                break;
            case 6 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:38: DIV
                {
                mDIV(); 


                }
                break;
            case 7 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:42: POW
                {
                mPOW(); 


                }
                break;
            case 8 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:46: LOG
                {
                mLOG(); 


                }
                break;
            case 9 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:50: SIN
                {
                mSIN(); 


                }
                break;
            case 10 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:54: COS
                {
                mCOS(); 


                }
                break;
            case 11 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:58: TAN
                {
                mTAN(); 


                }
                break;
            case 12 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:62: BINNUM
                {
                mBINNUM(); 


                }
                break;
            case 13 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:69: HEXNUM
                {
                mHEXNUM(); 


                }
                break;
            case 14 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:76: DECNUM
                {
                mDECNUM(); 


                }
                break;
            case 15 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:83: DECFRAC
                {
                mDECFRAC(); 


                }
                break;
            case 16 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:91: OCTNUM
                {
                mOCTNUM(); 


                }
                break;
            case 17 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:98: WS
                {
                mWS(); 


                }
                break;
            case 18 :
                // /users/109/c/ccharpen/EECS_665/labs/lab6/lab6/Lab6.g:1:101: DECIMAL
                {
                mDECIMAL(); 


                }
                break;

        }

    }


    protected DFA9 dfa9 = new DFA9(this);
    static final String DFA9_eotS =
        "\14\uffff\1\24\1\26\4\uffff\1\24\1\27\1\uffff\1\26\2\uffff";
    static final String DFA9_eofS =
        "\30\uffff";
    static final String DFA9_minS =
        "\1\11\13\uffff\2\56\4\uffff\2\56\1\uffff\1\56\2\uffff";
    static final String DFA9_maxS =
        "\1\164\13\uffff\1\170\1\71\4\uffff\2\71\1\uffff\1\71\2\uffff";
    static final String DFA9_acceptS =
        "\1\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\7\1\10\1\11\1\12\1\13\2\uffff"+
        "\1\17\1\21\1\14\1\15\2\uffff\1\20\1\uffff\1\16\1\22";
    static final String DFA9_specialS =
        "\30\uffff}>";
    static final String[] DFA9_transitionS = {
            "\2\17\2\uffff\1\17\22\uffff\1\17\7\uffff\1\1\1\2\1\5\1\3\1\uffff"+
            "\1\4\1\16\1\6\1\14\11\15\44\uffff\1\7\4\uffff\1\12\10\uffff"+
            "\1\10\6\uffff\1\11\1\13",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "\1\16\1\uffff\10\22\2\23\50\uffff\1\20\25\uffff\1\21",
            "\1\16\1\uffff\12\25",
            "",
            "",
            "",
            "",
            "\1\16\1\uffff\10\22\2\23",
            "\1\16\1\uffff\12\23",
            "",
            "\1\16\1\uffff\12\25",
            "",
            ""
    };

    static final short[] DFA9_eot = DFA.unpackEncodedString(DFA9_eotS);
    static final short[] DFA9_eof = DFA.unpackEncodedString(DFA9_eofS);
    static final char[] DFA9_min = DFA.unpackEncodedStringToUnsignedChars(DFA9_minS);
    static final char[] DFA9_max = DFA.unpackEncodedStringToUnsignedChars(DFA9_maxS);
    static final short[] DFA9_accept = DFA.unpackEncodedString(DFA9_acceptS);
    static final short[] DFA9_special = DFA.unpackEncodedString(DFA9_specialS);
    static final short[][] DFA9_transition;

    static {
        int numStates = DFA9_transitionS.length;
        DFA9_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA9_transition[i] = DFA.unpackEncodedString(DFA9_transitionS[i]);
        }
    }

    class DFA9 extends DFA {

        public DFA9(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 9;
            this.eot = DFA9_eot;
            this.eof = DFA9_eof;
            this.min = DFA9_min;
            this.max = DFA9_max;
            this.accept = DFA9_accept;
            this.special = DFA9_special;
            this.transition = DFA9_transition;
        }
        public String getDescription() {
            return "1:1: Tokens : ( T__24 | T__25 | PLUS | MINUS | MULT | DIV | POW | LOG | SIN | COS | TAN | BINNUM | HEXNUM | DECNUM | DECFRAC | OCTNUM | WS | DECIMAL );";
        }
    }
 

}