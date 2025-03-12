#include <stdio.h>
int main(){
	int x,i=0;
	scanf("%d",&x);
	while(i<x){
		printf("%d",i%10);
		i++;
	}
	printf("\n");
	return 0;
}
