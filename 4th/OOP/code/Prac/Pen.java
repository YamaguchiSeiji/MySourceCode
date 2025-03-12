class Pen{
	private char character;

	Pen(char character){
		this.character = character;
	}

	Pen(){
		this.character = '#';
	}

	char getCharacter(){
		return character;
	}

	void setCharacter(char c){
		character = c;
	}

	void draw(int len){
		for(int i = 0; i < len; i++){
			System.out.print(character);
		}
		System.out.println();
	}

	void draw(){
		System.out.println(character);
	}

	public String toString(){
		return "Pen:" + character;
	}
}
