#include <stdio.h>
int main(){
	int num;
	printf("整数を16進数で入力してください:");
	scanf("%x",&num);
	printf("8進数:%o\n",num);
	printf("10進数:%d\n",num);
	return 0;
}
