#include <stdio.h>
int main(){
	int x;
	printf("値を入力してください：");
	scanf("%d",&x);
	if(x%2==0){
		printf("偶数です。\n");
	} else {
		printf("奇数です。\n");
	}
	return 0;
}
