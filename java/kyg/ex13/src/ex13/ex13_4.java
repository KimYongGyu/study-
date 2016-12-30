package ex13;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ex13_4 {
	
	static class MyGUI extends JFrame {
		MyGUI(){
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setTitle("GUI 연습");
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
		   
		   //소문자일 경우 대문자로 변경
		   if(Character.isLowerCase(c)){
		    result+= toUpperCase(c);
		   //알파벳이 아닌경우 그냥 출력
		   }else{
		    result+= c;
		   }
		  }
		  return result;
		 }
		 //입력 받은 문자를 대문자로 변경한다.
		 private static char toUpperCase(char c) {
		  return Character.toUpperCase(c);
		 }
		 //입력받은 문자를 소문자로 변경한다.
		 private static char toLowerCase(char c) {
		  return Character.toLowerCase(c);
		 }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyGUI();
	}

}
