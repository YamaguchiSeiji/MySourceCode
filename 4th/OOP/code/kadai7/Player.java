abstract class Player {
	private String name; // プレイヤの名前

	Player(String name) {
		this.name = name;
	}

	String getName() {
		return name;
	}

	abstract int getNextLocation(Board board, int playerNum); // 次に石を打つ位置を返す

}
