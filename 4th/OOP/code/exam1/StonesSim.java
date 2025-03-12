class StonesSim {
	public static void main(String[] args) {
		Stones stones = new Stones(8, '*');
		System.out.println("Initial:");
		stones.show();
		
		int playerNo = 0;
 
		while(true) {
			System.out.println("[CPU" + (playerNo + 1) + "]");
			System.out.println("Taken: " + stones.take());
			stones.show();

			if(stones.getLeftCount() == 0){
				break;
			}

			playerNo = (playerNo + 1) % 2;
		}
		System.out.println("CPU" + (playerNo + 1) + " wins.");
	}
}
