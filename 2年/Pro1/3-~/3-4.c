#include <stdio.h>
int main(){
	int weight,sum=0,num=1;
	while(1){
		printf("%d人目の体重は： ",num);
		scanf("%d",&weight);
		sum+=weight;
		if(sum>300)break;
		num++;
	}
	printf("合計重量が%dkgとなり、%dkgオーバーしました。\n",sum,sum-300);
	printf("%d人目の人は乗ることができません。\n",num);
	return 0;
}
