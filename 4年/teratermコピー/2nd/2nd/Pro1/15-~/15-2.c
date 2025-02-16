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

void printcons(const char *s){
	for(int i='a'; i<='z'; i++){
		if(charcount(s,i)!=0){
			printf("- %c: %d\n",i,charcount(s,i));
		}
	}
}

int main(){
	char word[MAX_WORDLEN];

	printf("word: ");
	scanf("%s",word);
	printcons(word);
	return 0;
}
