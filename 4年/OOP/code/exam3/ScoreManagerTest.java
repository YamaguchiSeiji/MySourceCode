class ScoreManagerTest {
	public static void main(String[] args) {
		ScoreManager sman = new ScoreManager();
		System.out.println(sman);

		sman.add(5, "Alice");
		System.out.println(sman);

		sman.add(10, "Bob");
		sman.add(3, "Chris");
		sman.add(7, "Dan");
		System.out.println(sman);
		System.out.println("Average: " + sman.calcAverage());
	}
}
