#include <stdio.h>
int main(){
	int x,y;

	printf("xとyに入れる数を入力してください(例:x,y):");
	scanf("%d,%d",&x,&y);

	printf("(x+y)(x-y)の値は%dです。\n",(x+y)*(x-y));

	return 0;
}
