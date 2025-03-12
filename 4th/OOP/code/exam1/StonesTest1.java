class StonesTest1 {
	public static void main(String[] args) {
		Stones stones = new Stones();	
		System.out.println(stones);
		System.out.println();

		stones.show();
		System.out.println("take(2): "+ stones.take(2));
		stones.show();
		System.out.println("take(4): "+ stones.take(4));
		stones.show();
		System.out.println("take(3): "+ stones.take(3));
		stones.show();
		System.out.println("take(3): "+ stones.take(3));
		stones.show();
	}
}
