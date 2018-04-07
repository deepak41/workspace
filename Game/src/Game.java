import java.applet.Applet;
import java.awt.Image;

public class Game extends gameLoop{
	
	public void init(){
		setsize(854, 480);
		Thread th = new Thread(this);
		th.start();
	}
	public void paint(Graphics g){
		g.fillOval(x,y,20,20);
	}
}