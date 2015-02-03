import javax.swing.JApplet;
import java.awt.Graphics;
import javax.swing.event.*;
import java.awt.event.*;
import java.util.Random;
import java.lang.*;



public class Renderer extends JApplet{
    int human = 1;
	int bot = 0;
	boolean execute = false;
	char botChoice; 
	String outcome;

    public void paint(Graphics g) {
		super.paint(g);
		//g.drawRect(0, 0, getSize().width - 50, getSize().height - 100);
		g.drawString("click once for rock, twice for paper, or three  for scissors.", 10, 10);
		g.drawString("	Your bot opponent will choose at random." , 10, 25); 
		g.drawString("	Right Click to begin the game.", 10, 40);
   		g.drawString("Choice: " + human, 10, 55);

		if(execute == true)
		{	
			g.drawString(outcome + ". Bot: " + bot + ". You: " + human + ".", 10, 75);
			execute = false;
		}

		//this.repaint();
    }

    public void init() {
	addMouseListener(new MouseInputAdapter() {
		public void mouseClicked(MouseEvent e) {
			if(e.getButton() == MouseEvent.BUTTON1){
		    	human++;
				if(human > 3)
				{		
					human = 1;
				}
			}
			else if(e.getButton() == MouseEvent.BUTTON3){
				Random rand = new Random();
				bot = rand.nextInt(4);

				//determine winner
				if((human == 1 && bot == 2) || (human == 2 && bot == 3) || (human == 3 && bot == 1))
				{
					outcome = "Bot wins";
				}		
				else if(bot == human)
				{
					outcome = "Tie";
				}
				else 
				{
					outcome = "You win!";
				}
		
				execute = true;
			}

		    repaint(); // requests call to update
		}
	    });
    }
}

