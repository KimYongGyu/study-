
class Location2D {

	public int row; // ���� ��ġ�� ���ȣ
	public int col; // ���� ��ġ�� ����ȣ

	public Location2D(int r, int c) {
		row = r;
		col = c;
	}

	// ��ġ p�� �ڽ��� �̿����� �˻��ϴ� �Լ�
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
