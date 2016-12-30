package traffic_lights;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class MyPanel extends JPanel implements ActionListener{ //ActionListener����ϴ� �г��� �����
	private int light_count = 0;
	public MyPanel(){
		setLayout(new BorderLayout()); //��ư �׸��� ���
		JButton b = new JButton("Traffic light Turn on");  //Traffic light Turn on ���� ���� B��ư�� �����.
		b.addActionListener(this); //�̺�Ʈ �߻�
		add(b,BorderLayout.SOUTH); //�ؿ��ʿ� ��ư����
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.drawOval(100, 100, 100, 100); //�ȿ� ������� ���׸���
		g.drawOval(100, 200, 100, 100);	//�ȿ� ������� ���׸���
		g.drawOval(100, 300, 100, 100);	//�ȿ� ������� ���׸���
		if(light_count == 1){
			g.setColor(Color.RED);       //G��������
			g.fillOval(100,100,100,100); 	//�ȿ� ����ִ� ���׸���
		}
		if(light_count == 2){
			g.setColor(Color.YELLOW);	//G��������
			g.fillOval(100,200,100,100);}	//�ȿ� ����ִ� ���׸���
		if(light_count == 3){
			g.setColor(Color.GREEN);	//G��������
			g.fillOval(100,300,100,100);}	//�ȿ� ����ִ� ���׸���
	}
	
	public void actionPerformed( ActionEvent e){
		if(light_count == 3)light_count = 0;	//LIGHT_COUNT �� �ø��鼭 IF ���� �ٸ��� �����Ѵ�.
		light_count++;
		repaint(); //�θ������� �ٽ� �׸���
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
