package traffic_lights;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class MyPanel extends JPanel implements ActionListener{ //ActionListener사용하는 패널을 사용함
	private int light_count = 0;
	public MyPanel(){
		setLayout(new BorderLayout()); //버튼 그리는 방법
		JButton b = new JButton("Traffic light Turn on");  //Traffic light Turn on 글을 쓰는 B버튼을 만든다.
		b.addActionListener(this); //이벤트 발생
		add(b,BorderLayout.SOUTH); //밑에쪽에 버튼생성
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.drawOval(100, 100, 100, 100); //안에 색깔없는 원그리기
		g.drawOval(100, 200, 100, 100);	//안에 색깔없는 원그리기
		g.drawOval(100, 300, 100, 100);	//안에 색깔없는 원그리기
		if(light_count == 1){
			g.setColor(Color.RED);       //G색깔지정
			g.fillOval(100,100,100,100); 	//안에 색깔넣는 원그리기
		}
		if(light_count == 2){
			g.setColor(Color.YELLOW);	//G색깔지정
			g.fillOval(100,200,100,100);}	//안에 색깔넣는 원그리기
		if(light_count == 3){
			g.setColor(Color.GREEN);	//G색깔지정
			g.fillOval(100,300,100,100);}	//안에 색깔넣는 원그리기
	}
	
	public void actionPerformed( ActionEvent e){
		if(light_count == 3)light_count = 0;	//LIGHT_COUNT 를 늘리면서 IF 문을 다르게 들어가게한다.
		light_count++;
		repaint(); //부를때마다 다시 그리기
	}
}

public class graphics extends JFrame {
	public graphics() {
		setTitle("Graphics");
		setSize(500, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		MyPanel p = new MyPanel();
		setVisible(true);
		add(p);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		graphics frame = new graphics();
	}

}
