#include <stdio.h>
int main(){
	int x;
	printf("値を入力してください：");
	scanf("%d",&x);
	if(x%3==0){
		printf("3で割り切れます。\n");
	}
	if(x%2==0){
		printf("2で割り切れます。\n");
	}
	return 0;
}
