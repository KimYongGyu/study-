package ex_ch9;
import java.io.*;
public class ex10_8 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		FileReader fReader = new FileReader("C:/Windows/win.ini");
		
		BufferedReader bReader = new BufferedReader(fReader);
		String s=null;
		String str = null;
		
		while((str = bReader.readLine()) != null){
			s= str;
			s=s.toUpperCase();
			System.out.println(s);;
		}
			
		bReader.close();
		fReader.close();
	}

}
