class HintCard extends NumberCard{
	private int hintCount;
	private int number;
	private boolean isFront;
	private Result result;

	HintCard(int number){
		super(number);
		this.number = number;
		this.isFront = isFront;
		hintCount = 0;
	}

	int getHintCount(){
		return hintCount;
	}

	boolean getHint(int digit){
		String s = ""+number+"";
		int len = s.length();
		hintCount++;
		for(int i=0; i<len; i++){
			char c = s.charAt(i);
			if(digit == c - '0'){
				return true;
			}
		}

		return false;
	}

	Result getHint(NumberCard nc){
		hintCount++;
		if(nc.getNumber() > number){
			return Result.LOW;
		} else if(nc.getNumber() < number){
			return Result.HIGH;
		} else {
			return Result.SAME;
		}
	}

	boolean check(int num){
		if(num == number){
			return true;
		} else {
			return false;
		}
	}

	@Override
	int getNumber(){
		return number;
	}

	boolean flip(){
		isFront = !isFront;
		return isFront;
	}

	void show(){
		if(isFront){
			System.out.println("["+String.format("%3d", number)+"]");
		} else {
			System.out.println("[###]");
		}
	}

	public String toString(){
		String s;
		if(isFront){
			s = "front";
		} else {
			s = "back";
		}

		return number + "(" + s + "), hintCount: " + getHintCount();
	}
}
