import java.util.Timer;
import java.util.TimerTask;

import javax.swing.*;
import javax.swing.JPanel;
import java.awt.event.*;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics.*;
class MyPanel extends JPanel{
	private int x =0;
	private int y =0;
	int dir = 0;
	public MyPanel(){
		Timer m_timer = new Timer();
		TimerTask m_task = new TimerTask(){

			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(dir == 1) y-=10;
				else if(dir == 2) y+=10;
				else if(dir == 3) x-=10;
				else if(dir == 4) x+=10;
				repaint(); //�ٽñ׸���  paintComponent() �ٽý���
			}
			};
			m_timer.schedule(m_task, 0,500);
		addKeyListener(new KeyListener(){  //Ű���� �Է�ó��

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				int Keycode = e.getKeyCode();
				switch(Keycode){
				case KeyEvent.VK_UP :            dir=1;  break;
				case KeyEvent.VK_DOWN :       dir=2; break;
				case KeyEvent.VK_LEFT :         dir=3;  break;
				case KeyEvent.VK_RIGHT :       dir=4;  break;
				
				}
			
			}

			@Override
			public void keyReleased(KeyEvent e) {}

			@Override
			public void keyTyped(KeyEvent e) {}
			});
		//Ű �Է¹ޱ� ���� 2���� �Է����ؾ���
		this.requestFocus();
		setFocusable(true);
	}
	@Override
	protected void paintComponent(Graphics g){  //�θ��� ���  1.ó����  �۵�2.  repaint()�ҷ����� 3. �������� ����������
		super.paintComponent(g);
		
		g.setColor(Color.GREEN);
		g.fillRect(200 + x, 200 + y, 100, 100);
	}
}
public class graphics extends JFrame {
	public graphics() {
		setSize(500, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		cMyTimer mt = new graphics();
	}
}
