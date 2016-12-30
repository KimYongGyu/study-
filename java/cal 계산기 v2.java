package ex1;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyFrame extends JFrame {
	MyListener listener = new MyListener();
	private String strAct;
	private String prestrAct;
	// ����
	private double temp1;
	private double temp2;
	private double result; // ��� ���
	private String operator; // ��ȣ����
	private int flagcal = 0;
	private int flag = 0;
	private int flagop = 0;
	private JTextField f, f1;
	private JButton[] b = new JButton[16];
	private JPanel p;

	public MyFrame() {
		int x = 0;
		int y = 100;
		setSize(300, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Calculator");

		f = new JTextField(10);
		f.addActionListener(listener);
		f1 = new JTextField(10);
		f1.addActionListener(listener);
		p = new JPanel();
		b[0] = new JButton("7");
		b[1] = new JButton("8");
		b[2] = new JButton("9");
		b[3] = new JButton("4");
		b[4] = new JButton("5");
		b[5] = new JButton("6");
		b[6] = new JButton("1");
		b[7] = new JButton("2");
		b[8] = new JButton("3");
		b[9] = new JButton("0");
		b[10] = new JButton("+");
		b[11] = new JButton("-");
		b[12] = new JButton("/");
		b[13] = new JButton("*");
		b[14] = new JButton("=");
		b[15] = new JButton("C");

		p.add(f);
		p.add(f1);
		for (int i = 0; i < 16; i++) {
			p.add(b[i]);
			b[i].addActionListener(listener);
		}
		p.setLayout(null);

		f.setBounds(25, 25, 240, 30); // x,y,����,����
		f1.setBounds(25, 60, 240, 30);

		for (int i = 0; i < 5; i++) {
			b[x].setBounds(25, y, 70, 30);
			b[x + 1].setBounds(110, y, 70, 30);
			b[x + 2].setBounds(195, y, 70, 30);
			x += 3;
			y += 35;
		}
		b[15].setBounds(25, 280, 240, 30);
		f1.setHorizontalAlignment(JTextField.RIGHT);
		add(p);

		setVisible(true);

	}

	public class MyListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			strAct = e.getActionCommand();// ��µȹ�������
			
			// �ѹ��̶� ��������ʾҴٸ� 1 �ߴٸ� 0 : flagop
			// ���� �Ŀ� �ٽ� ���� ���� �ϴ°� �ѹ� 0 ���̻��� ++ flagcal

			if (strAct.equals("+") || strAct.equals("-") || strAct.equals("*") || strAct.equals("/")) {
				operator = strAct;
				flagop++;
				if (flagop == 1 &&flagcal ==0) {
					result =temp1;
				}if (flagop > 1 &&flagcal >=0) {
					switch (operator) {
					case "+":
						result = result + temp2;
						break;
					case "-":
						result = result - temp2;
						break;
					case "*":
						result = result * temp2;
						break;
					case "/":
						result = result / temp2;
						break;
					}
				}
				if(flagop==1&&flagcal>0){
					System.out.print("Ȯ��");
					temp1=result;
				}
				switch (operator) { // �����ڱ�ȣ������

				case "+":
					f.setText(f.getText() + f1.getText() + strAct);
					break;
				case "-":
					f.setText(f.getText() + f1.getText() + strAct);
					break;
				case "*":
					f.setText(f.getText() + f1.getText() + strAct);
					break;
				case "/":
					f.setText(f.getText() + f1.getText() + strAct);
					break;

				} // f1�� �Է¹��� ���ڿ� �����ڸ� ����ϰ���
			} else if (strAct.equals("=")) {
				if ((flagop > 0 && flagcal == 0)||(flagop>1&&flagcal>0)) {
					switch (operator) {
					case "+":
						result = result + temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "-":
						result = result - temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "*":
						result = result * temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "/":
						result = result / temp2;
						f.setText(Double.toString((double) result));
						f1.setText(null);
						flagcal++;
						break;
					}
				} else if((flagop == 0&&flagcal ==0)||(flagop==1&&flagcal>0)) {
					switch (operator) {
					case "+":
						result = temp1 + temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "-":
						result = temp1 - temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "*":
						result = temp1 * temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					case "/":
						result = temp1 / temp2;
						f.setText(Integer.toString((int) result));
						f1.setText(null);
						flagcal++;
						break;
					}
				}
				flagop=0;
				temp1 = 0;
				temp2 = 0;
				
			} else if (strAct.equals("C")) {
				temp1 = 0;
				temp2 = 0;
				result = 0;
				flagop=0;
				flagcal=0;
				operator = null;
				f.setText(null);
				f1.setText(null);
			} else {
				if (operator == null) {
					if (f1.getText() != null) {
						f1.setText(f1.getText() + strAct);
						temp1 = Integer.parseInt(f1.getText());
						flag = 0;
					} else {
						f1.setText("0");

					}
				} else {
					if (flag == 1) {
						f1.setText(f1.getText() + strAct);
						temp2 = Integer.parseInt(f1.getText());
						flag = 0;
					} else if (flag == 0) {
						f1.setText(null);
						f1.setText(f1.getText() + strAct);
						temp2 = Integer.parseInt(f1.getText());
						flag = 1;

					}
				}
			}
			System.out.print("flagcal " + flagcal + "\n");
			System.out.print("flagop " + flagop + "\n");
			System.out.print("result " + result + "\n");
			System.out.print("temp1 " + temp1 + "\n");
			System.out.print("temp2 " + temp2 + "\n\n");
		}
	
	}
}
public class ex1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame f = new MyFrame();

	}

}
