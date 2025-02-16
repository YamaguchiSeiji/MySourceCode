import java.util.Random;

class Card {
	Random rand = new Random();
	private Type type;
	private int number;
	private String red    = "\u001b[00;31m";
    private String green  = "\u001b[00;32m";
    private String cyan   = "\u001b[00;36m";   
    private String end    = "\u001b[00m";
	private String color;

	Card(){
		switch(rand.nextInt(3)){
			case 0:
				type = Type.FIRE;
				color = red;
				break;
			case 1:
				type = Type.WATER;
				color = cyan;
				break;
			case 2:
				type = Type.GRASS;
				color = green;
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

	String getColor(){
		return color;
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
		switch(number){
			case 1:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    ***      |\n" +
			   	"|      *      |\n" +
			   	"|      *      |\n" +
			   	"|      *      |\n" +
			   	"|      *      |\n" +
			   	"|      *      |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 2:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|    *****    |\n" +
			   	"|   *         |\n" +
			   	"|   *         |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 3:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 4:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|             |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|             |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 5:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|   *         |\n" +
			   	"|   *         |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 6:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|   *         |\n" +
			   	"|   *         |\n" +
			   	"|    *****    |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 7:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|             |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 8:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|    *****    |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			case 9:
				return color + 
			   	"---------------\n" + 
			   	"|             |\n" +
			   	"|    *****    |\n" +
			   	"|   *     *   |\n" +
			   	"|   *     *   |\n" +
			   	"|    *****    |\n" +
			   	"|         *   |\n" +
			   	"|         *   |\n" +
			   	"|    *****    |\n" +
			   	"|             |\n" +
			   	"---------------\n" +
			   	end;
			default:
				return "ERROR";
		}
	}
}
