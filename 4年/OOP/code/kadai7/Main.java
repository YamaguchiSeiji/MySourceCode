import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		Player[] p = {new HumanPlayer("???"), new RandomPlayer("???")};

		for(int i = 0; i < 2; i++){
			System.out.println("1: Bob(CPU)");
			System.out.println("2: Mike(Random)");
			System.out.println("3: Anyone(Human)");
			if(i == 0){
				System.out.print("Choose FIRST Player: ");
			} else {
				System.out.print("Choose SECOND Player: ");
			}
			int input = scanner.nextInt();
			if(input == 1){
				p[i] = new ComputerPlayer("Bob");
			} else if(input == 2){
				p[i] = new RandomPlayer("Mike");
			} else if(input == 3){
				System.out.print("What's Player name?: ");
				String name = scanner.next();
				p[i] = new HumanPlayer(name);
			}
		}

		System.out.println(p[0] + " vs " + p[1]);
		System.out.println();
		Game game = new Game(p[0], p[1]);
		game.start();
	}
}
