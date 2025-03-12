#include <stdio.h>
int main(){
	int num1;
	do{
		scanf("%d",&num1);
	} while(num1<10);

	int i=num1%10;
	int n=0;

	for(int num2=num1; num2>0; num2/=10){
		if(i==num2%10){
			n=1;
		} else {
			n=0;
		}
	}

	printf("%d\n",n);
	return 0;
}
