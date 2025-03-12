#include <stdio.h>
int main(){
	int x;
	printf("値を入力してください：");
	scanf("%d",&x);
	if(x>=10&&x<=99){
		printf("2桁の数字です。\n");
		} else {
		printf("2桁の数字ではありません。\n");
		}
	return 0;
}
