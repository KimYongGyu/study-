package kyg;

import java.util.Scanner;
import java.io.*;

public class ex12 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int a, b = 0;
		
		Scanner s = new Scanner(System.in);
		System.out.println("ù��°���� �Է��ϼ��� :");
		a = s.nextInt();

		System.out.println("����� �����ڸ� �Է��ϼ��� :");
		char str = (char)System.in.read();
		
		Scanner s1 = new Scanner(System.in);
		System.out.println("�ι�°���� �Է��ϼ��� :");
		b = s1.nextInt();
		
		int result = 0;
		
		if(str != '+' || str != '-' || str!='*' || str != '/' ||str!='%')
			System.out.printf("�����ڸ� �߸� �Է��߽��ϴ�. ");
		
		
		if (str == '+') {
			result = a + b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // ������
		} else if (str == '-') {
			result = a - b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // ������
		} else if (str == '*') {
			result = a * b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // ������
		} else if (str == '/') {
			result = a / b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // ������
		} else if (str == '%') {
			result = a % b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // ������
		}
		
		
	}

};

