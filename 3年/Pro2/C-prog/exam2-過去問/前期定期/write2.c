#include <stdio.h>
#include <string.h>
#define MAX 256

void f2(char st[]){
	for(int i=0; i < strlen(st); i++){
		if(st[i] == '\n'){
			for(int j=i; j<strlen(st); j++){
				st[j] = st[j+1];
			}
			st[strlen(st)] = '\0';
		}
	}
}
void f(FILE *fp){
	char st[MAX];
	int n = 1;
	while(fgets(st, sizeof(st), fp) != NULL){
		printf("%7d: ", n++);
		f2(st);
		puts(st);
	}
}


int main(int ac, char *av[]){
	FILE *fp;
	int i;

	if(ac == 1){
		f(stdin);
	} else {
		for(i = 1; i < ac; i++){
			fp = fopen(av[i], "r");
			if(fp == NULL){
				printf("cannot open file: %s\n", av[i]);
				continue;
			}
			f(fp);
			fclose(fp);
		}
	}
	return 0;
}
