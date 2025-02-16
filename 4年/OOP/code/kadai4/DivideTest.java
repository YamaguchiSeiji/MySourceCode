class DivideTest{
	public static void main(String[] args){
		if(args.length < 2){
			System.out.println("Error");
			System.exit(1);
		}

		try{			
			int x = (Integer.parseInt(args[0]));
			int y = (Integer.parseInt(args[1]));
			System.out.println(x / y);
		} catch (ArithmeticException e){
			System.out.println("算術計算に例外が発生しました.");
			System.exit(1);
		} catch (NumberFormatException e){
			System.out.println("入力の形式が正しくありません.");
			System.exit(1);
		}

	}
}
