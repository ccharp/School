import javax.swing.JApplet;
import java.awt.*;
import javax.swing.event.*;
import java.awt.event.*;
import java.util.Random;
import java.lang.*;
import java.util.*;

public class SnakeP extends JApplet
{
	LinkedList<Point> snake; //  = new LinkedList();
    Point apple; // = new Point ( (int)(Math.random() * 500), (int)(Math.random() * 500) );
    int score = 0;
    
    public void paint( Graphics g )
    {
        super.paint(g);

        g.drawString( "Score" + score, 200, 30);
        
        for( int i = 0; i < snake.size(); i++ )
        {
            g.drawString( "X", snake.get(i).x, snake.get(i).y );
        }
        
        g.drawString( Integer.toString( snake.size() ), 91, 91);
        
        checkBounds( g );
        checkBody( g );
        checkApple( g );
    }

    public void growSnake()
    {
        Point fst = snake.get(0);
        Point snd = snake.get(1);
    
        Point head = snake.getFirst();
        
        if( fst.x > snd.x )
        {       
            snake.add(0, new Point(head.x + 1, head.y) ); // Insert element as new head
        } 
        else if( fst.x < snd.x ) 
        {
            snake.add(0, new Point(head.x - 1, head.y) );
        } 
        else if( fst.y > snd.y ) 
        {
            snake.add(0, new Point(head.x, head.y + 1) );
        }   
        else if( fst.y < snd.y ) 
        {
            snake.add(0, new Point(head.x, head.y - 1) );
        } 
    }

    public void advSnake( Point advP )
    {
        Point newSeg = new Point( snake.getFirst().x  + advP.x, snake.getFirst().y + advP.y );
        snake.addFirst( newSeg );    
        snake.pollLast();
    }

    public void checkBounds( Graphics g )
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
    } 

    public void restart()
    {
        snake = new LinkedList();
        
    }
    
    public void init()
    {
        snake = new LinkedList();
        apple = new Point( (int)(Math.random() * 500), (int)(Math.random() * 500) );
        snake.add( new Point(10, 10) );
        snake.add( new Point(10, 20) ); 

        setFocusable( true );

        addKeyListener( new KeyAdapter() 
            {
                public void keyTyped( KeyEvent e)
                {
                    score++;
                    if( e.getKeyCode() == KeyEvent.VK_UP )
                    {
                        score++;
                        advSnake( new Point(0, -10) );
                    } 
                     if( e.getKeyCode() == KeyEvent.VK_DOWN )
                    {
                        advSnake( new Point(0, 10) );
                    }
                    if( e.getKeyCode() == KeyEvent.VK_RIGHT )
                    {
                        advSnake( new Point(10, 0) );
                    }
                    if( e.getKeyCode() == KeyEvent.VK_END )
                    {
                       advSnake( new Point(-10, 0) );
                    }

                    requestFocus();
                    repaint();
                } 
            });

        addMouseListener(new MouseInputAdapter() 
            {
		        public void mouseClicked(MouseEvent e) 
                {
			        if(e.getButton() == MouseEvent.BUTTON1)
                    {
                        advSnake( new Point(0, 10) );
		            	repaint(); // requests call to update
		            }
                }
	        });
    } 
}





