class DecoratedTag extends Tag{
	char deco;

	DecoratedTag(String name, char deco){
		super(name);
		this.deco = deco;
	}

	@Override
	void show(){
		System.out.println(deco + " " + name + " " + deco);
	}
}
