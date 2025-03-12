#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;
};

int main(){
	double dis=0;
	struct point pt1,pt2;
	printf("点1(x, y): ");
	scanf("%d,%d",&pt1.x,&pt1.y);
	printf("点2(x, y): ");
	scanf("%d,%d",&pt2.x,&pt2.y);
	dis=sqrt(pow(pt2.x-pt1.x,2)+pow(pt2.y-pt1.y,2));
	printf("2点間の距離は%.2fです。\n",dis);
	return 0;
}
