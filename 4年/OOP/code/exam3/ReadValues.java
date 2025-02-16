import java.io.*;

class ReadValues {
	public static void main(String[] args) {
		if (args.length < 1) {
			System.out.println("Too few arguments");
			System.exit(1);
		}

		String filename = args[0];				
		String line = null;
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			int count = 0;
			while (true) {
				line = br.readLine();
				if (line == null) // これ以上読み込む行がない場合
					break;
				int num = Integer.parseInt(line);
				count += num;
			}
			System.out.println(count);
			br.close();
		} catch(FileNotFoundException e){
			System.out.print("File Not Found: ");
			System.out.println(filename);
		} catch (IOException e) {
			System.out.println("I/O Exception");
		} catch (NumberFormatException e){
			System.out.print("Invalid data: ");
			System.out.println(line);
		}
	}
}
