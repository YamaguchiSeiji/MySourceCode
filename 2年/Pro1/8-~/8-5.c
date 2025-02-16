#include <stdio.h>
int factorial(int x){
	int fact=1;
	for(int i=1; i<=x; i++){
		fact*=i;
	}
	return fact;
}

int factsum(int n){
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=factorial(i);
	}
	return sum;
}

int main(){
	int n;
	printf("Input n: ");
	scanf("%d",&n);
	printf("%d\n",factsum(n));
	return 0;
}
