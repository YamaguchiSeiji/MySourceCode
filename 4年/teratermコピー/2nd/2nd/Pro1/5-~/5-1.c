#include <stdio.h>
int main(){
	int i,sum=0;
	printf("５つの整数を入力してください。\n");
	for(int num=1; num<=5; num++){
		printf("%d番目: ",num);
		scanf("%d",&i);
		sum+=i;
	}
	printf("合計値は%dです。\n",sum);
	printf("平均値は%.1fです。\n",(double)sum/5);
	return 0;
}
