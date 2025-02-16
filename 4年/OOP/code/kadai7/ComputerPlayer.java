import java.util.Scanner;
import java.util.Random;

class ComputerPlayer extends Player{
	
	ComputerPlayer(String name){
		super(name);
	}

	@Override
	int getNextLocation(Board board, int playerNum){
		/*
		0 1 2
		3 4 5
		6 7 8
		*/
		Random rand = new Random();
		int willWin = -1;
		int willLose = -1;
		while(true){
			int locnum = rand.nextInt(9);
			if(board.getStone(4) == -1){
				return 4;
			}
			
			willWin = -1;
			willLose = -1;

			for(int i = 0; i < 9; i+=3){
				if(board.getStone(0+i) == board.getStone(1+i) && board.getStone(0+i) != -1 && board.getStone(2+i) == -1){
					if(board.getStone(0+i)==playerNum){
						willWin = 2+i;
					} else {
						willLose = 2+i;
					}
				} else if(board.getStone(1+i) == board.getStone(2+i) && board.getStone(1+i) != -1 && board.getStone(0+i) == -1){
					if(board.getStone(1+i)==playerNum){
						willWin = 0+i;
					} else {
						willLose = 0+i;
					}
				} else if(board.getStone(0+i) == board.getStone(2+i) && board.getStone(2+i) != -1 && board.getStone(1+i) == -1){
					if(board.getStone(0+i)==playerNum){
						willWin = 1+i;
					} else {
						willLose = 1+i;
					}
				} else {
					locnum = rand.nextInt(9);
				}
			}

			for(int i = 0; i < 3; i++){
				if(board.getStone(0+i) == board.getStone(3+i) && board.getStone(0+i) != -1 && board.getStone(6+i) == -1){
					if(board.getStone(0+i)==playerNum){
						willWin = 6+i;
					} else {
						willLose = 6+i;
					}
				} else if(board.getStone(3+i) == board.getStone(6+i) && board.getStone(3+i) != -1 && board.getStone(0+i) == -1){
					if(board.getStone(3+i)==playerNum){
						willWin = 0+i;
					} else {
						willLose = 0+i;
					}
				} else if(board.getStone(0+i) == board.getStone(6+i) && board.getStone(6+i) != -1 && board.getStone(3+i) == -1){
					if(board.getStone(0+i)==playerNum){
						willWin = 3+i;
					} else {
						willLose = 3+i;
					}
				} else {
					locnum = rand.nextInt(9);
				}
			}
			
			if(board.getStone(0) == board.getStone(4) && board.getStone(0) != -1 && board.getStone(8) == -1){
				if(board.getStone(0)==playerNum){
					willWin = 8;
				} else {
					willLose = 8;
				}
			} else if(board.getStone(4) == board.getStone(8) && board.getStone(4) != -1 && board.getStone(0) == -1){
				if(board.getStone(4)==playerNum){
					willWin = 0;
				} else {
					willLose = 0;
				}
			} else if(board.getStone(0) == board.getStone(8) && board.getStone(8) != -1 && board.getStone(4) == -1){
				if(board.getStone(0)==playerNum){
					willWin = 4;
				} else {
					willLose = 4;
				}
			} else {
				locnum = rand.nextInt(9);
			}

			if(board.getStone(2) == board.getStone(4) && board.getStone(2) != -1 && board.getStone(6) == -1){
				if(board.getStone(2)==playerNum){
					willWin = 6;
				} else {
					willLose = 6;
				}
			} else if(board.getStone(4) == board.getStone(6) && board.getStone(4) != -1 && board.getStone(2) == -1){
				if(board.getStone(4)==playerNum){
					willWin = 2;
				} else {
					willLose = 2;
				}
			} else if(board.getStone(2) == board.getStone(6) && board.getStone(6) != -1 && board.getStone(4) == -1){
				if(board.getStone(2)==playerNum){
					willWin = 4;
				} else {
					willLose = 4;
				}
			} else {
				if(board.getStone(0) == -1 || board.getStone(2) == -1 ||  board.getStone(6) == -1 ||  board.getStone(8) == -1){
					int[] cornerNum = {0, 2, 6, 8};
					locnum = cornerNum[rand.nextInt(4)];
				} else {
					locnum = rand.nextInt(9);
				}
			}
			
			if(willWin != -1){
				return willWin;
			} else if(willLose != -1){
				return willLose;
			}
		
			if(board.getStone(locnum) != -1){
				continue;
			} 
			return locnum;
		}
	}

	public String toString(){
		return getName() + " (Human)";
	}
}
