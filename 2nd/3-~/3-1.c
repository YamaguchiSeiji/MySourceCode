#include <stdio.h>
int main(){
	int i=0,num=0;
	printf("何回出力しますか：");
	scanf("%d",&num);
	while(i<num){
		printf("%d: Hi!\n",i+1);
		i++;
	}
	return 0;
}
