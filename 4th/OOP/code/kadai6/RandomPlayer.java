import java.util.Random;

class RandomPlayer extends JankenPlayer{
	RandomPlayer(String name){
		super(name);
	}

	@Override
	void setNextHand(){
		Random rand = new Random();
		int num = rand.nextInt(3);
		switch(num){
			case 0:
				hand = Hand.SCISSORS;
				break;
			case 1:
				hand = Hand.ROCK;
				break;
			case 2:
				hand = Hand.PAPER;
				break;
		}
	}
}
