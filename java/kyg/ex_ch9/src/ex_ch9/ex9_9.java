package ex_ch9;
import java.util.Scanner;
class myChar{
	
	char ch;
}
public class ex9_9 {
	static void swap(myChar a, myChar b){
		char imsi;
		imsi =a.ch;
		a.ch=b.ch;
		b.ch=imsi;	
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		myChar ch1 = new myChar();
		myChar ch2 = new myChar();
		
		System.out.printf("문자1을 입력 : ");
		ch1.ch = (s.nextLine()).charAt(0);
		System.out.printf("문자2을 입력 : ");
		ch2.ch = (s.nextLine()).charAt(0);
		
		swap(ch1,ch2);
		
		System.out.printf("바뀐 문자 ==> %c %c", ch1.ch,ch2.ch);
	}
}
