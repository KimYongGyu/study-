package ex_ch9;
import java.util.*;

public class ex9_7 {

	static int diff( char a, char b){
		int c;
		int a1 = (int) a;
		int b1 = (int) b;
		c= b1-a1;
		return c;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		char a,b;
		System.out.print("����1�� �Է� : ");
		a = s.next().charAt(0);
		System.out.print("����2�� �Է� : ");
		b = s.next().charAt(0);
		
		System.out.printf("�ι����� ���� ==> %d ",diff(a,b));
	
	}

}
