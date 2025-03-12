class TripleTest{
	public static void main(String[] args) {
		System.out.println("[maxメソッドの確認]");
		Triple t1 = new Triple();
		t1.set(1, 2, 3);
		t1.show();
		System.out.println("最大値: " + t1.max());
		t1.set(1, 3, 3);
		t1.show();
		System.out.println("最大値: " + t1.max());
		t1.set(3, 3, 3);
		t1.show();
		System.out.println("最大値: " + t1.max());
		t1.set(2, 2, 3);
		t1.show();
		System.out.println("最大値: " + t1.max());

		System.out.println("[hasPairメソッドの確認]");
		t1.set(1, 2, 3);
		t1.show();
		System.out.println("2つ以上同じか: " + t1.hasPair());
		t1.set(1, 1, 2);
		t1.show();
		System.out.println("2つ以上同じか: " + t1.hasPair());
		t1.set(1, 1, 1);
		t1.show();
		System.out.println("2つ以上同じか: " + t1.hasPair());
		t1.set(1, 2, 1);
		t1.show();
		System.out.println("2つ以上同じか: " + t1.hasPair());
		t1.set(2, 1, 1);
		t1.show();
		System.out.println("2つ以上同じか: " + t1.hasPair());
		
		System.out.println("[isAllSameメソッドの確認]");
		t1.set(1, 2, 3);
		t1.show();
		System.out.println("すべて同じか: " + t1.isAllSame());
		t1.set(1, 1, 2);
		t1.show();
		System.out.println("すべて同じか: " + t1.isAllSame());
		t1.set(1, 1, 1);
		t1.show();
		System.out.println("すべて上同じか: " + t1.isAllSame());
		t1.set(1, 2, 1);
		t1.show();
		System.out.println("すべて上同じか: " + t1.isAllSame());
		t1.set(2, 1, 1);
		t1.show();
		System.out.println("すべて上同じか: " + t1.isAllSame());
		
		System.out.println("[addメソッドの確認]");
		Triple t2 = new Triple();
		t1.set(1, 2, 3);
		t1.show();
		t2.set(4, 5, 6);
		t2.show();
		t1.add(t2);
		t1.show();
		System.out.println("");

		t1.show();
		t2.set(-7, -8, -9);
		t2.show();
		t1.add(t2);
		t1.show();
	}
}
