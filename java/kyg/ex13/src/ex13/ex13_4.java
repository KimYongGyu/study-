package ex13;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ex13_4 {
	
	static class MyGUI extends JFrame {
		MyGUI(){
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setTitle("GUI ����");
			this.setLayout(new FlowLayout());
			JTextField txt = new JTextField(10);
			JTextArea area = new JTextArea(10,10);
			this.add(txt);
			this.add(area);
			
			txt.addKeyListener(new KeyAdapter(){
				public void keyReleased(KeyEvent e){
					
					int key = e.getKeyCode();
					
					if(key ==KeyEvent.VK_ENTER){
						String str = txt.getText();
						
						area.setText(area.getText() + convert(str) + "\n");
						txt.setText("");
						
					}
					
				}
				
			});
			
			
			setSize(200,200);
			setVisible(true);		
		}
	}
	static String convert (String str){
		String result="";
		  
		  for(char c : str.toCharArray()){
		   
		   //�ҹ����� ��� �빮�ڷ� ����
		   if(Character.isLowerCase(c)){
		    result+= toUpperCase(c);
		   //���ĺ��� �ƴѰ�� �׳� ���
		   }else{
		    result+= c;
		   }
		  }
		  return result;
		 }
		 //�Է� ���� ���ڸ� �빮�ڷ� �����Ѵ�.
		 private static char toUpperCase(char c) {
		  return Character.toUpperCase(c);
		 }
		 //�Է¹��� ���ڸ� �ҹ��ڷ� �����Ѵ�.
		 private static char toLowerCase(char c) {
		  return Character.toLowerCase(c);
		 }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyGUI();
	}

}
