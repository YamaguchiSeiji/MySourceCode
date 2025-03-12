class CoinWalletTest{
	public static void main(String[] args){
		// cw1.coin100 = 2; // コンパイルできない
		// System.out.println(cw1.coin10); // コンパイルできない
		CoinWallet cw1 = new CoinWallet(2, 3);
		System.out.println(cw1.sum()); //「230」
		cw1.show(); //「230Yen (100:2, 10:3)」
		CoinWallet cw2 = new CoinWallet(1, 5);
		System.out.println(cw2.hasMoreMoneyThan(cw1)); //「false」
		cw2.transferTo(cw1); // cw2 の中身をすべて cw1 に移す
		cw1.show(); //「380Yen (100:3, 10:8)」
		cw2.show(); //「0Yen (100:0, 10:0)」
		CoinWallet cw3 = new CoinWallet(1, 35);
		CoinWallet cw4 = new CoinWallet(2, 1);
		cw3.exchange(cw4);
		cw3.show(); //「450Yen (100:3, 10:15)」
		cw4.show(); //「210Yen (100:0, 10:21)」
	}
}
