class HighScore {
	private int point;
	private String name;
	HighScore() {
		point = 0;
		name = "NONAME";
	}
	// Add your code

	boolean tryUpdate(int point, String name){
		if(point > this.point){
			this.point = point;
			this.name = name;
			return true;
		} else {
			return false;
		}
	}

	public String toString(){
		return name + "(" + point + ")";
	}
}
