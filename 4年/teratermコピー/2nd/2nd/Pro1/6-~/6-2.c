#include <stdio.h>
#define NUMBER 5
int main(){
	int num[NUMBER];
	printf("値を%d個入力してください。\n",NUMBER);

	for(int i=0; i<NUMBER; i++){
		scanf("%d",&num[i]);
	}

	printf("逆順に表示します。\n");
	for(int i=NUMBER-1; i>=0; i--){
		printf("%d\n",num[i]);
	}

	return 0;
}
