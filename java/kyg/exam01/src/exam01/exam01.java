package exam01;
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
			int cnt=0;
			@Override
			public void run() {
				
				dir=cnt%8;
				// TODO Auto-generated method stub
				System.out.printf("%d %d\n", cnt++,dir);
				//if(cnt >= 100) m_timer.cancel(); //10�ʵǸ� Ÿ�̸Ӱ� �װ���
				
				repaint(); //�ٽñ׸���  paintComponent() �ٽý���
			}
			};
			m_timer.schedule(m_task, 0,500);
		
	}
	@Override
	protected void paintComponent(Graphics g){  //�θ��� ���  1.ó����  �۵�2.  repaint()�ҷ����� 3. �������� ����������
		super.paintComponent(g);
		
		g.drawOval(100, 100, 100, 100); //�ȿ� ������� ���׸���
		g.drawOval(100, 200, 100, 100);	//�ȿ� ������� ���׸���
		g.drawOval(100, 300, 100, 100);	//�ȿ� ������� ���׸���
		
		g.drawOval(300, 100, 100, 100); //�ȿ� ������� ���׸���
		g.drawOval(300, 200, 100, 100);	//�ȿ� ������� ���׸���
		g.drawOval(300, 300, 100, 100);	//�ȿ� ������� ���׸���
		
		if(dir==0||dir==1||dir==2){
		g.setColor(Color.RED);	//G��������
		g.fillOval(100,100,100,100);
		}
		if(dir==3||dir==4||dir==5){
			g.setColor(Color.GREEN);	//G��������
			g.fillOval(100,300,100,100);
		}
		if(dir==6){
			g.setColor(Color.YELLOW);	//G��������
			g.fillOval(100,200,100,100);
		}
		if(dir==7){g.setColor(Color.RED);	//G��������
		g.fillOval(100,100,100,100);}
	
		if(dir==1||dir==0){
			g.setColor(Color.GREEN);	//G��������
			g.fillOval(300,300,100,100);}
		if(dir==2){
			g.setColor(Color.YELLOW);	//G��������
			g.fillOval(300,200,100,100);}
		if(dir==3||dir==4||dir==5||dir==6){
			g.setColor(Color.RED);       //G��������
			g.fillOval(300,100,100,100);}

		if(dir==7){
			g.setColor(Color.GREEN);	//G��������
			g.fillOval(300,300,100,100);}
		
	}
	
	
}
public class exam01 extends JFrame {
	public exam01() {
		setSize(500, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		exam01 mt = new exam01();
	}
}
