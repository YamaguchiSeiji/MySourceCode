#include <stdio.h>
#include <string.h>
void transstr(char *s){
	char *p=s;
	while(*p){
		if(*p>='A'&&*p<='Z'){
			*p-='A'-'a';
		}
		if(*p==' '){
			while(*p){
				*p=*(p+1);
				p++;
			}
			p=s;
		}
		p++;
	}
	puts(s);
}
int ispalindrome(char *s1,char *s2){
	transstr(s1);
	int n=strlen(s1),i=0;
	s2+=n-2;
	while(i<n/2){
		if(*s1!=*s2){
			return 0;
		}
		s1++;
		s2--;
		i++;
	}
	return 1;
}
int main(){
	char s[80];
	printf("文字列は？: ");
	fgets(s,sizeof(s),stdin);
	if(ispalindrome(s,s)==1){
		puts("回文です。");
	} else {
		puts("回文ではありません。");
	}
	return 0;
}
