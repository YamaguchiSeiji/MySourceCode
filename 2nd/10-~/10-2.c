#include <stdio.h>
int main(){
	char str[48];
	printf("文字列を入力してください: ");
	scanf("%s",str);
	for(int i=0; str[i]!='\0'; i++){
		printf("%d番目の文字: %c (文字コード:%X)\n",i,str[i],str[i]);
	}
	return 0;

}
