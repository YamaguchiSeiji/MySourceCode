import java.util.Random;
import java.util.Scanner;

class GuessNumber{
	public static void main (String[] args){
		Random rand = new Random();
		Scanner in = new Scanner(System.in);

		int n = rand.nextInt(90) + 10;
		System.out.println(n);
	
		while(true){
			System.out.print("Guess: ");
			int x = in.nextInt();
			if(x > n){
				System.out.println("high");
			} else if(x < n){
				System.out.println("low");
			} else {
				System.out.println("CORRECT!");
				break;
			}
		}
	}
}
