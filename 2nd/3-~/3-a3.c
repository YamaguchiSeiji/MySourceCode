#include <stdio.h>
int main(){
	int num=0,min=0,max=0;
	do{
		printf("整数を入力してください：");
		scanf("%d",&num);
		if(num>=max){
			max=num;
		}
		if(min==0||num<=min&&num>=0){
			min=num;
		}
	} while(num>=0);

	if(max==0&&min==0){
		printf("有効な値が1つも入力されていません。\n");
	} else {
		printf("最大値は%d,最小値は%dです。\n",max,min);
	}

	return 0;
}
