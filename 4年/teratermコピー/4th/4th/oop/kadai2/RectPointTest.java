class RectPointTest{
	public static void main(String[] args){
		RectPoint rp1 = new RectPoint(2, 3);
		System.out.println("x; " + rp1.getX());
		System.out.println("y: " + rp1.getY());
	
		System.out.println("---");
		RectPoint rp2 = new RectPoint(0, 1);
		RectPoint rp3 = new RectPoint(-1, -5);
		System.out.println(rp2);
		System.out.println(rp3);

		System.out.println("---");
		RectPoint rp4 = new RectPoint(2, 8);
		System.out.println(rp4.isSameQuad(rp1));
		System.out.println(rp4.isSameQuad(rp3));

	}
}
