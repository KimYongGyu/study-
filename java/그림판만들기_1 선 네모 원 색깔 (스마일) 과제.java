import java.awt.*;
import javax.swing.*;

class Mypanel extends JPanel {
	public void paintComponent(Graphics g) {
		super.paintComponent(g);/*
		g.setColor(Color.BLUE);
		g.drawLine(10, 20, 110, 20); //선그리기 좌표 그리고 좌표 를 잇는 선그리기
		g.drawRect(30, 30, 100, 100); //네모그리기 좌표에서 넓이 높이를 그리는 네모
		g.drawOval(30, 30, 100, 100);  //원그리기
		g.drawArc(50, 30, 130, 130, -180, 180);
		g.setColor(Color.RED);  //색깔지정
		g.fillRect(50, 50, 20,20); //안에 색이들어간 네모*/
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
