class BoardTest2 {
	public static void main(String[] args) {
	int[][] locs = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}, {2, 3, 6}};
	for (int[] loc: locs) { //「拡張for」を使用している
			Board board = new Board();
			for (int i = 0; i < 3; i++)
				board.put(loc[i], 0);
			board.show();
			System.out.println(board.checkWin(0));
			System.out.println("-------------------");
		}
	}
}

