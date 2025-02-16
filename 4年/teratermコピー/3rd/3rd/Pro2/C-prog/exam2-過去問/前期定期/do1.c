#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int change(char[]);
void output(char [][100], int); 

int main(int ac, char *av[]){
	FILE *fp;
	int line = 10;
	char filename[80];

	if(ac == 1){
		
	} else if(ac >= 2 && ac <= 4){
		if(ac == 2){
		//ac == 2はファイル指定のみ
			strcpy(filename, av[1]);
		} else if(ac == 3){
		//ac == 3は行数指定のみ
			if(strcmp(av[1],"-n") != 0){
				printf("Usage: $ ./a.out [-n number] [filename]  -n\n");
				exit(1);
			} else {
				line = change(av[2]);
				printf("line = %d\n",line);
			}
		} else if(ac == 4){
		//ac == 4はファイル、行数指定
			if(strcmp(av[1],"-n") != 0){
				printf("Usage: $ ./a.out [-n number] [filename]  -n\n");
				exit(1);
			} else {
				line = change(av[2]);
				printf("line = %d\n",line);
			}
			strcpy(filename, av[3]);
		}
	}
	char data[line][100];
	if(ac == 2 || ac ==4){
		fp = fopen(filename, "r");
		if(fp == NULL){
			printf("File open ERROR: %s",filename);
		}
		fread(data, sizeof(char), line, fp);
	} else {
		for(int i =0; scanf("%s", data[i]) != EOF; i++){
			if(i == line) break;
		}
	}
	output(&data[line], line);

	fclose(fp);
	return 0;
}

int change(char s[]){
	int num=0;
	int i,j=1;
	for(i=strlen(s) - 1; i+1>0; i--){
		if(s[i] < '0' || s[i] > '9'){
			printf("Usage: $ ./a.out [-n number] [filename]\n");
		} else {
			num = num + (s[i] - '0') * j;
			j*=10;
		}
	}
	return num;
}

void output(char data[][100], int line){
	for(int i=0; i<line; i++){
		printf("%d: %s\n",i,data[i]);
	}
}
