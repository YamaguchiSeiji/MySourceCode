#include <stdio.h>
void topower(int *p,int y){
	int num=*p;
	for(int i=0; i<y-1; i++){
		*p*=num;
	}
}

int main(){
	int x,y;
	printf("2つの整数値を入力してください: ");
	scanf("%d %d",&x,&y);
	topower(&x,y);
	printf("%d\n",x);
	return 0;
}
