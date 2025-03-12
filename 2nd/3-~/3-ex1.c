#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int r1,r2,dif=0,sum=0,num=0;
	srand((unsigned)time(NULL));
	do{
		r1=rand()%90+10; 
		r2=rand()%90+10;
		
		if(num%2==0){
			printf("%d + %d：",r1,r2);
			scanf("%d",&sum);
		} else {
			printf("%d - %d：",r1,r2);
			scanf("%d",&dif);
		}		
		num++;
		if(num==10){
			printf("おめでとう！！\n");
			return 0;
		}

	} while(num%2!=0&&r1+r2==sum||num%2==0&&r1-r2==dif);
		
	if(num%2!=0){
		printf("残念！正解は%dでした。\n",r1+r2);
		printf("計%d問正解です。\n",num-1);
	} else {
		printf("残念！正解は%dでした。\n",r1-r2);
		printf("計%d問正解です。\n",num-1);
	}

	return 0;
}

