#include <stdio.h>
#include <stdlib.h>

void output(double [], int);

int main(){
	double data[100];
	int n;
	FILE *fp;
	
	if((fp = fopen("data7_2", "rb")) == NULL){
		printf("cannot file open.\n");
		exit(1);
	}

	fread(&n, sizeof(int), 1, fp);
	printf("data count = %d\n",n);	
	
	fread(data, sizeof(double), 100, fp);
	
	output(data, n);

	
	fclose(fp);

	return 0;	
}

void output(double data[], int n){
	for(int i=0; i < n; i++){
		printf("%f ", data[i]);
		if((i + 1) % 5 == 0){
			puts("");
		}
	}

}
