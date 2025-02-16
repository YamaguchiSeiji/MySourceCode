#include <stdio.h>
int main(){
	int num,sum=0;
	do{
		scanf("%d",&num);
		sum+=num;
	} while(num!=0);
	printf("総和：%d\n",sum);

	return 0;
}
