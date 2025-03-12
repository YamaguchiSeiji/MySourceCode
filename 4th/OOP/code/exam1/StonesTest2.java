class StonesTest2 {

	public static void main(String[] args) {
		Stones stones = new Stones(6, 'X');	
		System.out.println(stones);
		System.out.println();

		stones.show();
		System.out.println("take(): "+ stones.take());
		stones.show();
		System.out.println("take(): "+ stones.take());
		stones.show();
		System.out.println("take(): "+ stones.take());
		stones.show();
	}
}
