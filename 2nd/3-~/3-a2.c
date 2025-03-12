#include <stdio.h>
int main(){
	int i=0,height;
	int n=0,width=1;
	printf("高さは？： ");
	scanf("%d",&height);

	while(i<height){
		while(n<width){
			printf("%d",n%10);
			n++;
		}
		printf("\n");
		n=0;
		width++;
		i++;
	}

	return 0;
}
