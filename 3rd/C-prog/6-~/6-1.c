#include <stdio.h>
#include <stdlib.h>
void count(FILE *, int *, int *, int *);

int main(int argc, char *argv[]){
	FILE *fi;
	int cc = 0, wc = 0, lc = 0;
	int sumc = 0, sumw = 0, suml = 0;

	if(argc == 1){
		fi = stdin;
		count(fi, &cc, &wc, &lc);
		printf("%4d %4d %4d\n", lc, wc, cc); 
	} else {
		for(int i = 1; i < argc; i++){
			if((fi = fopen(argv[i], "r")) == NULL){
				printf("Cannot open %s.\n", argv[i]);
				continue;
			}	
			count(fi, &cc, &wc, &lc);
			sumc += cc, sumw += wc, suml += lc;
			printf("%4d %4d %4d %s\n", lc, wc, cc, argv[i]); 
			fclose(fi);
		}
		if(argc >= 3){
			printf("%4d %4d %4d 合計\n", suml, sumw, sumc);
		}
		
	}

	return 0;
}

void count(FILE *f, int *cc, int *wc, int *lc){
	int ch;
	*cc = 0, *wc = 0, *lc = 0;
	int sf = 1;
	while((ch = fgetc(f)) != EOF){
		(*cc)++;
		if(ch == ' ' || ch == '	' || ch == '\n'){
			sf = 1;
		} else if(sf == 1){
			(*wc)++;
			sf = 0;
		}
		if(ch == '\n'){
			(*lc)++;
		}
	}
}


