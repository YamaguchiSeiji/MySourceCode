#include <stdio.h>
int main(){
	int num,sum=0;
	printf("何の倍数をスキップしますか？： ");
	scanf("%d",&num);
	for(int i=1; i<=10 ;i++){
		if(i%num==0){
			sum++;
			continue;
		}
		printf("%d ",i);
	}
	puts(" ");
	printf("全部で%d個の数値を出力しました。\n",10-sum);
	return 0;
}
