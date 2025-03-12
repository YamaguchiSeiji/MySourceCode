#include <stdio.h>
#define NUM 3
struct point{
	int x;
	int y;
};

int main(){
	struct point pt[NUM];
	for(int i=0; i<NUM; i++){
		printf("点%dの座標を入力してください: ",i);
		scanf("%d,%d",&pt[i].x, &pt[i].y);
		for(int n=0; n<10; n++){
			for(int j=0; j<10; j++){
				if(pt[i].x==j && 9-pt[i].y==n){
					printf("%d",i);
				} else if(j==0 && n!=9){
					printf("|");
				} else if(n==9 && j==0){
					printf("+");
				} else if(n==9 && j!=0){
					printf("-");
				} else {
					printf(" ");
				}				
			}
			puts("");
		}
	}
	return 0;
}
