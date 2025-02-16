import java.util.Random;

class DrawPoints{
	public static void main(String[] args){
		//(1)
		Point p1 = new Point(2, 2);

		Point p2 = new Point(5, 7);

		System.out.println(p1.getDistance(p2));
	
		//(2)
		int n = Integer.parseInt(args[0]);
		Random rand = new Random();
		int rand_x, rand_y;
		Point p3[] = new Point[n];
		for(int i = 0; i < n; i++){
			rand_x = rand.nextInt(15);
			rand_y = rand.nextInt(15);
			p3[i] = new Point(rand_x, rand_y);
			System.out.println("x: " + p3[i].x + ", " + "y: " + p3[i].y);
		}
		boolean isAlpha = false;
		int count = 0;
		for(int i = 0; i < 15; i++){
			for(int j = 0; j < 15; j++){
				count = 0;
				for(int k = 0; k < n; k++){
					if(p3[k].x == j && p3[k].y == i){
						System.out.print((char)('A' + count) + " ");
						isAlpha = true;
						break;
					} else {
						isAlpha = false;
					}
					count++;
				}
				if(isAlpha == false){
					System.out.print("- ");
				}
			}
			System.out.println();
		}
		
		double min = 22;
		double max = 0;
		double dist = 0;
		char minC = 'A';
		char maxC = 'A';
		for(int i = 0; i < n; i++){
			dist = p3[i].getDistance(p3[0]);
			if(dist <= min){
				min = dist;
				minC += i;
			} else if(dist >= max){
				max = dist;
				maxC += i;
			}
		}
		System.out.println("点Aから一番遠い点: " + maxC + "(距離: " + max + ")");
		System.out.println("点Aから一番近い点: " + minC + "(距離: " + min + ")");


	}
}
