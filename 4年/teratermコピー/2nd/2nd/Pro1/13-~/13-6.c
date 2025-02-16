#include <stdio.h>
int ismu13(char *s){
	int sum=0;
	while(*s){
		sum+=(*s-'0');
		s++;
	}
	if(sum%3==0){
		return 1;
	} else{
		return 0;
	}
}
int main(){
	char s[80];
	printf("Input number: ");
	scanf("%s",s);
	if(ismu13(s)==1){
		puts("3の倍数です。");
	} else {
		puts("3の倍数ではありません。");
	}
	return 0;
}
