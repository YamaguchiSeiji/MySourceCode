import java.util.Scanner;

class HumanPlayer extends Player{
	
	HumanPlayer(String name){
		super(name);
	}

	@Override
	int getNextLocation(Board board, int playerNum){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Input location Number: ");
		int locnum = scanner.nextInt();
		return locnum;
	}

	public String toString(){
		return getName() + " (Human)";
	}
}
