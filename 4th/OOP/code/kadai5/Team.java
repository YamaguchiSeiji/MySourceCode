class Team{
	private String name;
	private BasketballScore score;

	Team(String name, BasketballScore score){
		this.name = name;
		this.score = score;
	}

	int compareScore(Team t){
		return score.getTotal() - t.score.getTotal();
	}
	
	int getScore(){
		return score.getTotal();
	}

	String getName(){
		return name;
	}

	@Override
	public String toString(){
		return "[" + getName() + "] " + score;
	}
}
