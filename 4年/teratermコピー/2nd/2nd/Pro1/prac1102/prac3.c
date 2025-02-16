#include <stdio.h>
#include <limits.h>

int main(){
	puts("この処理系におけるintとunsigned intが表現できる範囲:");
	printf("int最小値: %d\n",INT_MIN);
	printf("int最大値: %d\n",INT_MAX);
	printf("unsigned int最小値: %d\n",0);
	printf("unsigned int最大値: %u\n",UINT_MAX);
	return 0;
}
