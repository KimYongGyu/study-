package kyg;

public class ex {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int a=6;
		for(int i = 1 ; i <5;i++){
			
			for(int j = 0 ; j <i; j++){
			System.out.print("*");
			}
			for(int q= 0; q<a;q	++){
				System.out.print(" ");
			}
				
			for(int j = 0 ; j <i; j++){
				System.out.print("*");
				}
			
			System.out.print("\n");
			a-=2;
		}
		int b=2;
		for(int i = 3 ; i >0;i--){
			
			for(int j = 0 ; j <i; j++){
			System.out.print("*");
			}
			for(int q= 0; q<b;q	++){
				System.out.print(" ");
			}
				
			for(int j = 0 ; j <i; j++){
				System.out.print("*");
				}
			
			System.out.print("\n");
			b+=2;
		}
		
		
	}

}
