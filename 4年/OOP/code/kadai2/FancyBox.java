class FancyBox extends Box{
	boolean fills;
	char character;

	FancyBox(int h, int w, boolean f, char c){
		super(h, w);
		fills = f;
		character = c;
	}

	private void printCharacterLine(){
		for(int i = 0; i < width; i++){
			System.out.print(character);
		}
		System.out.println();
	}

	@Override
	void draw(){
		if(fills){
			for(int i = 0; i < height;  i++){
				for(int j = 0; j < width; j++){
					System.out.print(character);
				}
				System.out.println();
			}
		} else {
			printCharacterLine();
			for(int i = 2; i < height; i++){
				System.out.print(character);
				for(int j = 2; j < width; j++){
					System.out.print(" ");
				}
				System.out.println(character);
			}
			printCharacterLine();
		}
	}
}
