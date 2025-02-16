import java.io.*;
class OutputTest {
	public static void main(String[] args) {
		if (args.length < 1) {
			// コマンドライン引数がない場合終了
			System.out.println("Too few arguments.");
			System.exit(0);
		}
		
		try{
			FileWriter file = new FileWriter("out.txt");
			PrintWriter pw = new PrintWriter(new BufferedWriter(file));
			
			for(int i = 0; i < args.length; i++){
				pw.print(args[i].toLowerCase());
				if(i == args.length - 1){
					pw.println();
					break;
				}
				pw.print("_");
			}
			System.out.println("Done.");
			pw.close();
		} catch(IOException e){
			System.out.println("書き込むことができませんでした.");
			System.exit(0);
		}
	}
}
