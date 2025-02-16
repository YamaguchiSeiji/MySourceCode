import java.util.Random;

class Card {
	Random rand = new Random();
	private Type type;
	private int number;
	
	Card(){
		switch(rand.nextInt(3)){
			case 0:
				type = Type.FIRE;
				break;
			case 1:
				type = Type.WATER;
				break;
			case 2:
				type = Type.GRASS;
				break;
		}
		number = rand.nextInt(9)+1;
	}

	Card(Type type, int number){
		this.type = type;
		this.number = number;
	}

	Type getType(){
		return type;
	}

	int getNumber(){
		return number;
	}
	
	boolean isStrongerThan(Card c){
		if((type == Type.FIRE && c.type == Type.GRASS) ||
			(type == Type.WATER && c.type == Type.FIRE) || 
			(type == Type.GRASS && c.type == Type.WATER) ||
			(type == c.type && number > c.number)){
			return true;
		} else {
			return false;
		}
	}

	boolean isSameAs(Card c){
		if(type == c.type && number == c.number){
			return true;
		} else {
			return false;
		}
	}

	public String toString(){
		return type + " [" + number + "]";
	}
}
