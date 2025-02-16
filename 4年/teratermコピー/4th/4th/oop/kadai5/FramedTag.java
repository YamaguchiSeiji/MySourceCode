class FramedTag extends Tag{
	int margin;

	FramedTag(String name, int margin){
		super(name);
		this.margin = margin;
	}
	
	private void printLine(){
		System.out.print("+");
		for(int i = 0; i < margin * 2 + name.length(); i++){
			System.out.print("-");
		}
		System.out.println("+");
	}

	@Override
	void show(){
		printLine();
		System.out.print("|");
		for(int i = 0; i < margin; i++){
			System.out.print(" ");
		}
		System.out.print(name);
		for(int i = 0; i < margin; i++){
			System.out.print(" ");
		}
		System.out.println("|");
		printLine();
	}
}
