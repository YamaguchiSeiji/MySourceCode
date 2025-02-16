#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDLEN 80
#define MAX_MEANINGLEN 256
#define WORDNUM 5
#define ROW 8

typedef struct entry{
	char word[MAX_WORDLEN];
	char meaning[MAX_MEANINGLEN];
} data;

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
	FILE *fp;
	char fname[]="text.csv";
	char line[MAX_MEANINGLEN];
	char str[MAX_WORDLEN];
	char str_mean[MAX_MEANINGLEN];
	int i=0;
	data data[ROW];

	fp=fopen(fname,"r");
	if(fp == NULL){
		printf("%s file not open!\n", fname);
		return -1;
	}

	while(fgets(line,MAXMEANINGLEN,fp)!=NULL){
		sscanf(line, "%[^,],%[^,]\n",str, str_mean);
		for(int j=0; j<sizeof(data[i].str)/sizeof(data[i].str[0])); j++){
			data[i].str[j]=str[j];
		}
		
	}

	int r;
	srand((unsigned)time(NULL));
	r = rand() % WORDNUM;
	quiz(&entries[r]);
	return 0;
}
