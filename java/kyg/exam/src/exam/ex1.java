package exam;
interface Animal{
	abstract void bear();	
}
interface Fish{
	abstract void swim();	
}

class Whale implements Animal, Fish{
	public void bear(){
		System.out.println("���� ������ �����ϴ�.");		
	}
	public void swim(){
		System.out.println("������ ���ġ�� �����Դϴ�.");		
	}
	
}
public class ex1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Whale tank1 = new Whale();
		tank1.bear();
		tank1.swim();
	}

}
