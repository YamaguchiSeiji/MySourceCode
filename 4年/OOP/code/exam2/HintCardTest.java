class HintCardTest {
	public static void main(String[] args) {
		HintCard hc = new HintCard(309);
		System.out.println(hc);
		hc.show();
		System.out.println("hc.getHint(0)?: " + hc.getHint(0));
		System.out.println("hc.getHint(5)?: " + hc.getHint(5));
		System.out.println("hc.getHint(new NumberCard(320))?: "
			+ hc.getHint(new NumberCard(320)));
		System.out.println("hc.getHint(new NumberCard(123))?: "
			+ hc.getHint(new NumberCard(123)));
		System.out.println("hc.getHint(new NumberCard(309))?: "
			+ hc.getHint(new NumberCard(309)));
		System.out.println("hc.check(309))?: " + hc.check(309));
		System.out.println("hc.check(123))?: " + hc.check(123));
		hc.flip();
		hc.show();
		System.out.println(hc);
	}
}
