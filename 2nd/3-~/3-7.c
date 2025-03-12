#include <stdio.h>
int main(){
	int num;
	do{
		printf("1以上20以下の整数を入力してください：");
		scanf("%d",&num);
	} while(num<1||num>20);
	
	while(num>0){
		putchar('*');
		num--;
	}
	putchar('\n');

	return 0;

}
