#include <stdio.h>
int num(const char *p){
	int num=0;
	while(*p != '\0'){
		num =  num  * 10 + (*p-'0');
		p++;
	}
	return num;
}

int main(){
	char ch[80];
	puts("数字列を入力してください。");
	printf("Input: ");
	scanf("%s",ch);
	puts("数字列を数値に変換します。");
	printf("Output: %d\n",num(ch));
	
}
