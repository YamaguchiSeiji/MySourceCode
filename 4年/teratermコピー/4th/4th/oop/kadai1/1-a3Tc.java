import java.util.Random;

class DrawPoints{
	public static void main(String[] args){
		//(1)
		Point p1 = new Point(0, 4);

		Point p2 = new Point(3, 0);

		System.out.println(p1.getDistance(p2));
	
		//(2)
		int n = Integer.parseInt(args[0]);
		Random rand = new Random();
		int rand_x, rand_y;
		Point limit = new Point(15, 15);
		Point p3[] = new Point[n];
		for(int i = 0; i < n; i++){
			rand_x = rand.nextInt(limit.x);
			rand_y = rand.nextInt(limit.y);
			p3[i] = new Point(rand_x, rand_y);
		}
		boolean isAlpha = false;
		int count = 0;
		for(int i = 0; i < limit.y; i++){
			for(int j = 0; j < limit.x; j++){
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
		
		double min = limit.getDistance(new Point(0, 0));
		double max = 0.0;
		double dist = 0;
		char minC = 'A';
		char maxC = 'A';
		for(int i = 1; i < n; i++){
			dist = p3[i].getDistance(p3[0]);
			if(dist < min){
				min = dist;
				minC = (char)('A' + i);
			}
			if(dist > max){
				max = dist;
				maxC = (char)('A' + i);
			}
		}
		System.out.println("点Aから一番遠い点: " + maxC + " (距離: " + String.format("%.2f", max) + ")");
		System.out.println("点Aから一番近い点: " + minC + " (距離: " + String.format("%.2f", min) + ")");
	}
}
