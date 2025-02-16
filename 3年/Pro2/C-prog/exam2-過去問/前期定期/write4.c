#include <stdio.h>
#define MAX 100

int main(){
	FILE *fp;
	double data[MAX];
	int n;

	fp = fopen("data_file1", "rb");
	
	n = fread(data, sizeof(int), 100, fp);
	fclose(fp);
	printf("ファイルの中のデータ数:%d\n",n);

	while(scanf("%lf",&data[n]) != EOF){
		n++;
		if(n == MAX)break;
	}

	fp = fopen("data_file1", "wb");
	fwrite(&n, sizeof(int), 1, fp);
	fwrite(data, sizeof(int), n, fp);
	fclose(fp);

	return 0;
	

}
