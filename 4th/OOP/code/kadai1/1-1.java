class PrintEachChar{
	public static void main(String[] args){
		String s = "この猫の名前はmikeです";

		for(int i = 0; i < s.length(); i++){
			System.out.println(i + ":" + s.charAt(i));
		}
	}
}
