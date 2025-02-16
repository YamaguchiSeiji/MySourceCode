abstract class Figure {
	private char character;

	Figure(char c){
		character = c;
	}

	public char getCharacter(){
		return character;
	}

	public abstract void draw();
}
