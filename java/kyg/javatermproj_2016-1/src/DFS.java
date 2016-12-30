import java.util.Stack;

public class DFS {
	
	static int MAZE_SIZE = 8;
	char[][] map = {
		{'1', '1', '1', '1', '1', '1', '1', '1', },
		{'e', '0', '1', '0', '0', '0', '1', '1', },
		{'1', '0', '0', '0', '1', '0', '0', '1', },
		{'1', '0', '1', '0', '0', '1', '1', '1', },
		{'1', '0', '1', '1', '0', '1', '1', '1', },
		{'1', '0', '1', '1', '0', '0', '1', '1', },
		{'1', '0', '0', '0', '1', '0', '0', 'x', },
		{'1', '1', '1', '1', '1', '1', '1', '1', }
	};
	
	boolean isValidLoc(int r, int c) {
		if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
		else return map[r][c] == '0' || map[r][c] == 'x';
	}
	void printMaze(){
		System.out.printf("\n\n");
		for(int i = 0; i<8 ; i++){
			for(int j = 0; j<8 ; j++){
				switch(map[i][j]){
				case '1' : System.out.printf("1"); break;//��
				case '.' : System.out.printf("."); break;//��������
				case 'e' : System.out.printf("e"); break;//�Ա�
				case 'x' : System.out.printf("x"); break;//�ⱸ
				case '0' : System.out.printf("0"); break;//����������
				}
			}
			System.out.printf("\n");
		}
	}
	public DFS() {
		System.out.printf("\n************* [ 2016�⵵ 2�б� �ڹ� ��������Ʈ ] *************\n\n");
		System.out.printf("          2013136025 ����  �̷�ã�� DFS �׽�Ʈ���α׷�\n\n");
		Stack<Location2D> st = new Stack<Location2D>();
		System.out.printf("\n\n======================================\n");
		System.out.printf("  ��ü �̷��� ũ�� = ");
		System.out.printf(" 8 8 \n");
		System.out.printf("======================================\n");

		Location2D entry = new Location2D(1,0);
		st.add(entry);
		int n=0;
		printMaze();
		//���α׷� ����
		while(st.empty() == false) {
			Location2D here = st.pop();
			//������ġ �޾ƿ´�.
			int r = here.row;
			int c = here.col;
			
			if(n<10){
				System.out.printf("(%d,%d) ", r, c);
				n++;
			}
			else{
				System.out.printf("\n");
				n=0;
			}
			//map[r][c]��x�� �����ϸ� ����
			if(map[r][c] == 'x') {
				System.out.printf("�̷� Ž�� ����\n");
				printMaze();
				return;
			}
			//��������ġ Ȯ��
			else {
				map[r][c] = '.';
				if(isValidLoc(r-1, c)) st.add(new Location2D(r-1, c));
				if(isValidLoc(r+1, c)) st.add(new Location2D(r+1, c));
				if(isValidLoc(r, c-1)) st.add(new Location2D(r, c-1));
				if(isValidLoc(r, c+1)) st.add(new Location2D(r, c+1));
			}
			printMaze();
		}
		System.out.printf("�̷�Ž������\n");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DFS TermProject = new DFS();
		
	}

}
