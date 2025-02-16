#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;
};

int main(){
	struct point pts[4];
	int p[2];
	double dis;
	for(int i = 0; i < 4; i++){
		printf("点%d: ",i);
		scanf("%d, %d",&pts[i].x, &pts[i].y);
	}
	printf("2つの点を指定してください: ");
	scanf("%d %d",&p[0],&p[1]);

	dis=sqrt(pow(pts[p[1]].x-pts[p[0]].x,2)+pow(pts[p[1]].y-pts[p[0]].y,2));
	printf("点%dと点%dの間の距離は%.2fです。\n",p[0],p[1],dis);
	return 0;
}
