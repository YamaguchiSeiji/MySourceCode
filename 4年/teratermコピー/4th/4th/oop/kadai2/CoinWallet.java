class CoinWallet{
	private int coin100;
	private int coin10;

	CoinWallet(int coin100, int coin10){
		this.coin100 = coin100;
		this.coin10 = coin10;
	}

	void show(){
		System.out.println(sum() +"Yen (100:" + coin100 + ", 10:" + coin10 + ")");
	}

	int sum(){
		return coin10 * 10 + coin100 * 100;	
	}

	void transferTo(CoinWallet toCw){
		toCw.coin100 += coin100;
		toCw.coin10 += coin10;
		coin100 = 0;
		coin10 = 0;
	}

	boolean hasMoreMoneyThan(CoinWallet targetCw){
		if(sum() > targetCw.sum()){
			return true;
		} else {
			return false;
		}
	}

	void exchange(CoinWallet targetCw){
		for(int i = targetCw.coin100; i > 0; i--){
			if(coin10 >= 10 && targetCw.coin100 >= 1){
				targetCw.coin100--;
				targetCw.coin10 += 10;
				coin100++;
				coin10 -=10;
			} else {
				break;
			}
		}
	}
}
