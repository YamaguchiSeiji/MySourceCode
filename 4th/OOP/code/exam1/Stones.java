class Stones {
	private int leftCount;
	private char stoneChar;

	Stones(int count, char stoneChar){
		this.leftCount = count;
		this.stoneChar = stoneChar;
	}

	Stones(){
		this.leftCount = 8;
		this.stoneChar ='*';
	}

	int getLeftCount(){
		return leftCount;
	}

	boolean take(int number){
		if(number > leftCount || number < 1 || number > 3){
			return false;
		}
		leftCount -= number;
		return true;
	}

	int take(){
		int num;
		if(leftCount <= 3){
			num = leftCount;
		} else {
			num = leftCount % 2 + 1;
		}
		take(num);
		return num;
	}

	void show(){
		if(leftCount == 0){
			System.out.println("<0>");
		} else {
			for(int i=0; i < leftCount; i++){
				System.out.print(stoneChar);
			}
			System.out.println(" " + leftCount);
		}
	}

	public String toString(){
		return stoneChar + "(" + leftCount + ")"; 
	}

}
