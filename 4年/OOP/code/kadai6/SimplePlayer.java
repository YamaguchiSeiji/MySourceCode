class SimplePlayer extends JankenPlayer {
	SimplePlayer(String name) {
		super(name);
	}

	@Override
	void setNextHand() {
		if(hand == Hand.ROCK)
			hand = Hand.SCISSORS;
		else if(hand == Hand.SCISSORS)
			hand = Hand.PAPER;
		else
			hand = Hand.ROCK;
	}
}
