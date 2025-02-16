#include <stdio.h>
void delnumchars(char *s){
	char *p=s;
	while(*p!='\0'){
		if(*p>='0'&&*p<='9'){
			while(*p!='\0'){
				*p=*(p+1);
				p++;
			}
			p=s;
		}
		p++;
	}
}

int main(){
	char s[]="abc123DE45";
	printf("元の文字列は%sです。\n",s);
	delnumchars(s);
	printf("数値を削除した文字列は%sです。\n",s);
	return 9;
}
