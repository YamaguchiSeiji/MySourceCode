#include <stdio.h>
int main(){
	int num1,num2,n=0;
	scanf("%d",&num1);
	num2=num1;

	for(num1=num2; num2>0; num2/=10){
		num1=num2;
		while(num1>=10){
			num1-=10;
		}
		if(num1==3){
			n=1;
			break;
		}
	}
	
	printf("%d\n",n);

	return 0;
}
