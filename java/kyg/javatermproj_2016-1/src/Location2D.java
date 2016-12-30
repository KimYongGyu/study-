
class Location2D {

	public int row; // 현재 위치의 행번호
	public int col; // 현재 위치의 열번호

	public Location2D(int r, int c) {
		row = r;
		col = c;
	}

	// 위치 p가 자신의 이웃인지 검사하는 함수
	boolean isNeighbor(Location2D tmp) {
		return ((row == tmp.row && (col == tmp.col - 1 || col == tmp.col + 1))
				|| (col == tmp.col && (row == tmp.row - 1 || row == tmp.row + 1)));
	}

	int recallrow() {
		return row;
	}

	int recallcol() {
		return col;
	}
};
