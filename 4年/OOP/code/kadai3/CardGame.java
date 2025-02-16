import java.util.Scanner;
import java.util.Random;

class CardGame {
	public static void main(String args[]){
		Card[] cards = new Card[3];
		Card[] cpu = new Card[3];
		Scanner input = new Scanner(System.in);
		Random rand = new Random();
			
		for(int i = 0; i < 3; i++){
			cards[i] = new Card();
			cpu[i] = new Card();
		}

		while(true){
			System.out.println("-----YOUR CARDS-----");
			for(int i = 0; i < 3; i++){
				System.out.println("(" + (i+1) + ") \n" + cards[i]);
			}
			System.out.println("-----CPU CARDS-----");
			for(int i = 0; i < 3; i++){
				System.out.println("(" + (i+1) + ") \n"  + cpu[i]);
			}
			
			System.out.println("1: Fight");
			System.out.println("2: Exchange");
			System.out.print("What will you do?: ");
			int state = input.nextInt();
			if(state == 1){
				System.out.print("Which one?: ");
	
				int chooseNum = input.nextInt() - 1;
				System.out.println("You: \n" + cards[chooseNum]);
			
				int randomNum = rand.nextInt(3);
				System.out.println("CPU: \n" + cpu[randomNum]);
				
				if(cards[chooseNum].isStrongerThan(cpu[randomNum])){
					System.out.println("You win!");
					break;
				} else if(cards[chooseNum].isSameAs(cpu[randomNum])){
					System.out.println("You tie");
				} else {
					System.out.println("You lose..");
					break;
				}
			} else if(state == 2){
				System.out.print("Which one?: ");
				int chooseNum = input.nextInt() - 1;
				cards[chooseNum] = new Card();
			} else {
				System.out.println("ERROR");
			}
		}
	}
}
