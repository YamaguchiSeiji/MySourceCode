#include <stdio.h>
int main(void){
	int a,b;
	int ans;

	scanf("%d%d", &a, &b);
	printf("%p %p %p\n", &a, &b, &ans);

	ans = a + b;
	printf("%d + %d = %d\n", a, b, ans);
	return 0;
}
