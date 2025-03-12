#include <stdio.h>
int main(){
	int x,y;

	printf("整数xを入力してください：");
	scanf("%d",&x);

	printf("整数yを入力してください：");
	scanf("%d",&y);

	printf("yはxの%.1f%%です。\n", (double)y/x*100);

	return 0;
}
