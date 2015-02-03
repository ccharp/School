import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;
import javax.swing.*;

public class RPS extends Component{

	public void loadImages(Image rock, Image paper, Image scissor){
		BufferedImage img = null;
		try {
    	img = ImageIO.read(new File("strawberry.jpg"));
		} catch (IOException e) {
		}
	}

	public void paint(Graphics g, Image img){
		g.drawImage(img, 0, 0, null);
	}
	
	public static void main(String[] args){
		Image img;
		loadImages(img, null, null);
		
		JFrame f = new JFrame("tes test");

		f.addWindowListener(new WindowAdapter(){
				public void windowClosing(WindowEvent e){
					System.exit(0);
				}
			});
	
		f.add(img);
		f.pack();
		f.setVisible(true);
	}
}
