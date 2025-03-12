import java.util.Scanner;

class TagPrinter{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Tag[] t = new Tag[1000];
		int count = 0;

		while(true){
			System.out.print("[n]:Normal, [d]:Decoretad, [f]:Framed, [q]:quit: ");
			String selection = in.nextLine();
			
			if(selection.equals("n")){
				System.out.print("Name?: ");
				String name = in.nextLine();
				t[count] = new Tag(name);
			} else if(selection.equals("d")){
				System.out.print("Name?: ");
				String name = in.nextLine();
				System.out.print("decochar?: ");
				String deco = in.nextLine();
				t[count] = new DecoratedTag(name, deco.toCharArray()[0]);
			} else if(selection.equals("f")){
				System.out.print("Name?: ");
				String name = in.nextLine();
				System.out.print("margin?: ");
				try{
					int margin = Integer.parseInt(in.nextLine());
					t[count] = new FramedTag(name, margin);
				} catch(NumberFormatException e){
					System.out.println("Input Error");
					continue;
				}
			} else if(selection.equals("q")){
				break;
			} else {
				System.out.println("Input Error");
				continue;
			}
			count++;
		}
		
		for(int i = 0; i < count; i++){
			t[i].show();
		}
	}
}
