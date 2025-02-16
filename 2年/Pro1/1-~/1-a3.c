#include <stdio.h>
int main(){
	int x,y;

	printf("分数をx/yという形式で入力してください：");
	scanf("%d/%d",&x,&y);

	printf("%d/%dは%dと%d分の%dです。\n",x,y,x/y,y,x%y);

	return 0;
}
