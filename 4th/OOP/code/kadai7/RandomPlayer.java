import java.util.Scanner;
import java.util.Random;

class RandomPlayer extends Player{
	
	RandomPlayer(String name){
		super(name);
	}

	@Override
	int getNextLocation(Board board, int playerNum){
		Random rand = new Random();

		while(true){
			int locnum = rand.nextInt(9);
			if(board.getStone(locnum) == -1){
				return locnum;
			}
		}
	}

	public String toString(){
		return getName() + " (Human)";
	}
}
