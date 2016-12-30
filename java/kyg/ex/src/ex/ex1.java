package ex;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ex1 {
	static int n[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //각버튼의 몇번 눌럿는지 세는 배열
	static int re = 0;  //연속으로 눌렀을때 기억해주는 변수

	static class MYGUI extends JFrame {
		MYGUI() {
			// 윈도우 창에서 오른쪽위의 x버튼을 누르면 프로그램이 종료하게 된다.
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			// 윈도우창 제목 설정
			setTitle("GUI; 바탕색 변하기");

			// GridLayout으로 3행3열로 버튼 출력
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
					//짝수번 눌렀을때는 자기 색깔이 바탕색이 된다.
					if (n[0] % 2 == 0) {
						c.setBackground(new Color(0, 0, 0));
						n[0]++;
						re = n[0];
						//다른 열을 초기화
						for (int i = 0; i < 9; i++) {
							n[i] = 0;
						}
						//자기 버튼수는 기억해둔다.
						n[0] = re;
					} 
					//홀수번 눌렀을때는 바탕색이 하얀색이 된다.
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
			
			//버튼1~8까지는 버튼 0과 똑같은 알고리즘.
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

			setSize(500, 500); // 윈도우창 크기
			setVisible(true); // 윈도우 화면에 출력
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new MYGUI();
	}

}
