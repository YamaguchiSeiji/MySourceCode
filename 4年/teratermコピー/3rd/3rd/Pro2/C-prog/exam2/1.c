#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]){
	FILE *fp;
	double data;
	double sum = 0;
	int data_no;

	if(ac == 1){
		puts("Usage: ./a.out filename");
		exit(1);
	} else if(ac == 2){
		if((fp = fopen(av[1], "rb")) == NULL){
			printf("file open error: %s\n", av[1]);
			exit(1);
		}
	}

	while(fread(&data, sizeof(double), 1, fp) == 1){
		printf("%.2f\n",data);
		sum += data;
	}
	printf("合計：%.2f\n",sum);

	printf("先頭から何番目のデータを表示しますか？:");
	scanf("%d",&data_no);
	fseek(fp, (data_no-1) * sizeof(double), SEEK_SET);
	fread(&data, sizeof(double), 1, fp);
	printf("%.2f\n", data);
	fclose(fp);
	return 0;
}
