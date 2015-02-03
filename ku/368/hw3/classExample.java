import javax.swing.JApplet;
import java.awt.Graphics;
import javax.swing.event.*;
import java.awt.event.*;

public class HelloWorld extends JApplet {
    int i = 10;
    public void paint(Graphics g) {
	g.drawRect(0, 0, 
		   getSize().width - 50,
		   getSize().height - 100);
        g.drawString("Hello world (" + i + ")", 10, i);
    }

    public void init() {
	addMouseListener(new MouseInputAdapter() {
		public void mouseClicked(MouseEvent e) {
		    i += 10;
		    repaint(); // requests call to update
		}
	    });
    }
}

