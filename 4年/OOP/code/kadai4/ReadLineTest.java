import java.io.*;
class ReadLineTest {
	public static void main(String[] args) {
		if (args.length < 1) {
			// コマンドライン引数がない場合終了
			System.out.println("Too few arguments.");
			System.exit(0);
		}
		String filename = args[0];
		
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			while (true) {
				String line = br.readLine();
				if (line == null) // これ以上読み込む行がない場合
					break;
				System.out.println("[" + line + "]");
			}
			br.close();
		} catch(FileNotFoundException e){
			System.out.println("指定したファイルが見つかりませんでした.");
			System.exit(0);
		} catch(IOException e){
			System.out.println("入出力エラーが発生しました.");
			System.exit(0);
		}
	}
}
