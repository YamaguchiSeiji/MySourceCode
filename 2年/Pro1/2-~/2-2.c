#include <stdio.h>
int main(){
	int x;
	printf("値を入力してください：");
	scanf("%d",&x);
	if(x==0){
		printf("0です。\n");
	} else if(x<0){
		printf("負の値です。\n");
	} else if(0<x){
		printf("正の値です。\n");
	}
	return 0;
}
