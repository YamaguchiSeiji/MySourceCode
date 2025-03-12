#include <stdio.h>
#define MAX_WORDLEN 80

int charcount(const char *s ,char c){
	int count=0;
	for(int i=0; *s!='\0'; i++){
		if(*s==c){
			count++;
		}
		s++;
		i++;
	}
	return count;
}

int main(){
	char c;
	char word[MAX_WORDLEN];

	printf("word: ");
	scanf("%s",word);
	printf("char: ");
	scanf(" %c",&c);
	printf("%d\n", charcount(word, c));
	return 0;
}
