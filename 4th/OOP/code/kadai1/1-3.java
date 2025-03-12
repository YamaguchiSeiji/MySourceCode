class StringChar {
	public static void main(String[] args){
		if(args.length != 2 || args[0].length() < Integer.parseInt(args[1])){
			System.out.println("入力が不正です");
			System.exit(0);
		}

		int n = Integer.parseInt(args[1]);
		char c = args[0].charAt(n-1);
		System.out.println(c);
	}
}
