class SimplePlayerTest {
	public static void main(String[] args){
		JankenPlayer jp = new SimplePlayer("Alice");
		for(int i = 0; i < 5; i++){
			jp.setNextHand();
			System.out.println(jp);
		}
	}
}
