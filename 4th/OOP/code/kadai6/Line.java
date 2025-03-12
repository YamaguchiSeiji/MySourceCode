class Line extends Figure{
	int len;

	Line(char c, int len){
		super(c);
		this.len = len;
	}

	@Override
	public void draw(){
		for(int i = 0; i < len; i++){
			System.out.print(getCharacter());
		}
		System.out.println();
	}

	public String toString(){
		return "Line(" + getCharacter() + ", " + len + ")";
	}
}
