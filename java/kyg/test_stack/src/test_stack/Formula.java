package test_stack;

public class Formula {
	private String exp;
	private int expSize;
	private char testCh, openPair;

	public boolean testPair(String exp){
		this.exp = exp;
		LinkedStack stack = new LinkedStack();
		expSize = this.exp.length();

		for(int i=0; i<expSize; i++){
			testCh = exp.charAt(i);

			switch(testCh){
			case '(' :
			case '[' :
			case '{' :
				stack.push(testCh);
				break;
			case ')' :
			case ']' :
			case '}' :
				if(stack.isEmpty()){
					return false;
				}else{
					openPair = stack.pop();
					if((openPair==')') && (testCh!='(') || 
					   (openPair==']') && (testCh!='[') || 
					   (openPair=='}') && (testCh!='{')){
						return false;

					}else{
						break;
					}
				}
			}
		}

		if(stack.isEmpty()){
			return true;
		}else{
			return false;
		}
	}
	
	public void toPostfix(String infix){
		char testCh;
		exp = infix;
		int expSize = exp.length();
		LinkedStack stack = new LinkedStack();
		String result;
		for(int i=0; i<expSize; i++){
			testCh = exp.charAt(i);
			
			switch(testCh){
			case '0' :
			case '1' :
			case '2' :
			case '3' :
			case '4' :
			case '5' :
			case '6' :
			case '7' :
			case '8' :
			case '9' :
				System.out.print(testCh);
				break;
			case '+' :
			case '-' :
			case '/' :
			case '*' :
				stack.push(testCh);
				break;
			case ')' :
				System.out.print(stack.pop());
				break;
			default:
			}
		}
		
		while(!stack.isEmpty()){
			System.out.print(stack.pop());
		}
	}
}
