import java.util.Scanner;

class Simulator{
	public static void main(String[] args){
		ExClock clk = new ExClock(true);
		Scanner in = new Scanner(System.in);

		while(true){
			System.out.print("[s] show, [t] toggle 12/24H,  [q] quit: ");
			String mode = in.nextLine();
			if(mode.equals("s")){
				clk.show();
			} else if(mode.equals("q")){
				System.out.println("Bye.");
				break;
			} else if(mode.equals("t")){
				clk.changeMode();
			} else {
				System.out.println("Invalid input.");
			}
		}
		in.close();
	}
}
