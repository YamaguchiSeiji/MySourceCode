#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fi1, *fi2, *fi3;
	char fn[80];

	puts("読み込むファイル1を指定してください。");
	scanf("%s",fn);
	if((fi1 = fopen(fn,"r")) == NULL){
		printf("Cannot open %s\n",fn);
	}

	puts("読み込むファイル2を指定してください。");
	scanf("%s",fn);
	if((fi2 = fopen(fn,"r")) == NULL){
		printf("Cannot open %s\n",fn);
	}
	puts("書き込むファイルを指定してください。");
	scanf("%s",fn);
	if((fi3 = fopen(fn,"w")) == NULL){
		printf("Cannot open %s\n",fn);
	}

	int data1,data2,flag = 0;
	fscanf(fi1, "%d", &data1);
	fscanf(fi2, "%d", &data2);
	puts("2つのファイルを昇順に並び替えました。");
	while(1){
		if(data1 > data2){
			fprintf(fi3, "%d\n", data2);
			if(fscanf(fi2, "%d", &data2) == EOF){
				break;	
			}
		} else if(data1 < data2){
			fprintf(fi3, "%d\n", data1);
			if(fscanf(fi1, "%d", &data1) == EOF){
				break;	
			}
		} else if(data1 == data2){
			fprintf(fi3, "%d\n", data1);
			fprintf(fi3, "%d\n", data2);
			if(fscanf(fi1, "%d", &data1) == EOF){
				flag = 0;
				break;
			} else if(fscanf(fi2, "%d", &data2) == EOF){
				flag = 1;
				break;
			}
		}
	}
	if(flag == 0){
		while(fscanf(fi2, "%d", &data2) != EOF){
			fprintf(fi3, "%d\n", data2);
		}
	} else {
		while(fscanf(fi1, "%d", &data1) != EOF){
			fprintf(fi3, "%d\n", data1);
		}
	}
	fclose(fi1);
	fclose(fi2);
	fclose(fi3);

	return 0;

}
