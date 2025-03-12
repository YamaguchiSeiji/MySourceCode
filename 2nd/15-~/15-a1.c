#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDLEN 80
#define MAX_MEANINGLEN 256
#define WORDNUM 5
struct entry{
	char word[MAX_WORDLEN];
	char meaning[MAX_MEANINGLEN];
};

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

void quiz(struct entry *p){
	char ans[MAX_WORDLEN];
	printf("[meaning] %s\n",(*p).meaning);
	printcons((*p).word);
	printf("Answer?: ");
	scanf("%s",ans);
	if(strcmp((*p).word,ans)==0){
		puts("Correct!");
	} else {
		puts("Wrong Answer");
	}

}
int main(){
	int r;
	srand((unsigned)time(NULL));
	r = rand() % WORDNUM;
	struct entry entries[]={
		{"pen", "a writing implement with a point from which ink flows"},
		{"eraser", "an implement used to erase something"},
		{"notebook", "a book with blank pages for recording notes or memoranda"},
		{"compass", "drafting instrument used for drawing circles"}
	};
	quiz(&entries[r]);
	return 0;
}
