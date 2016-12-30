package ex1;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class ex1 {
	
	static class MYGUI extends JFrame{
		MYGUI(){
			//������ â���� ���������� x��ư�� ������ ���α׷��� �����ϰ� �ȴ�.
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			//������â ���� ����
			setTitle("GUI; ������ ���ϱ�");
			
			//GridLayout���� 3��3���� ��ư ���
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
			
			setSize(500,500); //������â ũ��
			setVisible(true); //������ ȭ�鿡 ���
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		new MYGUI();
	}

}
