import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class graphics extends JFrame implements MouseListener, MouseMotionListener{
	public graphics() {
		setTitle("Graphics");
		setSize(500, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.addMouseListener(this);;
		panel.addMouseMotionListener(this);
		
		add(panel);
		setVisible(true);
	
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Dragged",e);
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Moved",e);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Clicked( clicks : " + e.getClickCount() + " )",e);
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Entered",e);
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Exited",e);
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Pressed( clicks : " + e.getClickCount() + " )",e);
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		display("Mouse Released( clicks : " + e.getClickCount() + " )",e);
	}
	protected void display(String  s, MouseEvent e){
		System.out.println(s + " X =" + e.getX() + " Y = " + e.getY());
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		graphics frame = new graphics();
	}
}





















