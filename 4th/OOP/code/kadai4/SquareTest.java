class SquareTest {
	public static void main(String[] args) {
		if(args.length < 1) {
			System.out.println("Too Few Arguments.");
			System.exit(0);
		}
		try{
			int size = Integer.parseInt(args[0]);
			Square r = new Square();
			r.setSize(size);
			r.draw();
		} catch(InvailSizeException e){
			System.out.println("サイズ指定が正しくありません.");
			System.exit(0);
		} catch(NumberFormatException e){
			System.out.println("引数が整数ではありません.");
			System.exit(0);
		}

	}
}
