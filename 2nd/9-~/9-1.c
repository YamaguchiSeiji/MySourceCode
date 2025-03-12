#include <stdio.h>
int main(){
	int num;
	printf("整数を10進数で入力してください:");
	scanf("%d",&num);
	printf("8進数:%o\n",num);
	printf("16進数:%X\n",num);
	return 0;
}
