#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int i,r,sum,answer;
	srand((unsigned)time(NULL));

	sum=0,i=0;
	while(i<3){
		r=rand()%9+1;
		printf("%d\n",r);
		sum+=r;
		i++;
	}
	printf("Answer: ");
	scanf("%d",&answer);

	if(sum==answer){
		printf("Correct!\n");
	} else {
		printf("Wrong..\n");
		printf("The correct answer was %d.\n",sum);
	}

	return 0;
}
