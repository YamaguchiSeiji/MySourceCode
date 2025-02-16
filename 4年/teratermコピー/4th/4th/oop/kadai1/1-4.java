class StringTest{
	public static void main(String[] args){
		String s1 = "astronaut";
		String s2 = "collection";

		System.out.println("(1): " + s1.length());
		System.out.println("(2): " + s1.startsWith("ast"));
		System.out.println("(3): " + s1.lastIndexOf('a'));
		System.out.println("(4): " + s1.lastIndexOf("tron"));
		System.out.println("(5): " + s1.toUpperCase());
		System.out.println("(6): " + s1.replace('t', ('*')));
		System.out.println("(7): " + s1.contentEquals(s2));
		System.out.println("(8): " + s1.compareTo(s2));
	}
}
