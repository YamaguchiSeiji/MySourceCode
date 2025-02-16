#include <stdio.h>
int main(){
	int n,num=0,i=1;
	printf("Input n: ");
	scanf("%d",&n);
	while(i<n){
		num+=i;
		printf("%d + ",i++);
	}
	printf("%d = ",i);
	printf("%d\n",num+i);
	return 0;
}
