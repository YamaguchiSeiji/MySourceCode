class FigureTest {
	public static void main(String[] args){
		Figure[] figures = {new Line('X', 5),
			new Square('$', 2), new Square('#', 5)};

		for(int i = 0; i < figures.length; i++){
			System.out.println(figures[i]);
			figures[i].draw();
		}
	}
}
