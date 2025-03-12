#include <stdio.h>
int main(){
	char word[80];
	char *p=word;
	int count=0;
	printf("Input a word: ");
	scanf("%s",word);
	while(*p){
		if(*p>='0'&&*p<='9'){
			count++;
		}
		p++;
	}
	printf("%d\n",count);
	return 0;
}
