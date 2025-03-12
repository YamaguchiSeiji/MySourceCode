class WordTest{
	public static void main(String[] args){
		if(args.length < 1){
			System.out.println("Error");
			System.exit(1);
		}

		String[] suf_es = {"s", "sh", "ch", "x", "o"};
		String[] suf_mo = {"ay", "iy", "uy", "ey", "oy"};
		boolean isNo = true;
		boolean isY = false;

		for(int i=0; i < args.length; i++){
			if(args[i].equals("have")){
				args[i] = "has";
				System.out.println(args[i]);
				continue;
			}

			for(int j=0; j < suf_es.length; j++){
				if(args[i].endsWith(suf_es[j])){
					args[i] += "es";
					isNo = false;
				}
			}

			if(args[i].endsWith("y")){
				isY = true;
				if(isY){
					for(int j=0; j<suf_mo.length; j++){
						if(args[i].endsWith(suf_mo[j])){
							isY = false;
						}
					}
				}
				if(isY){
					args[i] = args[i].substring(0, args[i].length()-1);
					args[i] += "ies";
					isNo = false;
				}
			}

			if(isNo){
				args[i] += "s";
			}

			System.out.println(args[i]);
			isNo = true;
		}
	}
}
