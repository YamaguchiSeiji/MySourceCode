class NumberCard {
	private int number;	// 番号（3桁の整数を想定する）
	private boolean isFront;	// 表向きかどうか

	NumberCard(int number) {
		this.number = number;
		isFront = false;
	}

	int getNumber() {
		return number;
	}

	boolean flip() {
		isFront = !isFront;
		return isFront;
	}

	void show() {
		if (isFront)
			System.out.println("["+String.format("%3d", number)+"]");
		else
			System.out.println("[###]");
	}

	@Override
	public String toString() {
		String s;
		if (isFront)
			s = "front";
		else
			s = "back";
		return "" + number + " (" + s + ")";
	}
}
