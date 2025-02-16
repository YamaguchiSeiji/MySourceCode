class NumberCardTest {
	public static void main(String[] args) {
		NumberCard nc = new NumberCard(125);
		System.out.println(nc);
		nc.show();
		nc.flip();
		System.out.println(nc);
		nc.show();
	}
}
