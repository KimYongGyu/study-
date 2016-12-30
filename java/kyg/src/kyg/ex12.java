package kyg;

import java.util.Scanner;
import java.io.*;

public class ex12 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int a, b = 0;
		
		Scanner s = new Scanner(System.in);
		System.out.println("첫번째수를 입력하세요 :");
		a = s.nextInt();

		System.out.println("계산할 연산자를 입력하세요 :");
		char str = (char)System.in.read();
		
		Scanner s1 = new Scanner(System.in);
		System.out.println("두번째수를 입력하세요 :");
		b = s1.nextInt();
		
		int result = 0;
		
		if(str != '+' || str != '-' || str!='*' || str != '/' ||str!='%')
			System.out.printf("연산자를 잘못 입력했습니다. ");
		
		
		if (str == '+') {
			result = a + b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // 결과출력
		} else if (str == '-') {
			result = a - b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // 결과출력
		} else if (str == '*') {
			result = a * b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // 결과출력
		} else if (str == '/') {
			result = a / b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // 결과출력
		} else if (str == '%') {
			result = a % b;
			System.out.printf("%d %c %d = %d%n", a, str, b, result); // 결과출력
		}
		
		
	}

};

