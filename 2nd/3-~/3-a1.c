#include <stdio.h>
int main(){
	int i=0,num=0;
	printf("整数を入力してください：　");
	scanf("%d",&num);
	while(0<num){
		num/=10;
		i++;
	}
	printf("%d\n",i);
	return 0;
}
