class Square {
	private int size;

	Square(){
		this.size = 5;
	}

	void setSize(int size) throws InvailSizeException{
		if(size <= 0){
			throw new InvailSizeException("不正な値です.");
		}
		this.size = size;
	}

	void draw(){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				System.out.print("#");
			}
			System.out.println();
		}
	}
}
