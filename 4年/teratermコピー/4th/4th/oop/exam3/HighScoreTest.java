class HighScoreTest {
	public static void main(String[] args) {
		HighScore hs = new HighScore();
		System.out.println(hs);
		System.out.println("tryUpdate(1): " + hs.tryUpdate(15, "Thomas"));
		System.out.println(hs);
		System.out.println("tryUpdate(2): " + hs.tryUpdate(12, "Percy"));
		System.out.println(hs);
		System.out.println("tryUpdate(3): " + hs.tryUpdate(15, "Gordon"));
		System.out.println(hs);
		System.out.println("tryUpdate(4): " + hs.tryUpdate(20, "James"));
		System.out.println(hs);
	}
}
