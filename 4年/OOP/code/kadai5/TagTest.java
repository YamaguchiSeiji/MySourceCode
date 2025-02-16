class TagTest{
	public static void main(String[] args){
		Tag t = new Tag("Alice");
		Tag dt = new DecoratedTag("Bob", '#');
		Tag ft1 = new FramedTag("Chris", 0);
		Tag ft2 = new FramedTag("Chris", 3);

		t.show();
		dt.show();
		ft1.show();
		ft2.show();
	}
}
