#include <stdio.h>
int main(){
	int i=0, num=0, sum=0;
	puts("入力値の合計と平均--計算終了条件(負値入力)");
	puts("整数を入力してください。");
	while(1){
		scanf("%d",&num);
		if(num<0 && i==0){
			puts("データが無効です。");
			return 0;
		}
		if(num<0){
			break;
		}
		sum+=num;
		i++;
	}
	printf("合計： %7d\n",sum);
	printf("平均： %7.2f\n",(double)sum/i);
	return 0;
}
