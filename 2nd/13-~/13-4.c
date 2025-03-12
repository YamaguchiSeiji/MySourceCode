#include <stdio.h>
void gethead(char *s,int x){
	int i=0;
	while(i<x){
		s++;
		i++;
	}
	*s='\0';
}

int main(){
	char s[80];
	int x;
	printf("文字列は？: ");
	scanf("%s",s);
	printf("文字数は？: ");
	scanf("%d",&x);
	gethead(s,x);
	puts(s);
	return 0;
}
