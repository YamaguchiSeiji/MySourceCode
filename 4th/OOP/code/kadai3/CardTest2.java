class CardTest2{
	public static void main(String[] args){
		Card mine = new Card(Type.FIRE, 5);
		System.out.println("My Card: " + mine);
		System.out.println("Type: " + mine.getType() + ", Number: " + mine.getNumber());
		System.out.println();

		Card[] cards = {
			new Card(Type.GRASS, 8), 
			new Card(Type.WATER, 5),
			new Card(Type.FIRE, 7),
			new Card(Type.FIRE, 5)};
		
		for(int i = 0; i < cards.length; i++){
			Card c = cards[i];
			System.out.println(mine + " is stronger than " + c + "?: " + mine.isStrongerThan(c));
			System.out.println(mine + " is same as " + c + "?: " + mine.isSameAs(c));
			System.out.println();
		}
	}
}
