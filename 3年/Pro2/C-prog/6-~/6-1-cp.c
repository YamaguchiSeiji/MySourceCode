#include <stdio.h>
#include <stdlib.h>
void count(FILE *, int *, int *, int *);

int main(int argc, char *argv[]){
	FILE *fi;

	if(argc == 1){
		fi = stdin;
		count(fi);
	} else {
		for(int i=1; i<argc; i++){
			if((fi = fopen(argv[i], "r")) == NULL){
				printf("Cannot open %s.\n", argv[i]);
				exit(1);
			}	
			count(fi);
			fclose(fi);
		}
	}

	return 0;
}

void count(FILE *f, int *l, int *w, int *c){
	int ch;
	int cc = 0, wc = 0, lc = 0;

	while((ch = fgetc(f)) != EOF){
		cc += 1;
		if(ch == ' '){
			wc += 1;
		} else if(ch == '\n'){
			lc += 1;
		}
	}
	printf("%4d %4d %4d \n", lc, wc, cc);
}

