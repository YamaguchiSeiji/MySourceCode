class Point{
	int x;
	int y;

	Point(int x, int y){
		this.x = x;
		this.y = y;
	}

	double getDistance(Point p){
		return Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
	}

	void printPoint(Point p){
		System.out.println("x: " + p.x + "y:" +  p.y);
	}
}
