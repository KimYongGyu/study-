package ex;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ex1 {
	static int n[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //����ư�� ��� �������� ���� �迭
	static int re = 0;  //�������� �������� ������ִ� ����

	static class MYGUI extends JFrame {
		MYGUI() {
			// ������ â���� ���������� x��ư�� ������ ���α׷��� �����ϰ� �ȴ�.
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			// ������â ���� ����
			setTitle("GUI; ������ ���ϱ�");

			// GridLayout���� 3��3���� ��ư ���
			this.setLayout(new GridLayout(3, 3, 30, 30));

			JButton[] btn = new JButton[9];

			Container c = this.getContentPane();

			for (int i = 0; i < 9; i++) {
				btn[i] = new JButton("btn" + (i + 1));
				btn[i].setBackground(new Color(10 * i, 20 * i, 25 * i));
				btn[i].setBorder(null);

				this.add(btn[i]);
			}
			btn[0].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					//¦���� ���������� �ڱ� ������ �������� �ȴ�.
					if (n[0] % 2 == 0) {
						c.setBackground(new Color(0, 0, 0));
						n[0]++;
						re = n[0];
						//�ٸ� ���� �ʱ�ȭ
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						//�ڱ� ��ư���� ����صд�.
						n[0] = re;
					} 
					//Ȧ���� ���������� �������� �Ͼ���� �ȴ�.
					else {
						c.setBackground(new Color(255, 255, 255));
						n[0]++;
						re = n[0];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[0] = re;

					}
				}
			});
			
			//��ư1~8������ ��ư 0�� �Ȱ��� �˰���.
			btn[1].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {

					if (n[1] % 2 == 0) {
						c.setBackground(new Color(10, 20, 25));
						n[1]++;
						re = n[1];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[1] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[1]++;
						re = n[1];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[1] = re;
					}
				}
			});
			btn[2].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[2] % 2 == 0) {
						c.setBackground(new Color(20, 40, 50));
						n[2]++;
						re = n[2];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[2] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[2]++;
						re = n[2];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[2] = re;
					}
				}
			});
			btn[3].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[3] % 2 == 0) {
						c.setBackground(new Color(30, 60, 75));
						n[3]++;
						re = n[3];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[3] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[3]++;
						re = n[3];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[3] = re;
					}
				}
			});
			btn[4].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[4] % 2 == 0) {
						c.setBackground(new Color(40, 80, 100));
						n[4]++;
						re = n[4];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[4] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[4]++;
						re = n[4];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[4] = re;
					}
				}
			});
			btn[5].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[5] % 2 == 0) {
						c.setBackground(new Color(50, 100, 125));
						n[5]++;
						re = n[5];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[5] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[5]++;
						re = n[5];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[5] = re;
					}
				}
			});
			btn[6].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[6] % 2 == 0) {
						c.setBackground(new Color(60, 120, 150));
						n[6]++;
						re = n[6];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[6] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[6]++;
						re = n[6];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[6] = re;
					}
				}
			});
			btn[7].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					if (n[7] % 2 == 0) {
						c.setBackground(new Color(70, 140, 175));
						n[7]++;
						re = n[7];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[7] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[7]++;
						re = n[7];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[7] = re;
					}
				}
			});
			btn[8].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {

					if (n[8] % 2 == 0) {
						c.setBackground(new Color(80, 160, 200));
						n[8]++;
						re = n[8];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[8] = re;
					} else {
						c.setBackground(new Color(255, 255, 255));
						n[8]++;
						re = n[8];
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						n[8] = re;
					}
				}
			});

			setSize(500, 500); // ������â ũ��
			setVisible(true); // ������ ȭ�鿡 ���
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new MYGUI();
	}

}
