class HumanPlayerTest {
	public static void main(String[] args) {
		Player p1 = new HumanPlayer("Alice");
		System.out.println(p1);
		Board board = new Board();
		int loc = p1.getNextLocation(board, 0);
		board.put(loc, 0);
		board.show();
	}
}
