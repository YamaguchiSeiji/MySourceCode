#include <stdio.h>

int z;

void func(int x) {
	int y;
	printf("func: &x =  %p\n", &x);
	printf("func: &y =  %p\n", &y);
}

int main(void) {
	int x;

	printf("main: &x =  %p\n", &x);
	printf("main: &z =  %p\n", &z);
	func(x);

	return 0;
}
