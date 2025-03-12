#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDLEN 80
#define WORDNUM 5

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
	for(int i='a'; i<'z'; i++){
		if(charcount(s,i)!=0){
			printf("- %c: %d\n",i,charcount(s,i));
		}
	}
}

void quiz(const char *words){
	char ans[MAX_WORDLEN];
	printf("Guess: %c",*words);
	
	for(int i=1; i<strlen(words); i++){
		printf("*");
	}
	puts("");
	printcons(words);
	printf("Answer?: ");
	scanf("%s",ans);
	if(strcmp(words,ans)==0){
		puts("Correct!");
	} else {
		puts("Wrong Answer");
	}

}
int main(){
	int r;
	char words[][MAX_WORDLEN] = {"astronaut", "book", "cat", "daughter", "egg"};
	srand((unsigned)time(NULL));
	r = rand() % WORDNUM;
	quiz(words[r]);
	return 0;
}
