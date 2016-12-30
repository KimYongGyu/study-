package javatermproj_2016;


import java.io.*;
import java.util.Stack;
class kygLocation2D	{

	public static int rows;
	public static int cols;
	public kygLocation2D(int r, int c){
		this.rows =r;
		this.cols =c;
	}
	  // ��ġ p�� �ڽ��� �̿����� �˻��ϴ� �Լ�
	boolean isNeighbor(kygLocation2D p){
		return ( (rows==p.rows && ( cols == p.cols-1 || cols == p.cols+1))
				||(cols==p.cols && ( rows == p.rows-1 || rows == p.rows +1)) );
		}
	int getrows() {
		return rows;
	}
	int getcols() {
		return cols;
	}
	

}
class miro {

	public int MAX_STACK_SIZE = 100;
	public static char[][] map =

				  { { 1, 1, 1, 1, 1, 1, 1, 1, },
					{ 8, 0, 1, 0, 0, 0, 1, 1, },
					{ 1, 0, 0, 0, 1, 0, 0, 1, },
					{ 1, 0, 1, 0, 0, 1, 1, 1, },
					{ 1, 0, 1, 1, 0, 1, 1, 1, },
					{ 1, 0, 1, 1, 0, 0, 1, 1, },
					{ 1, 0, 0, 0, 1, 0, 0, 9, },
					{ 1, 1, 1, 1, 1, 1, 1, 1, } };
	
	static boolean isValidLoc(int r, int c) {
		if(r < 0 || c < 0 || r >= 8|| c >= 8) return false;
		else return map[r][c] == 0 || map[r][c] == 9;
	}
	
	public static void FindStartLocation(kygLocation2D location) {
		
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++){
				if (map[i][j] == 8){ 
					location.rows = i;
					location.cols = j;
					break;
				}
			}
		
	}

	public static void printMaze() {
		System.out.print("=========\n");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				switch (map[i][j]) {
				case 1:
					System.out.printf("1");
					break;// ��
				case 2:
					System.out.printf("2");
					break;// ��������
				case 8:
					System.out.printf("8");
					break;// �Ա�
				case 9:
					System.out.printf("9");
					break;// �ⱸ
				case 0:
					System.out.printf("0");
					break;// ����������
				}
			}
		
			System.out.print("\n");
		}
		System.out.print("=========\n");
	}

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		try {
			System.out.print("\t\t2016�⵵ 2�б� �ڹ� ��������Ʈ\n\n");
			// kygLocation2D location = new kygLocation2D();
			Stack<Integer> stack = new Stack<Integer>();
			
			kygLocation2D location= null;
			printMaze();
			FindStartLocation(location);
			stack.add(FindStartLocation(location));
			while(stack.isEmpty() == false){
				kygLocation2D here = null;
				here= stack.pop();
				stack.pop();
				
				int r = location.getrows();
				int c = location.getcols();
				System.out.printf(" (%d, %d)", r,c);
				if(map[r][c] == '9'){
					System.out.printf("�̷�Ž�� ����");
					return;
				}
				else {
					map[r][c] = '.';
					if(isValidLoc(r-1, c)) stack.push(location(r-1, c));
					if(isValidLoc(r+1, c)) stack.push(location(r+1, c));
					if(isValidLoc(r, c-1)) stack.push(location(r, c-1));
					if(isValidLoc(r, c+1)) stack.push(location(r, c+1));
				}
			}
			
		} catch (Exception e) {
			System.out.print("�߻� ���� ==>");
			System.out.print(e.getMessage());
		} finally {
			System.out.print("\n���α׷��� �����մϴ�.");
		}
	}
}