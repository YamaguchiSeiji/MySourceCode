#include <stdio.h>
void put_stringr(const char s[]){
	int n=0;
	for(int i=0; s[i]!='\0'; i++){
		n++;
	}
	for(int i=n; i>=0; i--){
		putchar(s[i]);
	}
}

int main(){
	char s[80];
	scanf("%s",s);
	put_stringr(s);
	puts("");
	return 0;
}
