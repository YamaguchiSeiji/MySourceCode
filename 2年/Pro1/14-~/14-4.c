#include <stdio.h>
struct point{
	int x;
	int y;
};

void xyswap(struct point *p){
	int i;
	i = p->x;
	p->x = p->y;
	p->y = i;
}

int main(void){
	struct point pt;
	printf("点: ");
	scanf("%d, %d",&pt.x,&pt.y);
	printf("(%d, %d)\n",pt.x,pt.y);
	xyswap(&pt);
	puts("xとyを入れ替えます");
	printf("(%d, %d)\n",pt.x,pt.y);
	return 0;
}
