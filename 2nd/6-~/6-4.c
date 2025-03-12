#include <stdio.h>
int main(){
	int a;
	printf("何個のデータを入力しますか？(最大１０): ");
	scanf("%d",&a);

	int num[a];
	for(int i=0; i<a; i++){
		printf("No.%d: ",i+1);
		scanf("%d",&num[i]);
	}

	int max=num[0],min=num[0];
	for(int i=0; i<a-1; i++){
		if(max<num[i+1]){
			max=num[i+1];
		}
		if(min>num[i+1]){
			min=num[i+1];
		}
	}

	printf("最大値は%dで、最小値は%dです。\n",max,min);

	return 0;
}
