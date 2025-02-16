#include <stdio.h>
#define NUM 3

int main(){
	int  sales[NUM][2];
	for(int i=0; i<NUM; i++){
		printf("<%d個目>\n",i+1);
		printf("値段: ");
		scanf("%d",&sales[i][0]);
		printf("個数: ");
		scanf("%d",&sales[i][1]);
	}

	int sum=0;
	for(int i=0; i<NUM; i++){
		printf("%d円 * %d個 = %d円\n",sales[i][0],sales[i][1],sales[i][0]*sales[i][1]);
		sum+=sales[i][0]*sales[i][1];
	}
	printf("合計: %d円\n",sum);

	return 0;
}
