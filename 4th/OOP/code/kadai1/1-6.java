class Triple{
	int n[] = new int[3];

	void set(int num1, int num2, int num3){
		n[0] = num1;
		n[1] = num2;
		n[2] = num3;
	}

	void show(){
		System.out.println(n[0] + "-" + n[1] + "-" + n[2]);
	}
	
	int max(){
		int max = n[0];
		for(int i = 0; i < 3; i++){
			if(max < n[i]){
				max = n[i];
			}
		}
		return max;
	}

	boolean hasPair(){
		if(n[0] == n[1] || n[1] == n[2] || n[0] == n[2]){
			return true;
		} else {
			return false;
		}
	}

	boolean isAllSame(){
		if(n[0] == n[1] && n[1] == n[2]){
			return true;
		} else {
			return false;
		}
	}

	void add(Triple t){
		n[0] += t.n[0];
		n[1] += t.n[1];
		n[2] += t.n[2];
	}
}
