#include <stdio.h>
int main(){
	int x;
	do{
		printf("1以上の数を入力してください：");
		scanf("%d",&x);
	} while(x<1);
	if(x%2==0){
		puts("偶数です");
	} else {
		puts("奇数です");
	}

	return 0;
}
