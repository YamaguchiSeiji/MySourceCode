import java.util.Scanner;

class SumTest{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int sum = 0;
		int count = 0;
		for(int i = 0; i < 5; i++){
			System.out.println("Input number:");
			int num = in.nextInt();
			sum += num;
			count++;
		}
		float ave = (float)sum / count;
		System.out.println("sum: " + sum);
		System.out.println("average: " + ave);
	}
}
