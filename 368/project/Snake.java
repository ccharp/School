import javax.swing.JApplet;
import java.awt.Graphics;
import javax.swing.event.*;
import java.awt.event.*;
import java.util.Random;
import java.lang.*;

public class SnakeP extends JApplet
{
	//LinkedList<Point> snake; //  = new LinkedList();
    //Point apple; // = new Point ( (int)(Math.random() * 500), (int)(Math.random() * 500) );
    //int score = 0;
    
    public void paint( Graphics g )
    {
        super.paint(g);

        //g.drawString( "Score" + score, 30, 30);
        
        //for( int i = 0; i < snake.size(); i++ )
       // {
       //     g.drawString( "X", snake.get(i).x, snake.get(i).y );
       // }
        
        g.drawString( "why isnt this pringing" , 20, 20);
        
        //checkBounds( g );
       // checkBody( g );
       // checkApple( g );

        repaint(); 
    }

   /* public void growSnake()
    {
        Point fst = snake.get(0);
        Point snd = snake.get(1);
    
        if( fst.x > snd.x  
    }*/

    /*public void checkBounds( Graphics g )
    {
        if ( snake.get(0).x < 0 || snake.get(0).x > 500
          || snake.get(0).y < 0 || snake.get(0).y > 500 )
        {
            //you lose
        }
    }

    public void checkBody( Graphics g )
    {
        Point head = snake.get(0);
        for( int i = 1; i < snake.size(); i++ )
        {
            if( snake.get(i).x == head.x && snake.get(i).y == head.y )
            {
                //you lose
            }
        }   
    }
    
    public void checkApple( Graphics g )
    {
        if( (snake.get(0).x == apple.x) && (snake.get(0).y == apple.y) )
        {
            score++; 
            apple.x = (int)(Math.random() * 500);
            apple.y = (int)(Math.random() * 500);

            //growSnake(); 
        }
   */ }  

    public void init()
    {
       // snake = new LinkedList();
        //apple = new Point( (int)(Math.random() * 500), (int)(Math.random() * 500) );
        //snake.add( new Point(10, 10) );
        //snake.add( new Point(10, 20) ); 

        addMouseListener(new MouseInputAdapter() 
            {
		        public void mouseClicked(MouseEvent e) 
                {
			        if(e.getButton() == MouseEvent.BUTTON1)
                    {
		            	repaint(); // requests call to update
		            }
                }
	        });
    } 
}









