package ex01;
import java.util.Timer;
import java.util.TimerTask;

import java.awt.*;
import javax.swing.*;


import java.awt.event.*;

class MyPanel extends JPanel  { 
															
	MyListener listener = new MyListener();
	static int x = 0;
	static int y = 0;
	private String strAct;
	private JButton[] b = new JButton[4];
	int dir = 0;
	public MyPanel() {
		Timer m_timer = new Timer();
		TimerTask m_task = new TimerTask(){

			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(dir == 1) y-=10;
				else if(dir == 2) y+=10;
				else if(dir == 3) x-=10;
				else if(dir == 4) x+=10;
				repaint(); //다시그리기  paintComponent() 다시실행
			}
			
		};
		m_timer.schedule(m_task, 10,500);
		setLayout(new BorderLayout(10,10));
		b[0] = new JButton("N");
		b[1] = new JButton("E");
		b[2] = new JButton("W");
		b[3] = new JButton("S");
		
		this.add(b[0],BorderLayout.NORTH);
		this.add(b[1],BorderLayout.EAST);
		this.add(b[2],BorderLayout.WEST);
		this.add(b[3],BorderLayout.SOUTH);

		for (int i = 0; i < 4; i++) {
			
			b[i].addActionListener(listener);
		}
		
		setVisible(true);
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.GREEN);
		g.fillRect(200 + x, 200 + y, 100, 100);

	}

	public class MyListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			strAct = e.getActionCommand();
			if (strAct.equals("N")) {
				y -= 10;
				dir=1;
			} else if (strAct.equals("W")) {
				x -= 10;
				dir=3;
			} else if (strAct.equals("E")) {
				x += 10;
				dir=4;
			} else if (strAct.equals("S")) {
				y += 10;
				dir=2;
			}
			repaint(); // 부를때마다 다시 그리기
		}
	}

	
}

public class ex01 extends JFrame {
	public ex01() {
		setSize(500, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		MyPanel p = new MyPanel();
		setVisible(true);
		add(p);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ex01 frame = new ex01();
		
		Timer m_timer = new Timer();
		TimerTask m_task = new TimerTask() {
			int cnt = 0;

			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(cnt >= 10) m_timer.cancel(); //10초되면 타이머가 죽게함
			}
		};
		m_timer.schedule(m_task, 0,1000); //밀리세컨드 3초마다 출력, 1초마다 위에있는코드 반복 
		
	}

}
