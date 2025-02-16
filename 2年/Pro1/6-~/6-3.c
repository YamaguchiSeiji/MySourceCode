#include <stdio.h>
#define NUMBER 3
int main(){
	int num[NUMBER];
	printf("値を%d個入力してください。\n",NUMBER);

	for(int i=0; i<NUMBER; i++){
		scanf("%d",&num[i]);
	}

	putchar('[');
	for(int i=0; i<NUMBER; i++){
		printf("%d",num[i]);
		if(i==NUMBER-1)continue;
		putchar(',');
	}
	puts("]");

	return 0;
}
