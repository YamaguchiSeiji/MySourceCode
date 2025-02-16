#include <stdio.h>
#define MAX 256

void f(FILE *fp){
	char st[MAX];
	int n = 1;
	while(fscanf(fp,"%s", st) != EOF){
		printf("%7d: ", n++);
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
