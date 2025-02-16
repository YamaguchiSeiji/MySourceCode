class ScoreManager {
	private int totalPoints;
	private int count;
	private HighScore highScore;
	
	ScoreManager() {
		this.totalPoints = 0;
		count = 0;
		highScore = new HighScore();
	}
	
	void add(int point, String name){
		totalPoints += point;
		count++;
		highScore.tryUpdate(point, name);

	}

	double calcAverage(){
		return (double)totalPoints / count;
	}

	@Override
	public String toString(){
		return "total: " + totalPoints + ", count : " + count + ", high score: " + highScore;
	}

}


