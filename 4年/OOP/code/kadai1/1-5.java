class Rectangle {
	int height;
	int width;
	char ch;

	int getArea(){
		return height * width;
	}

	void draw(){
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				System.out.print(ch);
			}
			System.out.println("");
		}
	}
}
