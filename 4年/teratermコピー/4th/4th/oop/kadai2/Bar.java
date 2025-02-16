class Bar {
	int len;
	char pattern;
	
	Bar(){
		len = 1;
		pattern = '-';
	}

	Bar(int n, char c){
		len = n;
		pattern = c;
	}
	
	void draw(){
		for(int i = 0; i < len; i++){
			System.out.print(pattern);
		}
		System.out.println();
	}
	
	void draw(int times){
		for(int i = 0; i < times; i++){
			draw();
		}
	}

	void draw(boolean isvert){
		for(int i = 0; i < len; i++){
			System.out.print(pattern);
			if(isvert){
				System.out.println();
			}
		}
		if(!isvert)
			System.out.println();
	}
}
