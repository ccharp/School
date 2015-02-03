import java.io.*;
import org.antlr.runtime.*;
import org.antlr.runtime.debug.DebugEventSocketProxy;


public class __Test__ {

    public static void main(String args[]) throws Exception {
        Lab6Lexer lex = new Lab6Lexer(new ANTLRFileStream("/users/109/c/ccharpen/EECS_665/labs/lab6/lab6/output/__Test___input.txt", "UTF8"));
        CommonTokenStream tokens = new CommonTokenStream(lex);

        Lab6Parser g = new Lab6Parser(tokens, 49100, null);
        try {
            g.expr();
        } catch (RecognitionException e) {
            e.printStackTrace();
        }
    }
}