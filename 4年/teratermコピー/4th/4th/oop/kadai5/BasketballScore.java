class BasketballScore {
	private int twoPoint;
	private int threePoint;

	BasketballScore(int twoPoint, int threePoint){
		this.twoPoint = twoPoint;
		this.threePoint = threePoint;
	}

	int getTotal(){
		return twoPoint * 2 + threePoint * 3;
	}
	
	@Override
	public String toString(){
		return "Total: " + getTotal() + " (2pt: " + twoPoint + ", 3pt: " + threePoint + ")";
	}
}
