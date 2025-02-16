class Game{
	private Player[] players;
	private Board board;

	Game(Player p1, Player p2){
		players = new Player[2];
		players[0] = p1;
		players[1] = p2;
		board = new Board();
	}

	void start(){
		System.out.println("<< Tic-Tac-Toe >>");
		System.out.println(players[0].getName() + " vs " + players[1].getName());
		int i = 0;
		while(true){
			System.out.println(players[i].getName() + "'s turn.");	
			System.out.println();
			board.display();
			System.out.println();
			System.out.println("Stone: " + board.CHAR_STONES[i]);
			System.out.println();
			for(int j = 0; j < board.STONE_NUM; j++){
				System.out.print(j);
				if(j % 3 == 2){
					System.out.println();
				}
			}
			System.out.println();
			int loc = players[i].getNextLocation(board, i);

			if(board.put(loc, i) == false){
				System.out.println("Not Available!!");
				System.out.println("------------------------");
				continue;
			}
			if(board.checkWin(i)){
				System.out.println();
				board.display();
				System.out.println();
				System.out.println(players[i].getName() + " Win!!");
				break;
			}
			if(board.checkDraw()){
				System.out.println();
				board.display();
				System.out.println("\nDraw!!");
				break;
			}
			System.out.println("------------------------");
			System.out.println();
			if(i == 0){
				i++;
			} else {
				i = 0;	
			}
		}
	}
}
