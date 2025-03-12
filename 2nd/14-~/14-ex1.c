#include <stdio.h>
#define NUM 5
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
				for(int k=0; k<=i; k++){
					if(pt[k].x==j && 9-pt[k].y==n){
						printf("%d",k);
					} else if(k==0 && j==0 && n!=9){
						printf("|");
					} else if(k==0 && n==9 && j==0){
						printf("+");
					} else if(k==0 && n==9 && j!=0){
						printf("-");
					} else if(k==0){
						printf(" ");
					}				
				}
			}
			puts("");	
		}
		for(int j=0; j<=i; j++){
			printf("点%d: (%d, %d)\n",j, pt[j].x, pt[j].y);
		}
	}
	return 0;
}
