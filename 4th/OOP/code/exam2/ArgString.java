class ArgString{
	public static void main(String[] args){
		int len = args.length;
		if(len < 1){
			System.out.println("Error");
			return;
		}
		int max = args[0].length();
		for(int i=0; i<len; i++){	
			if(max <= args[i].length()){
				max = args[i].length();
			}
		}

		System.out.println(max);

		for(int i=0; i<len; i++){
			if(max == args[i].length()){
				System.out.println(args[i]);
			}
		}

	}

}
