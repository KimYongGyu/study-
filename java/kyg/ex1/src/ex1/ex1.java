package ex1;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class ex1 {
	
	static class MYGUI extends JFrame{
		MYGUI(){
			//윈도우 창에서 오른쪽위의 x버튼을 누르면 프로그램이 종료하게 된다.
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			//윈도우창 제목 설정
			setTitle("GUI; 바탕색 변하기");
			
			//GridLayout으로 3행3열로 버튼 출력
			this.setLayout(new GridLayout(3,3,30,30));
			
			JButton[] btn = new JButton[9];
			
			Container c = this.getContentPane();
			
			for(int i = 0 ; i <9 ; i ++){
				btn[i] = new JButton("btn"+(i+1));
				btn[i].setBackground(new Color(10*i,20*i,25*i));
				btn[i].setBorder(null);
				
				this.add(btn[i]);
			}
			btn[0].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(0,0,0));
				}
			});
			btn[1].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(10,20,25));
				}
			});
			btn[2].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(20,40,50));
				}
			});
			btn[3].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(30,60,75));
				}
			});
			btn[4].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(40,80,100));
				}
			});
			btn[5].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(50,100,125));
				}
			});
			btn[6].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(60,120,150));
				}
			});
			btn[7].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(70,140,175));
				}
			});
			btn[8].addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent arg0) {
					
					c.setBackground(new Color(80,160,200));
				}
			});
			
			setSize(500,500); //윈도우창 크기
			setVisible(true); //윈도우 화면에 출력
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		new MYGUI();
	}

}
