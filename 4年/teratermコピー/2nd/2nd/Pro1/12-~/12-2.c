#include <stdio.h>
void adjust(int *x){
	if(*x<0){
		*x=0;
	} else if(*x>10){
		*x=10;
	}
}

int main(){
	int x;
	printf("値を入力してください: ");
	scanf("%d",&x);
	adjust(&x);
	printf("%d\n",x);
	return 0;
}
