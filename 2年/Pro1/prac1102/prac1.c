#include <stdio.h>
#include <limits.h>

int main(){
	puts("この処理系における型のサイズ:");
	printf("char: %zuバイト\n",sizeof(char));
	printf("int: %zuバイト\n",sizeof(int));
	printf("double: %zuバイト\n",sizeof(double));

	return 0;
}
