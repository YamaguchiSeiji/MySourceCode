#include <stdio.h>
int factorial(int x){
	int sum=1;
	for(int i=1; i<=x; i++){
		sum*=i;
	}
	return sum;
}
int main(){
	int x;
	printf("整数を入力してください： ");
	scanf("%d",&x);
	printf("%dの階乗は%dです。\n",x,factorial(x));
	return 0; 
}
