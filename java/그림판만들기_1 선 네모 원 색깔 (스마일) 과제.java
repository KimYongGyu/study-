import java.awt.*;
import javax.swing.*;

class Mypanel extends JPanel {
	public void paintComponent(Graphics g) {
		super.paintComponent(g);/*
		g.setColor(Color.BLUE);
		g.drawLine(10, 20, 110, 20); //���׸��� ��ǥ �׸��� ��ǥ �� �մ� ���׸���
		g.drawRect(30, 30, 100, 100); //�׸�׸��� ��ǥ���� ���� ���̸� �׸��� �׸�
		g.drawOval(30, 30, 100, 100);  //���׸���
		g.drawArc(50, 30, 130, 130, -180, 180);
		g.setColor(Color.RED);  //��������
		g.fillRect(50, 50, 20,20); //�ȿ� ���̵� �׸�*/
		g.setColor(Color.YELLOW);
		g.fillOval(30, 30, 200, 200);;
		
		g.setColor(Color.black);
		g.drawArc(60, 80, 50, 50, 180, -180);
		g.drawArc(150, 80, 50, 50, 180, -180);
		g.drawArc(80, 130, 100, 70, 180, -180);
	}
}

public class graphics extends JFrame {
	public graphics() {
		setTitle("Graphics");
		setSize(500, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Mypanel p = new Mypanel();
		setVisible(true);
		add(p);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		graphics frame = new graphics();
	}

}
