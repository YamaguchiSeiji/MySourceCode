#include <stdio.h>
#include <stdlib.h>

void output(double [], int);

int main(){
	double data[100];
	int n;
	FILE *fp;
	
	if((fp = fopen("data_double_only", "rb")) == NULL){
		printf("cannot file open.");
		exit(1);
	}

	n = fread(data, sizeof(double), 100, fp);
	printf("data count = %d\n",n );	
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
