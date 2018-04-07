import java.applet.Applet;

public class gameLoop extends Applet implements Runnable{
	
	public int x, y;
	
	public void run(){
		x=100;
		y=100;
		while(true){
			x++;
			repaint();
			try{
				Thread.sleep(20);
			}
			catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
	
}