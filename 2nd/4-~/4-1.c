#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i,r;
	srand((unsigned)time(NULL));

	i=0;
	while(i<10){
		r=rand()%9+1;
		printf("%d\n",r);
		i++;
	}

	return 0;
}
