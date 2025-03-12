class Square extends Figure{
	int size;

	Square(char c, int size){
		super(c);
		this.size = size;
	}

	@Override
	public void draw(){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				System.out.print(getCharacter());
			}
			System.out.println();
		}
	}

	public String toString(){
		return "Square(" + getCharacter() + ", " + size + ")";
	}
}
