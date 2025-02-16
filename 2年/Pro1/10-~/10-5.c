#include <stdio.h>
#include <string.h>
int main(){
	char str[80];
	printf("文字列を入力してください: ");
	scanf("%s",str);
	printf("文字列%sの長さは%zuです。\n",str,strlen(str));
	return 0;
}
