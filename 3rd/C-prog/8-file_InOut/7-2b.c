#include <stdio.h>
#include <stdlib.h>

void output(double [], int);
void add_data(double [], int *);

int main(){
	double data[100];
	int n;
	int i;
	FILE *fp;
//data読み取り

	if((fp = fopen("data7_2", "rb")) == NULL){
		printf("cannot file open.\n");
		exit(1);
	}

	printf("---------------データ追加前---------------\n\n");	
	fread(&n, sizeof(int), 1, fp);
	printf("data count = %d\n",n);	
	
	fread(data, sizeof(double), 100, fp);
	output(data, n);
	
	fclose(fp);
	printf("\n------------------------------------------\n");
	
//data追加
	if(n >= 100){
		puts("これ以上データを追加できません.");
		exit(1);
	}
	puts("追加したいデータを入力してください");

	add_data(data, &n);
	printf("\n---------------データ追加後---------------\n\n");
	printf("data count = %d\n",n);
	fwrite(&n, sizeof(int), 1, fp);
	fwrite(data, sizeof(double), 100, fp);
	output(data, n);
	fclose(fp);
	printf("\n------------------------------------------\n");

	return 0;	
}

void output(double data[], int n){
	for(int i=0; i < n; i++){
		printf("%f ", data[i]);
		if((i + 1) % 5 == 0){
			puts("");
		}
	}
	puts("");
}

void add_data(double data[], int *n){
	int i;
	FILE *fp;
	if((fp = fopen("data7_2", "wb")) == NULL){
		printf("cannot file open.\n");
		exit(1);
	}
	for(i = *n; scanf("%lf",&data[i]) != EOF; i++){
		if(i >= 99){
			i++;
			*n = i;
			return;
		}
	}
	*n = i;
}
