package ex14;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.*;

import javax.swing.*;
public class ex14_progress {
	static class MyGUI extends JFrame implements Runnable{
		JProgressBar bar1,bar2,bar3;
		MyGUI(){
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setTitle("¿¬½À");
			this.setLayout(new GridLayout(3,1,10,10));
			
			bar1 = new JProgressBar();
			bar1.setValue(50);
			
			bar1.setStringPainted(true);
			
			bar2 = new JProgressBar();
			bar2.setValue(10);
			bar2.setStringPainted(true);
			
			bar3 = new JProgressBar();
			bar3.setValue(30);
			bar3.setStringPainted(true);
			
			
			MyGUI.this.add(bar1);
			MyGUI.this.add(bar2);
			MyGUI.this.add(bar3);
			setSize(512,256);
			setVisible(true);		
		}
		@Override
		public void run() {
			// TODO Auto-generated method stub
			for (int i = 0; i<100; i++){
				try{
					Thread.sleep(100);;
					bar1.setValue(bar1.getValue()+1);
					bar2.setValue(bar1.getValue()+3);
					bar3.setValue(bar1.getValue()+2);
					Random a = new Random();
					Random b = new Random();
					Random c = new Random();
					
					bar1.setForeground( new Color(a.nextInt(255),b.nextInt(255),c.nextInt(255)) );
					bar2.setForeground(new Color(b.nextInt(255),c.nextInt(255),a.nextInt(255)));
					bar3.setForeground(new Color(c.nextInt(255),a.nextInt(255),b.nextInt(255)));
				}
				catch(Exception e){}
			}
			
			
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyGUI mygui = new MyGUI();
		Thread th = new Thread(mygui);
		th.start();
	}

}
