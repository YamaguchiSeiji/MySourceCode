class JankenSimulator {
	public static void main(String[] args) {

		JankenPlayer jp1 = new SimplePlayer("Alice");
		JankenPlayer jp2 = new RandomPlayer("Bob");
		for(int i = 0; i < 5; i++) {
			jp1.setNextHand();
			System.out.println(jp1);
			jp2.setNextHand();
			System.out.println(jp2);
			System.out.println(jp1.name + " wins?: " + jp1.beats(jp2));
			System.out.println();
		}
	}
}

