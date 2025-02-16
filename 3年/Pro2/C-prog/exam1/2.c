#include <stdio.h>
#include <string.h>
int sum(FILE *);
int myatoi(const char *);
int main(int argc, char *argv[]){
	FILE *fi;
	if(argc == 1){
		fi = stdin;

	} else if(argc >= 2){
		for(int i=1; i < argc; i++){
			if((fi = fopen(argv[i], "r")) == NULL){
				printf("ファイル%sは開けません.\n", argv[i]);	
				continue;
			}
		printf("ファイル%sの合計=%d\n",argv[i],sum(fi));
		fclose(fi);
		}

	}
	return 0;
}

int sum(FILE *f){
	int ch;
	char s[80];
	int i=0;
	int sum=0;
	for(i = 0; (ch = fgetc(f)) != EOF; i++) {
		s[i] = ch;
		if(ch == ' ' || ch =='\t' || ch =='\n' || ch == ','){
			s[i] = '\0';
			sum += myatoi(s);
			i = 0;
			strcpy(s, "");
		}
	}
	return sum;
}

int myatoi(const char *s){
	int num=0;
	int i=0;
	while(*(s+i) != '\0'){
		i++;
	}
	for(int j=i-1,n=1;  j >= 0; j--, n++){
		num += n * (*(s+j) - '0');
	}
	return num;
}
