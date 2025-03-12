#include <stdio.h>

int factorial(int n) {
	//printf("factorial &n = %p\n", &n);
	//printf("factorial  n = %d\n", n);
	if (n > 1)
		return n * factorial(n-1);
	else
		return 1;
}
int main(void){
	int  x;

	x = factorial(4);
	printf("n! = %d\n", x);

	return 0;
}
