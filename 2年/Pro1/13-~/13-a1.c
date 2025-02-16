#include <stdio.h>
#include <string.h>
void strmove(char *s,char t){
	int len=strlen(s);
	for(int i=0; i<t-2; i++){
		
	}
}

void convstr(char *s){
	char *p=s;
	int n;
	for(int i=0; *s; i++){
		if(*s>='0'&&s<='9'){
			strmove(s,*s-'0');
		}
	}
}
int main(){
	char s[80];
	printf("Input: ");
	scanf("%s",s);
	convstr(s);
	puts(s);
}
