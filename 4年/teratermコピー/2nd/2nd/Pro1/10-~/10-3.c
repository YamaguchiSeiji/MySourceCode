#include <stdio.h>
void hidevowel(char s[]){
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'){
			s[i]='*';
		}
	}
}

int main(){
	char s[80];
	printf("文字列を入力してください: ");
	scanf("%s",s);
	hidevowel(s);
	puts(s);
	return 0;
}
