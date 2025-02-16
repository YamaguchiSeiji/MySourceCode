import java.util.Scanner;

class SimpleGame {
	public static void main(String args[]){
		Card[] cards = new Card[3];
		Scanner input = new Scanner(System.in);

		for(int i = 0; i < 3; i++){
			cards[i] = new Card();
			System.out.println("(" + (i+1) + ") " + cards[i]);
		}
		System.out.print("Which one?: ");
		int chooseNum = input.nextInt() - 1;
		System.out.println("You: " + cards[chooseNum]);
		
		Card cpu = new Card();
		System.out.println("CPU: " + cpu);
		
		if(cards[chooseNum].isStrongerThan(cpu)){
			System.out.println("You win!");
		} else if(cards[chooseNum].isSameAs(cpu)){
			System.out.println("You tie");
		} else {
			System.out.println("You lose..");
		}
	}
}
